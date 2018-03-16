/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:13:04 by jlange            #+#    #+#             */
/*   Updated: 2017/11/03 18:20:38 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_skip_useless(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			break ;
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
	}
	return (i);
}

int		ft_return(char c)
{
	if (c == '"')
		return (-1);
	else if (c == '\'')
		return (-2);
	else if (c == '`')
		return (-3);
	else
		return (0);
}
