/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:26:30 by jlange            #+#    #+#             */
/*   Updated: 2017/11/03 18:37:44 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline int		ft_ret(t_shell *sh)
{
	int i;

	i = 0;
	if (sh->ac < 2)
	{
		ft_display_env(sh->env);
		return (1);
	}
	else if (sh->ac > 3)
	{
		ft_putstr_fd("setenv: Too many arguments.\n", 2);
		return (1);
	}
	while (sh->av[1][i])
	{
		if (!ft_isalnum(sh->av[1][i]))
		{
			ft_putstr_fd("setenv: Variable name must contain alphanumeric \
characters.\n", 2);
			return (1);
		}
		++i;
	}
	return (0);
}

static inline char		*create_line(char *name, char *value)
{
	char	*line;
	char	*tmp;

	line = ft_strjoin(name, "=");
	tmp = line;
	line = (value) ? ft_strjoin(tmp, value) : ft_strdup(line);
	free(tmp);
	return (line);
}

static inline char		**change_line(char *name, char *value, char **env)
{
	int		i;
	char	**new_env;
	char	*name2;

	i = 0;
	name2 = ft_strjoin(name, "=");
	if (!(new_env = (char**)malloc(sizeof(char*) * (tab_2d_len(env) + 1))))
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(name2, env[i], ft_strlen(name2)))
			new_env[i] = ft_strdup(env[i]);
		else
			new_env[i] = create_line(name, value);
		i++;
	}
	free(name2);
	new_env[i] = NULL;
	return (new_env);
}

char					**ft_setenv(char *name, char *value, char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	if ((ft_getenv(name, env)) != NULL)
		new_env = change_line(name, value, env);
	else
	{
		if (!(new_env = (char**)malloc(sizeof(char*) * (tab_2d_len(env) + 2))))
			return (NULL);
		while (env[i])
		{
			new_env[i] = ft_strdup(env[i]);
			i++;
		}
		new_env[i] = create_line(name, value);
		new_env[i + 1] = NULL;
	}
	return (new_env);
}

void					ft_prepare_setenv(t_shell *sh)
{
	char **new_env;

	if (ft_ret(sh))
		return ;
	new_env = ft_setenv(sh->av[1], sh->av[2], sh->env);
	free_tab_2d(sh->env);
	sh->env = new_env;
}
