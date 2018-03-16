/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:10:30 by jlange            #+#    #+#             */
/*   Updated: 2017/11/03 21:05:33 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <time.h>
# include <pwd.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>

typedef struct		s_shell
{
	char	*line;
	char	**av;
	int		ac;
	char	**env;
	char	*pwd;
}					t_shell;

void		ft_perror(char *str, int error, char *str2);

/********************************/
/*            quote             */
/********************************/

char		**ft_fill_av(char *line);
void		ft_fill(char *line, char **av);
int			ft_count_av1(char *line);
int			ft_count_av2(char *line, char **av);
int			ft_char_escape(char c);
int			ft_check_quote(char *line);

/********************************/
/*            builtins          */
/********************************/

void		ft_echo(char **av);
void		ft_cd(t_shell *sh);
void		ft_cd_l(t_shell *sh, char *path);
void		ft_cd_p(t_shell *sh, char *path);
void		ft_env(t_shell *sh);
int			env_skip_name_value(char **av, char ***env);
void		ft_prepare_setenv(t_shell *sh);
char		**ft_setenv(char *name, char *value, char **env);
void		ft_prepare_unsetenv(t_shell *sh);
char		**ft_unsetenv(char *name, char **env);
void		ft_pwd(t_shell *sh);
int			display_octal(char *str);
int			display_hexa(char *str);

/********************************/
/*            replace           */
/********************************/

void		ft_replace(t_shell *sh);
void		ft_replace_dollar(t_shell *sh, int save);
char		*ft_replace_line(char *str1, char *value, char *str2);

/********************************/
/*            exec              */
/********************************/

void		ft_exec(char **av, char **env);

/********************************/
/*            other             */
/********************************/

void		signal_sigint();
void		ft_display_env(char **env);
void		ft_chdir_error(char *path);
char		*ft_getenv(const char *name, char **env);
void		ft_fill_env(t_shell *sh, char **env);
char		**ft_replace_env(char **new_env, char **old_env);
char		*ft_remove_useless_path(char *str);
char		*ft_replace_str(char *new, char *old);
char		**ft_cp_env(char **env);
void		ft_display_prompt(t_shell sh, int status);
void		ft_charcat(char *str, char c);
void		ft_fill_line(t_shell *sh);
void		free_tab_2d(char **tab);
int			tab_2d_len(char **tab);

#endif
