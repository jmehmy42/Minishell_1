/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:06:36 by thguimar          #+#    #+#             */
/*   Updated: 2025/06/05 20:15:20 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include <stdio.h>

int	builtins(char *str, t_shell *utils, int i)
{
	static int	flag;

	if (flag == 0)
	{
		utils->builtins = ft_calloc(8, sizeof(char *));
		utils->builtins[0] = "echo";
		utils->builtins[1] = "cd";
		utils->builtins[2] = "pwd";
		utils->builtins[3] = "export";
		utils->builtins[4] = "unset";
		utils->builtins[5] = "env";
		utils->builtins[6] = "exit";
		flag = 1;
	}
	while (++i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(utils->builtins[i], str, \
				ft_strlen(utils->builtins[i])))
				return (i + 1);
		}
	}
	return (0);
}
