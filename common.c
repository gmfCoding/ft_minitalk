/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:29 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 15:22:11 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include "common.h"
#include <unistd.h>

void	send_byte(int pid, char byte)
{
	const int	mode[] = {BIT_LOW, BIT_HIGH};
	int			i;
	i = 0;
	while (i < 8)
	{
		kill(pid, mode[byte >> i++ & 1]);
		usleep(10);
	}
}

int	ft_itoa(char *str)
{
	int mult;
	unsigned int accum;

	accum = 0;
	mult = 1;
	while (*str > 9 && *str < 14)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			mult = -1;
	while (*str >= '0' && *str <= '9')
	{	
	    accum = (accum * 10) + (*str - '0');
        str++;
	}
	return (accum * mult);
}
