/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:45:26 by dgarizad          #+#    #+#             */
/*   Updated: 2023/04/06 19:19:42 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "./libft/libft.h"

typedef struct s_glist
{
	int				count;
	char			str;
}	t_glist;

t_glist				g_vars;

//CHECK POINT!!! //CHECK CHEK POINT!!
/**
 * @brief Rebuilds each characer bit by bit from LSB to MSB.
 * str |= 1 << i; sets the current i bit of str to 1. 
 * for example if i is 4, and str is 00000101 the operation is:
 * 00000101 | 1 << 4 (means this : 00010000) so: result is 00010101.
 * @param signal 
 */
void	ft_sa_handler(int signal)
{
	if (signal == SIGUSR1)
		g_vars.str |= 1 << (g_vars.count);
	(g_vars.count)++;
	if (g_vars.count == 8)
	{
		ft_putchar_fd(g_vars.str, 1);
		g_vars.count = 0;
		g_vars.str = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	g_vars.count = 0;
	g_vars.str = 0;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = ft_sa_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit (1);
	while (1)
	{		
	}
	return (0);
}
