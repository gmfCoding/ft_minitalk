/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:33:48 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 20:19:41 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "common.h"
#include "libft.h"

//#include <stdio.h>
// void print_byte(char byte)
// {
// 	int	i;
	
// 	i = 7;
// 	while (i >= 0)
// 		printf("%d", (byte >> i--) & 1);
// 	printf("\n");
// }

static void	s_recv_byte(char byte, int pid)
{
	static char	insert[] = {0, 0};
	static char *message;
	char		*old;

	insert[0] = byte;
	if (message == NULL)
		message = ft_strdup("");
	if (byte == MSG_EOT)
		send_byte(pid, MSG_ACK);
	else
	{
		old = message;
		message = ft_strjoin(old, insert);
		free(old);
	}
}

int	main(int argc, char **argv)
{
	on_byte_func(s_recv_byte);
	setup_recv(NULL);

	ft_putstr("Message Server: ");
	ft_putnbr_fd(getpid(), 1);
	ft_putstr("\t BAUD:");
	ft_putnbr_fd(BAUD_RATE, 1);
	ft_putstr("\n");
	while (1)
	{
		usleep(100);
	}
	return (0);
}
