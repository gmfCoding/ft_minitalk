/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:32:49 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 17:47:18 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *s);
void	ft_putstr(const char *str);
#endif
