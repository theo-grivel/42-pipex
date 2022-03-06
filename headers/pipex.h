/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <tggrivel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:41:51 by tgrivel           #+#    #+#             */
/*   Updated: 2022/03/06 12:05:32 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

	//	Include

# include	<fcntl.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<sys/types.h>
# include	<sys/wait.h>

//	Define

# define	STDIN	0
# define	STDOUT	1
# define	STDERR	2

	//	Structur

typedef struct s_file {
	char	*path;
	int		fd;
}	t_file;

typedef struct s_cmd {
	char	*cmd;
	char	**arg;
}	t_cmd;

typedef struct s_info {
	t_file	inf;
	t_file	ouf;
	t_cmd	cmd1;
	t_cmd	cmd2;
	char	**path;
}	t_info;

/*	inf ~ input file
 *	ouf ~ output file
 *	cmd ~ commande
 *	arg ~ arguments of the commande
 *	path
 *		all path of binaries
 * 
 */

	//	pp_brexit.c

// free info struct and exit the program with exit value
void	pp_brexit(t_info *info, int exitValue);

	//	pp_parse.c

int		pp_parse(t_info *info, char **argv, char **env);

	//	pp_split.c

char	**pp_split(char *str, char c);
char	*pp_strcpy(char *str, int s, int e);
int		pp_strlen(char *str);

	//	pp_pipex.c

int		pp_pipex(t_info *info, char **env);

	//	pp_error.c

void	pp_errmsg(char *str, ...);

#endif /* PIPEX_H */
