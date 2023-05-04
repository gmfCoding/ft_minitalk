/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:29 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 18:12:19 by clovell          ###   ########.fr       */
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

void	recv_low(int pid, void (*on_byte)(char, int))
{
	recv_bit(0, pid, on_byte);
}

void	recv_high(int pid, void (*on_byte)(char, int))
{
	recv_bit(1, pid, on_byte);
}
