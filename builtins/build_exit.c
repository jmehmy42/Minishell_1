/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:57:29 by thguimar          #+#    #+#             */
/*   Updated: 2025/06/11 11:44:44 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	free_dptr(char **clc, int i)
{
	if (!clc)
		return ;
	while (clc[i])
	{
		free(clc[i]);
		clc[i] = NULL;
		i++;
	}
		free(clc);
}

void	ft_free(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
	}
}

void	final_cleaner(t_shell *utils)
{
	free_dptr(utils->builtins, 0);
	free_dptr(utils->exp, 0);
	free_dptr(utils->command, 0);
	free_dptr(utils->envr, 0);
	free(utils->export);
	free(utils->input);
	free(utils->echo_breed);
	free(utils->splitex);
	free(utils);
}

void	clear_little_things(char **argv, t_shell *utils)
{
	free_dptr(argv, 0);
	final_cleaner(utils);
	exit (0);
}

void	build_exit(char **argv, t_shell *utils)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
	if (!argv[1])
		clear_little_things(argv, utils);
	if (!argv[2])
	{
		while (ft_isdigit(argv[1][i]) == 1)
			i++;
		if (argv[1][i] != '\0')
		{
			free_dptr(argv, 0);
			exit (2);
		}
		else
		{
			status = ft_atoi(argv[1]);
			final_cleaner(utils);
			ft_putendl_fd("exit", 1);
			exit (status);
		}
	}
}
