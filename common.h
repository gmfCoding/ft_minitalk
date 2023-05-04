/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:34:43 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 17:07:15 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <signal.h>
# define BIT_LOW SIGUSR1
# define BIT_HIGH SIGUSR2
# ifndef BAUD_RATE
#  define BAUD_RATE 20000
# endif

int		ft_atoi(const char *s);
void	send_byte(int pid, char byte);
void	recv_bit(char bit, void (*on_byte)(char));
void	recv_low(int pid, void (*on_byte)(char));
void	recv_high(int pid, void (*on_byte)(char));
#endif
