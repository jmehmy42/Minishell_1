/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:13:54 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/04 20:25:28 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

char	*get_env_value(char *key, t_shell *utils)
{
	int		i;
	int		key_len;

	i = 0;
	key_len = ft_strlen3(key);
	while (utils->envr[i])
	{
		if (ft_strncmp(key, utils->envr[i], key_len) == 0
			&& key_len == ft_strlen3(utils->envr[i]))
		{
			return (ft_substr(utils->envr[i], key_len + 1,
					ft_strlen(utils->envr[i]) - key_len - 1));
		}
		i++;
	}
	return (NULL);
}

char	*expand_unfound_env(char *str, t_shell *utils)
{
	char	*before;
	char	*after;
	char	*middle;

	before = ft_substr(str, 0, utils->count_m - 1);
	after = ft_substr(str, utils->count_n, ft_strlen(str) - utils->count_n);
	free(str);
	middle = ft_strjoin(before, after);
	free_expansion(utils);
	return (middle);
}

char	*expand_found_env(char *str, char *val, t_shell *utils)
{
	char	*before;
	char	*after;
	char	*temp;
	char	*middle;
	int		j;

	before = NULL;
	if (utils->count_h != 0)
		before = ft_substr(str, 0, utils->count_h);
	j = utils->count_m;
	while (str[j])
		j++;
	after = ft_substr(str, utils->count_n, j - utils->count_n);
	temp = ft_strjoin(before, val);
	middle = ft_strjoin(temp, after);
	free(str);
	free_expansion(utils);
	return (middle);
}

char	*expand_env(char *str, t_shell *utils)
{
	char	*key;
	char	*val;

	key = ft_substr(str, utils->count_m, utils->count_n - utils->count_m);
	val = get_env_value(key, utils);
	free(key);
	if (val)
		return (expand_found_env(str, val, utils));
	else
		return (expand_unfound_env(str, utils));
}
