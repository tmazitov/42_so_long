/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:32:59 by tmazitov          #+#    #+#             */
/*   Updated: 2023/12/06 13:37:57 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../utils/gnl/get_next_line.h"

typedef struct s_raw_node
{
	char				*data;
	struct s_raw_node	*next;
}		t_raw_node;

// NODE

t_raw_node	*make_node(char *data);
void		*free_node(t_raw_node *node);

// MAP

char	**make_map(char *filePath);
void	*free_map(char **result);
int		map_validate(char **map);
int		map_count_of_char(char **map, char ch);

// UTILS
int		parser_error(char *str);
int		ft_strlen(char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(char *src)

#endif