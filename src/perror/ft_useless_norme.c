/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useless_norme.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:06:04 by jlange            #+#    #+#             */
/*   Updated: 2017/11/03 18:08:15 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_useless_norme(void)
{
	char *str;

	str = "Input/output error. Some physical input or output error occurred.";
	return (ft_strdup(str));
}
