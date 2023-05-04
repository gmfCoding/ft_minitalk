/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:33:48 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 16:56:28 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "common.h"

void print_byte(char byte)
{
	int	i;
	
	i = 7;
	while (i >= 0)
    	printf("%d", (byte >> i--) & 1);
	printf("\n");
}

static void	s_recv_byte(char byte)
{
	write(1, &byte, 1);
}

static void s_recv_low(int pid)
{
	recv_low(pid, s_recv_byte);
}

static void s_recv_high(int pid)
{
	recv_high(pid, s_recv_byte);
}

int	main(int argc, char **argv)
{
	int self;

	signal(BIT_LOW, s_recv_low);
	signal(BIT_HIGH, s_recv_high);
	self = getpid();
	printf("SERVER... %d@%d\n", self, BAUD_RATE);

	while (1)
	{
		usleep(100);
	}
	return (0);
}
