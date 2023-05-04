/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:33:03 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 17:04:54 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "common.h"

int	main(int argc, char **argv)
{
	char	*str;
	int pid;

	if (argc < 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_byte(pid, *str);
		str++;
	}
	
	return (0);
}
