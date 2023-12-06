/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:32:59 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/06 14:54:33 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../utils/gnl/get_next_line.h"
# include "../../utils/printf/ft_printf.h"

typedef struct s_raw_node
{
	char				*data;
	struct s_raw_node	*next;
}		t_raw_node;

typedef struct s_map
{
	char	**content;
	int		height;
	int		width;
}		t_map;




// MAP

t_map	*make_map(char *filePath);
void	*free_map(t_map *map);
int		map_validate(t_map *map);
int		map_count_of_char(t_map *map, char ch);

// NODE

t_raw_node	*make_node(char *data);
void		*free_node(t_raw_node *node);

// UTILS
int		parser_error(char *str);
int		ft_strlen(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(char *src);

#endif