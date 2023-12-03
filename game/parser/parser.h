/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:32:59 by tmazitov          #+#    #+#             */
/*   Updated: 2023/11/25 18:25:36 by tmazitov         ###   ########.fr       */
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

char	**parse(char *filePath);
void	free_parse(char	**result);
int		count_of_char(char	**map, char ch);
#endif