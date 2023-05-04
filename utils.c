/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:00:01 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 17:14:23 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(const char *s)
{
	int				mult;
	unsigned int	accum;
	char			*str;

	str = (char *)s;
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

void	ft_putstr(const char *str)
{
	while (str && *str)
		write(1, str++, 1);
}
