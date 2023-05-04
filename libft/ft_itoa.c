/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:20:49 by clovell           #+#    #+#             */
/*   Updated: 2023/03/10 18:42:56 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_itoa_rec(char* dst, int size, long long int n)
{
	if (n == 0 || size < 0)
		return ;
	ft_itoa_rec(dst, size - 1, n / 10);
	dst[size] = n % 10 + '0';
}

char *ft_itoa(int n)
{
	long long ni;
	int count;
	char	*str;

	ni = n;
	if (n < 0)
		ni = 0L - n;
	count = 1;
	ni /= 10;
	while (ni != 0)
	{
		ni /= 10;
		count++;	
	}
	str = ft_calloc(count + 1 + (n < 0), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	ni = n;
	if (n < 0)
		ni = 0L - n;
	ft_itoa_rec(str + (n < 0), count - 1, ni);
	if (n < 0)
		str[0] = '-';
	return (str);
}

#ifdef _MAIN_
void main()
{
	printf("%s", ft_itoa(0));
	printf("%s", ft_itoa(-2147483648));
	return;
}
#endif
