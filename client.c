/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:33:03 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 18:32:38 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "common.h"
static int acknowledged(int ack)
{
	static int info;
	if (ack)
		info = 1;
	return (info);
}

static void	c_recv_byte(char byte, int pid)
{
	printf("Got byte: %x, from:%d", byte, pid);
	if (byte == MSG_ACK)
	{
		ft_putstr("Message Sent Successfully!");
		acknowledged(1);
	}
}

static void	c_recv_low(int pid)
{
	recv_low(pid, c_recv_byte);
}

static void	c_recv_high(int pid)
{
	recv_high(pid, c_recv_byte);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc < 3)
		return (-1);
	signal(BIT_LOW, c_recv_low);
	signal(BIT_HIGH, c_recv_high);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_byte(pid, *str);
		str++;
	}
	send_byte(pid, MSG_EOT);
	ft_putstr("Send EOT");	
	while (!acknowledged(0))
	{
		usleep(1000);
	}
	return (0);
}
