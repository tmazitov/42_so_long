/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:32:54 by tmazitov          #+#    #+#             */
/*   Updated: 2023/10/08 22:36:29 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_strlen(char *str)
{
	int	counter;
	
	if (!str)
		return (0);
	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_strdup(char *src)
{
	size_t	src_len;
	int		counter;
	char	*new_str;

	src_len = ft_strlen(src);
	counter = 0;
	new_str = malloc(sizeof(char) * (src_len + 1));
	if (!new_str)
		return (0);
	while (src[counter])
	{
		new_str[counter] = src[counter];
		counter++;
	}
	new_str[counter] = '\0';
	return (new_str);
}


t_raw_node	*make_node(char *data)
{
	t_raw_node	*raw_node;

	if (!data)
		return (NULL);
	raw_node = malloc(sizeof(t_raw_node));
	if (!raw_node)
		return (NULL);
	raw_node->data = data;
	raw_node->next = NULL;
	return (raw_node);
}

void	free_node(t_raw_node *node)
{
	if (node->next)
		free_node(node->next);
	if (node->data)
		free(node->data);
	free(node);
}

void	free_parse(char	**result)
{
	int	counter;

	counter = 0;
	while(result[counter])
		free(result[counter++]);
	free(result);
}

int	count_of_trees(char	**map)
{
	int	x;
	int	y;
	int count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

char	**parse(char *filePath)
{
	t_raw_node	*init;
	t_raw_node	*raw;
	int			fd;
	int			row_count;
	char		**result;

	fd = open(filePath, O_RDONLY);
	if (fd == -1)
		return (NULL);
	init = make_node(get_next_line(fd));
	if (!init)
		return (close(fd), NULL);
	raw = init;
	row_count = 0;
	while (raw)
	{
		if (ft_strchr(raw->data, '\n'))
			raw->data[ft_strlen(raw->data) - 1] = '\0';
		if (ft_strlen(init->data) != ft_strlen(raw->data))
			return (close(fd), free_node(init), NULL);
		raw->next = make_node(get_next_line(fd));
		raw = raw->next;
		row_count++;
	}
	close(fd);
	result = malloc(sizeof(char*) * (row_count + 1));
	if (!result)
		return (free_node(init), NULL);
	raw = init;
	row_count = 0;
	while(raw)
	{
		result[row_count] = ft_strdup(raw->data);
		printf("%d) dup : %s\n",row_count, result[row_count]);
		if (!result[row_count])
			return (free_parse(result), NULL);
		row_count++;
		raw = raw->next;
	}
	
	printf("raw row: %d\n", row_count);
	result[row_count] = NULL;
	row_count = 0;
	while (result[row_count])
	{
		printf("%d)dup1: %s\n",row_count, result[row_count]);
		row_count++;
	}
	free_node(init);
	return (result);
}