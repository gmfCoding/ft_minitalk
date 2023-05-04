/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:34:43 by clovell           #+#    #+#             */
/*   Updated: 2023/05/04 20:20:45 by clovell          ###   ########.fr       */
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

# define MSG_ACK 0x006
# define MSG_EOT 0x004


struct sigaction	setup_recv(void (*a)(int, siginfo_t, void *));
void				send_byte(int pid, char byte);
void				recv_bit(char bit, int pid, void (*on_byte)(char, int));
void				recv_low(int pid, void (*on_byte)(char, int));
void				recv_high(int pid, void (*on_byte)(char, int));

int					ft_atoi(const char *s);
void				ft_putstr(const char *str);

typedef void (*t_bytefunc)(char, int);
t_bytefunc	on_byte_func(t_bytefunc on_byte);

struct sigaction setup_recv(void (*a)(int, siginfo_t, void *));
/* EXAMPLE of a function to be passed for 'a'
static void	s_recv_bit(int sig, siginfo_t *info, void *context)
{
	if (pid == BIT_HIGH)
		recv_bit(1, info->si_pid, s_recv_byte);
	else if (pid == BIT_LOW)
		recv_bit(0, info->si_pid, s_recv_byte);
}*/


#endif
