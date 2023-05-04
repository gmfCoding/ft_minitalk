/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:33:48 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 18:56:51 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "common.h"
#include "libft.h"

//#include <stdio.h>
//void print_byte(char byte)
//{
//	int	i;
//	
//	i = 7;
//	while (i >= 0)
//		printf("%d", (byte >> i--) & 1);
//	printf("\n");
//}

static void	s_recv_byte(char byte, int pid)
{
	if (byte == MSG_EOT)
	{
		send_byte(MSG_ACK, pid);
		ft_putstr("Sending Acl: ");
		ft_putnbr_fd(getppid(), 1);
		ft_putstr("\n");
		ft_putstr("Sending Ack; ");
		ft_putnbr_fd(getpid(), 1);
		ft_putstr("\n");
		ft_putstr("Sending Ack; ");
		ft_putnbr_fd(pid, 1);
		ft_putstr("\n");
	}
	else
		write(1, &byte, 1);
}

static void	s_recv_low(int pid)
{
	recv_low(pid, s_recv_byte);
}

static void	s_recv_high(int pid)
{
	recv_high(pid, s_recv_byte);
}

int	main(int argc, char **argv)
{
	int	self;

	signal(BIT_LOW, s_recv_low);
	signal(BIT_HIGH, s_recv_high);
	self = getpid();
	ft_putstr("Message Server: ");
	ft_putnbr_fd(self, 1);
	ft_putstr("\t BAUD:");
	ft_putnbr_fd(BAUD_RATE, 1);
	ft_putstr("\n");
	while (1)
	{
		usleep(100);
	}
	return (0);
}
