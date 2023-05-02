/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:33:03 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 15:20:05 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "common.h"

void print_byte(char byte)
{
	int	i;
	i = 7;
	while (i >= 0)
    	printf("%d", (byte >> i--) & 1);
	printf("\n");
}

int	main(int argc, char **argv)
{
	char	*str;
	int pid;

	if (argc < 3)
		return (-1);
	pid = ft_itoa(argv[1]);
	str = argv[2];
	while (*str)
	{
		print_byte(*str);

		send_byte(pid, *str);
		str++;
	}
	printf("CLIENT...\n");
	return (0);
}
