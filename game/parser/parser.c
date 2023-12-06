/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:32:54 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/06 13:37:36 by tmazitov         ###   ########.fr       */
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
	result = malloc(sizeof(char*) * (length + 1));
	if (!result)
		return (free_parse(result), NULL);
	row_count = 0;
	while(raw_list && row_count < length)
	{
		result[row_count] = ft_strdup(raw_list->data);
		if (!result[row_count++])
			return (free_parse(result), NULL);
		raw_list = raw_list->next;
	}	
	result[row_count] = NULL;
	return (result);
}



char	**make_map(char *filePath)
{
	t_raw_node	*raw_list;
	int			row_count;
	char		**map;

	row_count = 0;
	raw_list = make_raw_list(filePath, &row_count);
	if (!raw_list || row_count == 0)
		return (parser_error("can not to read file"), NULL);
	map = convert_to_map(raw_list, row_count);
	free_node(raw_list);
	if (!map)
		return (parser_error("can not to create map"), NULL);
	if (map_validate(map) != 0)
		return (free_parse(map), NULL);
	return (map);
}



void	*free_map(char **map)
{
	int	counter;

	if (!map)
		return (NULL);
	counter = 0;
	while(map[counter])
		free(map[counter++]);
	free(map);
	return (NULL);
}