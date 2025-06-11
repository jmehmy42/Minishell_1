/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:02:20 by thiago-camp       #+#    #+#             */
/*   Updated: 2025/06/11 12:20:09 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

void	init_func(t_files *file, char **envp, t_pipesort *piped, int argc)
{
	int			i;
	t_pipesort	*tmp;

	i = 0;
	tmp = piped;
	//file->paths = malloc(sizeof(char *) * 1);
	file->envp = envp;
	file->cmd_count = argc;
	file->cmds = malloc(sizeof(char **) * file->cmd_count);
	if (!file->cmds)
		return ;
	i = 0;
	while (i < file->cmd_count)
	{
		file->cmds[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
}

void	init_pipexinfo(t_pipexinfo *px, t_pipesort *piped)
{
	px->fd_in = -1;
	px->i = 0;
	px->pipe_counts = ft_lstsize_pipesort(piped);
}

void	inform_path_error(void)
{
	exit(1);
}

void	free_pipesort(t_pipesort *head)
{
	t_pipesort *tmp;

	while (head)
	{
		if(head->content)
			free_dptr(head->content, 0);
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	free_file(t_files *file)
{
	int i;
	int j;

	i = 0;
	while( i < file->cmd_count)
	{
		j = 0;
		while(file->cmds[i][j])
			free(file->cmds[i][j++]);
		free(file->cmds[i]);
		i++;
	}
	free(file->cmds);
}

