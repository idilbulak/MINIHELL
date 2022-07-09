/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ast_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 12:29:45 by ibulak        #+#    #+#                 */
/*   Updated: 2022/07/06 12:32:52 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tokenizer.h"
#include "../inc/parser.h"
#include <stdio.h>

t_ast	*init_tree(t_ast *tree)
{
	tree = malloc(sizeof(t_ast));
	if (!tree)
		exit(EXIT_FAILURE);
	return (tree);
}

// void	*print_simple_command(t_ast *tree, t_token *tokens)
// {
// 	int	i;

// 	i = 0;
// 	while (tree->parse != NULL)
// 	{
// 		if (data->args != NULL)
// 			printf("args[%d]: %s\n", i, tree->data[i]->args);
// 		if (data->path != NULL)
// 			printf("path[%d]: %s\n", i, tree->data[i]->path);
// 		i++;
// 	}
// }
