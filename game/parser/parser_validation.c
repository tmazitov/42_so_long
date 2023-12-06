/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:08:30 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/06 13:39:02 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	map_check_length(char **map)
{
	int	counter;

	counter = 0;
	while (map[counter])
	{
		if (ft_strlen(map[counter]) != ft_strlen(*map))
			return (1);
		counter++;
	}
	return (0);
}

static int	map_check_border_line(char *str)
{
	int	counter;	

	if (!str)
		return (NULL);
	counter = 0;
	while (str[counter])
	{
		if (str != '1')
			return (1); 
	}
	return (0);
}

static int	map_check_walls(char **map)
{
	int	x;
	int	y;
	int	height;

	height = 0;
	x = 0;
	y = 0;
	if (map_check_border_line(map[y++]) != 0)
		return (1);
	while (map[y])
	{
		if (map[y+1] == NULL)
			break;
		x = 0;
		if (map[y][x++] != '1')
			return (1);
		while (map[y][x])
			x++;
		if (map[y][x - 1] != '1')
			return (1);
		y++;
	}
	if (map_check_border_line(map[y++]) != 0)
		return (1);
	return (0);
}

int file_check(char *file_path)
{
	char	*resolution;

	resolution = ft_strnstr(file_path, ".ber", ft_strlen(file_path));
	return (resolution && ft_strlen(resolution) == 4);
}

int	map_validate(char **map)
{
	if (!map)
		return (1);
	if (map_count_of_char(map, 'C') == 0)
		return (parser_error("collectable count is 0"));
	if (map_count_of_char(map, 'P') != 1)
		return (parser_error("player start position is undefined"));
	if (map_count_of_char(map, 'E') != 1)
		return (parser_error("exit position is undefined"));
	if (map_check_length(map) != 0)
		return (parser_error("map is not rectangle"));
	if (map_check_walls(map) != 0)
		return (parser_error("map is not bordered by walls"));
	return (0);
}