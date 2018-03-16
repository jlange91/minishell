/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:41:49 by jlange            #+#    #+#             */
/*   Updated: 2017/11/03 19:38:34 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		display_missing_quote(int opt)
{
	if (opt == -1)
		ft_putstr("dquote > ");
	else if (opt == -2)
		ft_putstr("quote > ");
	else if (opt == -3)
		ft_putstr("bquote > ");
	else if (opt == -4)
		ft_putstr(">");
}

static char		*ft_new_line(char *str)
{
	int		nb;
	char	*ret;
	int		i;

	nb = ft_strlen(str);
	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (nb + 2))))
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\n';
	ret[i + 1] = 0;
	return (ret);
}

static void		fill_new_line(t_shell *sh, char **line, int *opt)
{
	sh->line = ft_replace_str(ft_strjoin(sh->line, *line), sh->line);
	free(*line);
	*opt = 0;
	*line = ft_strdup(sh->line);
	free(sh->line);
}

void			ft_fill_line(t_shell *sh)
{
	int		ret;
	int		opt;
	char	*line;

	ret = 0;
	opt = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (opt == 1)
			fill_new_line(sh, &line, &opt);
		ret = ft_check_quote(line);
		if (ret == 0)
		{
			sh->line = ft_strdup(line);
			free(line);
			return ;
		}
		else
		{
			sh->line = ft_new_line(line);
			display_missing_quote(ret);
			free(line);
			opt = 1;
		}
	}
}
