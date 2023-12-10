/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:32:54 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:22:19 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_raw_node	*make_raw_list(char *file_path, int *length)
{
	int			fd;
	t_raw_node	*raw;
	t_raw_node	*init;

	if (!file_path)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	init = make_node(get_next_line(fd));
	if (!init)
		return (close(fd), NULL);
	raw = init;
	while (raw)
	{
		if (ft_strchr(raw->data, '\n'))
			raw->data[ft_strlen(raw->data) - 1] = '\0';
		raw->next = make_node(get_next_line(fd));
		raw = raw->next;
		*length = *length + 1;
	}
	return (close(fd), init);
}

static char	**convert_to_map(t_raw_node *raw_list, int length)
{
	char	**result;
	int		row_count;

	if (!raw_list || length == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (length + 1));
	if (!result)
		return (NULL);
	row_count = 0;
	while (raw_list && row_count < length)
	{
		result[row_count] = ft_strdup(raw_list->data);
		if (!result[row_count++])
			return (NULL);
		raw_list = raw_list->next;
	}
	result[row_count] = NULL;
	return (result);
}

static void	init_map(t_map *map)
{
	map->content = NULL;
	map->height = 0;
	map->width = 0;
}

t_map	*make_map(char *file_path)
{
	t_raw_node	*raw_list;
	int			row_count;
	t_map		*map;

	if (!file_path)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map(map);
	row_count = 0;
	raw_list = make_raw_list(file_path, &row_count);
	if (!raw_list || row_count == 0)
		return (parser_error("can not to read file"), free_map(map));
	map->content = convert_to_map(raw_list, row_count);
	free_node(raw_list);
	if (!map->content)
		return (parser_error("can not to create map"), free_map(map));
	if (map_validate(map) != 0)
		return (free_map(map));
	map->width = ft_strlen(map->content[0]);
	map->height = row_count;
	return (map);
}

void	*free_map(t_map *map)
{
	int	counter;

	if (!map)
		return (NULL);
	counter = 0;
	if (map->content)
	{
		while (map->content[counter])
			free(map->content[counter++]);
		free(map->content);
	}
	free(map);
	return (NULL);
}
