/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:24:45 by tgrivel           #+#    #+#             */
/*   Updated: 2022/02/22 18:38:16 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	display_tab(char **tab, char *s)
{
	while (*tab)
	{
		printf("\t%s\t%s\n", s, *tab);
		tab++;
	}
}

void	test_parse(t_info *info)
{
	printf("infile\t: %s\n", info->inf);
	printf("cmd 1\t: %s\n", info->cmd1);
	printf("cmd 2\t: %s\n", info->cmd2);
	printf("outfile\t: %s\n", info->ouf);
	display_tab(info->path, "path");
}
 //	./pipex infile ``ls -l'' ``wc -l'' outfile

static void
	init_info(t_info *info, char **argv, char **env)
{
	info->inf = 0;
	info->ouf = 0;
	info->cmd1 = 0;
	info->cmd2 = 0;
	info->arg1 = 0;
	info->arg2 = 0;
	info->path = 0;
	pp_parse(info, argv, env);
}

void
	free_info(t_info *info)
{
	free(info->inf);
	free(info->ouf);
	free(info->cmd1);
}

int
	main(int argc, char **argv, char **env)
{
	t_info	info;

	if (argc != 5)
		printf("Error, bad number of arguments\n");
	if (argc != 5)
		return (0);
	init_info(&info, argv, env);
	test_parse(&info);
}
 //	./pipex infile ``ls -l'' ``wc -l'' outfile
