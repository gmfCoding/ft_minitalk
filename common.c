/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:29 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 20:22:09 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include "common.h"
#include <unistd.h>

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

/* Returns the callback to be used by setup_recv, 
 * to set the function to be used call:
 * on_byte_func(&func);
 * */
t_bytefunc	on_byte_func(t_bytefunc on_byte)
{
	static t_bytefunc event;

	if (on_byte != NULL)
		event = on_byte;
	return event;
}

/* Sets up the receiver functions,
 * When a is NULL it uses the on_byte_func to find the target callback.
 * Otherwise it uses a as it's target callback.
 * SEE on_byte_func
 * */
struct sigaction setup_recv(void (*a)(int, struct __siginfo, void *))
{
	struct sigaction	sa;
    
    sa.sa_flags = SA_SIGINFO;
	if (a != NULL)
		sa.sa_sigaction = a;
	else
    	sa.sa_sigaction = on_byte_func(NULL);
    sigaction(BIT_LOW, &sa, NULL);
    sigaction(BIT_HIGH, &sa, NULL);
	return (sa);
}

/*void	recv_low(int pid, void (*on_byte)(char, int))
{
	recv_bit(0, pid, on_byte);
}

void	recv_high(int pid, void (*on_byte)(char, int))
{
	recv_bit(1, pid, on_byte);
}*/
