/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:57:29 by thguimar          #+#    #+#             */
/*   Updated: 2025/06/09 00:17:50 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	free_dptr(char **clc, int i)
{
	if (!clc)
		return ;
	if (clc)
	{
		while (clc[i])
		{
			free(clc[i]);
			clc[i] = NULL;
			i++;
		}
		if (clc)
			clc = NULL;
	}
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
	if (utils->builtins)
		free_dptr(utils->builtins, 0);
	if (utils->exp)
		free_dptr(utils->exp, 0);
	if (utils->command)
		free_dptr(utils->command, 0);
	if (utils->export)
		free(utils->export);
	if (utils->input)
		free(utils->input);
	if (utils)
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
