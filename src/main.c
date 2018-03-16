/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:50:47 by jlange            #+#    #+#             */
/*   Updated: 2017/11/03 18:55:35 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			signal_sigint(int sign)
{
	sign = (int)sign;
	write(1, "\n", 1);
}

void			ft_cmd(t_shell *sh)
{
	if (!ft_strcmp(sh->av[0], "exit"))
	{
		ft_putstr("exit\n");
		exit(0);
	}
	else if (!ft_strcmp(sh->av[0], "echo"))
		ft_echo(sh->av);
	else if (!ft_strcmp(sh->av[0], "pwd"))
		ft_pwd(sh);
	else if (!ft_strcmp(sh->av[0], "setenv"))
		ft_prepare_setenv(sh);
	else if (!ft_strcmp(sh->av[0], "unsetenv"))
		ft_prepare_unsetenv(sh);
	else if (!ft_strcmp(sh->av[0], "env"))
		ft_env(sh);
	else if (!ft_strcmp(sh->av[0], "cd"))
		ft_cd(sh);
	else if (sh->av[0])
		ft_exec(sh->av, sh->env);
}

void			init_shell(t_shell *sh, char **env)
{
	ft_fill_env(sh, env);
	sh->line = NULL;
	sh->av = NULL;
	sh->ac = 0;
}

void			free_shell(t_shell *sh)
{
	if (sh->line)
	{
		free(sh->line);
		sh->line = NULL;
	}
	if (sh->av)
	{
		free_tab_2d(sh->av);
		sh->av = NULL;
	}
}

int				main(int ac, char **av, char **env)
{
	t_shell		sh;

	signal(SIGINT, signal_sigint);
	ac = (int)ac;
	av = (char**)av;
	env = (char**)env;
	init_shell(&sh, env);
	ft_display_prompt(sh, 0);
	while (42)
	{
		ft_fill_line(&sh);
		if (!sh.line)
			break ;
		ft_replace(&sh);
		sh.av = ft_fill_av(sh.line);
		sh.ac = tab_2d_len(sh.av);
		if (sh.av[0])
			ft_cmd(&sh);
		ft_display_prompt(sh, 1);
		free_shell(&sh);
	}
	free_tab_2d(sh.env);
	free(sh.pwd);
	ft_putendl("exit");
}
