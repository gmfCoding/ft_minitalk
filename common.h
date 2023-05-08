/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:34:43 by clovell           #+#    #+#             */
/*   Updated: 2023/05/08 19:24:16 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <signal.h>

# define BIT_LOW SIGUSR1
# define BIT_HIGH SIGUSR2

# ifndef BAUD_RATE
#  define BAUD_RATE 6600
# endif

# define MSG_ACK 0x006
# define MSG_EOT 0x004


void				send_byte(int pid, char byte);
void				recv_bit(char bit, int pid, void (*on_byte)(char, int));
void				recv_low(int pid, void (*on_byte)(char, int));
void				recv_high(int pid, void (*on_byte)(char, int));

typedef void (*t_bytefunc)(char, int);
t_bytefunc	on_byte_func(t_bytefunc on_byte);

struct sigaction setup_recv(void (*a)(int, siginfo_t *, void *));
#endif
