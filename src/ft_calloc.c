/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:18:21 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 18:19:13 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	n;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	while (size > 0)
	{
		((char *)mem)[size] = 0;
	}	
	return (mem);
}
