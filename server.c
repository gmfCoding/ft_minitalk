/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:33:48 by clovell           #+#    #+#             */
/*   Updated: 2023/05/08 19:22:49 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "common.h"
#include "libft.h"
#include "ft_printf.h"

static void	s_recv_byte(char byte, int pid)
{
	if (byte == MSG_EOT)
		send_byte(pid, MSG_ACK);
	else
		write(1, &byte, 1);
}

int	main(int argc, char **argv)
{
	on_byte_func(s_recv_byte);
	setup_recv(NULL);

	ft_printf("Message Server: %d\t BAUD:%d\n", getpid(), BAUD_RATE);
	while (1)
	{
		usleep(100);
	}
	return (0);
}
