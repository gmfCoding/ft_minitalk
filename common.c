/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:29 by clovell           #+#    #+#             */
/*   Updated: 2023/05/08 20:32:11 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include "common.h"

void	send_byte(int pid, char byte)
{
	const int	mode[] = {BIT_LOW, BIT_HIGH};
	int			i;

	i = 0;
	while (i < 8)
	{
		kill(pid, mode[byte >> i++ & 1]);
		usleep(1000000 / BAUD_RATE);
	}
}

/* Will execute on_byte when 8 bits have been recieved/processed.
 * tmp exists so we can clear data before the on_byte is called so that...
 * if on_byte fails the data has been cleared and subsequent calls work. */
void	recv_bit(char bit, int pid, void (*on_byte)(char, int))
{
	static char	data;
	static int	i;
	char		tmp;

	data = data | ((bit & 1) << i);
	i++;
	if (i <= 7)
		return ;
	i = 0;
	tmp = data;
	data = 0;
	on_byte(tmp, pid);
}

/* Returns the callback to be used by the default implementation of...
 * d_recv_bit and once that gets 8 bits it calls the 'on_byte' function.
 * to set the function use:
 * on_byte_func(&func);
 * */
t_bytefunc	on_byte_func(t_bytefunc on_byte)
{
	static t_bytefunc	event;

	if (on_byte != NULL)
		event = on_byte;
	return (event);
}

/* Default implementation for recieve bits:
 * SEE on_byte_func
 */
static void	d_recv_bit(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == BIT_LOW)
		recv_bit(0, info->si_pid, on_byte_func(NULL));
	if (sig == BIT_HIGH)
		recv_bit(1, info->si_pid, on_byte_func(NULL));
}

/* Sets up the receiver functions,
 * When a is NULL it uses the d_recv_bit.
 * Otherwise it uses the supplied 'func' as the bit/sig callback callback.
 */
struct sigaction	setup_recv(void (*func)(int, siginfo_t *, void *))
{
	static struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	if (func != NULL)
		sa.sa_sigaction = func;
	else
		sa.sa_sigaction = d_recv_bit;
	sigaction(BIT_LOW, &sa, NULL);
	sigaction(BIT_HIGH, &sa, NULL);
	return (sa);
}
