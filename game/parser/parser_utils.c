/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:02:27 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/10 21:22:56 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_strlen(const char *str)
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

static int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	counter;
	int		result;

	counter = 0;
	result = 0;
	while ((str1[counter] || str2[counter]) && counter < num)
	{
		if (str1[counter] != str2[counter])
		{
			result = (unsigned char)str1[counter]
				- (unsigned char)str2[counter];
			return (result);
		}
		counter++;
	}
	if (num != counter)
		result = (unsigned char)str1[counter] - (unsigned char)str2[counter];
	return (result);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter;
	int		substr_is_same;
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	counter = 0;
	substr_is_same = 0;
	while (big[counter] && counter < len)
	{
		if (big[counter] == little[0])
		{
			substr_is_same = ft_strncmp(&big[counter], little, little_len);
			if (substr_is_same == 0 && counter + little_len <= len)
				return (&((char *)big)[counter]);
		}
		counter++;
	}
	return (0);
}

int	map_count_of_char(t_map *map, char ch)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (map->content[y][x] == ch)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
