/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:33:48 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 15:18:01 by clovell          ###   ########.fr       */
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

void	recv_byte(char byte)
{
	//print_byte(byte);
	printf("%c\n", byte);
	//write(1, &byte, 1);
}

void	recv_bit(char bit)
{
	static char	data;
	static int	i;
	data = data | ((bit & 1) << i);
	i++;
	if (i <= 7)
		return ;
	recv_byte(data);
	i = 0;
	data = 0;
}

void	recv_low(int pid)
{
	printf("0");
	recv_bit(0);
}

void	recv_high(int pid)
{
	printf("1");
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
		usleep(1);
	}
	return (0);
}
