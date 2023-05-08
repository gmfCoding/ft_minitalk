/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:33:03 by clovell           #+#    #+#             */
/*   Updated: 2023/05/08 19:34:47 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "common.h"

static int	acknowledged(int ack)
{
	static int	info;

	if (ack)
		info = 1;
	return (info);
}

static void	c_recv_byte(char byte, int pid)
{
	if (byte == MSG_ACK)
	{
		ft_printf("Message Sent Successfully!\n");
		acknowledged(1);
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc < 3)
		return (-1);
	on_byte_func(c_recv_byte);
	setup_recv(NULL);
	ft_printf("Message Client: %d\t BAUD:%d\n", getpid(), BAUD_RATE);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_byte(pid, *str);
		str++;
	}
	send_byte(pid, MSG_EOT);
	while (!acknowledged(0))
		usleep(100);
	return (0);
}
