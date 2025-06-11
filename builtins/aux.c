/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:56:34 by thguimar          #+#    #+#             */
/*   Updated: 2025/06/11 12:06:10 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	ft_free_pid(char **pid)
{
	int	i;

	i = 0;
	if (*pid == NULL)
		return ;
	while (pid[i])
	{
		free(pid[i]);
		pid[i] = NULL;
		i++;
	}
	free(pid);
}

char	*ft_getpid(void)
{
	char		*pid;
	int			fd;
	char		**temp;

	fd = open("/proc/self/stat", O_RDONLY);
	if (!fd)
		return (NULL);
	pid = get_next_line(fd);
	if (!pid)
		return (NULL);
	temp = ft_split(pid, ' ');
	free(pid);
	if (!temp)
		return (NULL);
	pid = ft_strdup(temp[0]);
	ft_free_pid(temp);
	if (!pid)
		return (NULL);
	return (pid);
}

char	*ft_strrstr(const char *haystack, const char *needle)
{
	char	*last_occurrence;
	size_t	needle_len;

	last_occurrence = NULL;
	if (!haystack || !needle)
		return (NULL);
	needle_len = ft_strlen(needle);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			last_occurrence = (char *)haystack;
		haystack++;
	}
	return (last_occurrence);
}

char	*trim_start(char *str)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	j = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	trimmed = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!trimmed)
		return (NULL);
	while (str[i])
	{
		trimmed[j] = str[i];
		i++;
		j++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;

	i = -1;
	j = -1;
	if (s1 != NULL && s2 != NULL)
		final = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 2);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	while (s1[++i] != '\0')
		final[i] = s1[i];
	final[i] = ' ';
	i++;
	while (s2[++j] != '\0')
		final[i++] = s2[j];
	final[i] = '\0';
	return (final);
}
