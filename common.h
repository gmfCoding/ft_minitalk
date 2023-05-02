/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:34:43 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 13:14:55 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <signal.h>
# define BIT_LOW SIGUSR1
# define BIT_HIGH SIGUSR2

void	send_byte(int pid, char byte);
int	ft_itoa(char *str);
#endif
