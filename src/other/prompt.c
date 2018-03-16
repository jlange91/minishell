/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:46:19 by jlange            #+#    #+#             */
/*   Updated: 2017/11/03 18:48:48 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void		ft_time(void)
{
	time_t		time_sec;
	struct tm	now;

	time(&time_sec);
	now = *localtime(&time_sec);
	ft_putstr(" [");
	if (ft_intlen(now.tm_hour) == 1)
		write(1, "0", 1);
	ft_putnbr(now.tm_hour);
	ft_putchar(':');
	if (ft_intlen(now.tm_min) == 1)
		write(1, "0", 1);
	ft_putnbr(now.tm_min);
	ft_putchar(':');
	if (ft_intlen(now.tm_sec) == 1)
		write(1, "0", 1);
	ft_putnbr(now.tm_sec);
	ft_putstr("] ");
}

static inline void		ft_uid(void)
{
	struct passwd	*pw;
	uid_t			uid;
	char			host[2048];
	int				i;

	i = 0;
	gethostname(host, 2048);
	uid = geteuid();
	pw = getpwuid(uid);
	ft_putstr("\033[36;1m");
	ft_putstr(pw->pw_name);
	ft_putstr("\033[0m");
	write(1, "@", 1);
	ft_putstr("\033[34;1m");
	while (host[i] && host[i] != '.')
	{
		write(1, &host[i], 1);
		i++;
	}
	ft_putstr("\033[0m");
	write(1, ":", 1);
}

void					ft_display_prompt(t_shell sh, int status)
{
	ft_uid();
	ft_putstr("\033[32;1m");
	ft_putstr(sh.pwd);
	ft_putstr("\033[0;1m");
	ft_time();
	(status < 0) ? ft_putendl("😡") : ft_putendl("😇");
	ft_putstr("\033[32;1m");
	ft_putstr("$> ");
	ft_putstr("\033[0m");
}
