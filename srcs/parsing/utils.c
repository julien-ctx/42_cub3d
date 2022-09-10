/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:11 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/10 21:51:08 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	tab_size(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**dup_tab(char **tab)
{
	int		i;
	char	**new;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int	max_tab_len(char **tab)
{
	int	i;
	int	len;

	if (!tab)
		return (0);
	i = -1;
	while (tab[++i])
		if (ft_strlen(tab[i]) > len)
			len = ft_strlen(tab[i]);
	return (len);
}

char	**resize_tab(char **tab)
{
	char	**new;
	int		i;
	int		len;
	int		j;

	len = max_tab_len(tab);
	new = malloc(sizeof(char *) * (tab_size(tab) + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		j = -1;
		new[i] = malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		if (!new[i])
			return (NULL);
		while (tab[i][++j])
			new[i][j] = tab[i][j];
		new[i][j] = '\0';
		if (j < len)
			while (j++ < len)
				new[i] = ft_strjoin_char(new[i], ' ');
	}
	new[i] = NULL;
	return (new);
}
//has to be removed
void	print_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		printf("'%s'\n", tab[i]);
		i++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
