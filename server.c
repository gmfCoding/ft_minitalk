/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:33:48 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 13:36:55 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "common.h"

#include <stdio.h>

void	recv_byte(char byte)
{
	printf("%hhx\n", byte);
	//write(1, &byte, 1);
}

void	recv_bit(char bit)
{
	static char	data;
	static int	i;
	printf("%d\f", bit & 1);	
	data = data << 1;
	data = data | (bit & 1);
	i++;
	if (i <= 7)
		return ;
	recv_byte(data);
	i = 0;
	data = 0;
}

void	recv_low(int pid)
{
	recv_bit(0);
}

void	recv_high(int pid)
{
	recv_bit(1);
}

int	main(int argc, char **argv)
{
	int self;

	signal(BIT_LOW, recv_low);
	signal(BIT_HIGH, recv_high);
	self = getpid();
	printf("SERVER... %d\n", self);

	while (1)
	{
		sleep(1);
	}
	return (0);
}
