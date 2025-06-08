/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_frees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:28:14 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/04 20:34:52 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	free_expansion(t_shell *utils)
{
	if (utils->o_que_quiser)
		free(utils->o_que_quiser);
	if (utils->o_que_quiser2)
		free(utils->o_que_quiser2);
	if (utils->o_que_quiser3)
		free(utils->o_que_quiser3);
	if (utils->o_que_quiser4)
		free(utils->o_que_quiser4);
	if (utils->o_que_quiser5)
		free(utils->o_que_quiser4);
}
