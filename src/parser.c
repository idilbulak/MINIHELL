/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 10:24:53 by ibulak        #+#    #+#                 */
/*   Updated: 2022/07/06 15:01:49 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tokenizer.h"
#include "../inc/parser.h"
#include <stdio.h>

t_ast	*cmd_withoutpipe(t_token *tokens)
{
	t_ast	*tree;
	int		n;
	int		i;
	int		cmd_number;
	int		index;


	n = n_token(tokens);
	i = 0;
	while (i < n)
	{
		index = 0;
		while(tree->args != NULL)
		{
			index++;
		}
		if (tokens->tokentype == TOKEN_PIPE)
			break ;
		else if (check_ifredirection(tokens) == 1)
		{
			tree->args[index]->type = tokens->tokentype;
			tokens = tokens->next;
			tree->args[index]->data = tokens->data;
		}
		else if (tokens->tokentype == TOKEN_STRING)
		{
			tree->args[index]->type = tokens->tokentype;
			tree->args[index]->data = tokens->data;
		}
		tokens = tokens->next;
		i++;
	}
	return (tree);
}

t_ast	*parser(t_token *tokens)
{
	t_ast	*tree;

	if (check_pipe(tokens) == 42)
	{
		tree->parse = WITH_PIPE;
		tree->left = cmd_withoutpipe(tokens);
		while(tokens->data != NULL)
		{
			if (tokens->tokentype == TOKEN_PIPE)
			{
				tokens = tokens->next;
				break;
			}
			tokens = tokens->next;
		}
		tree->right = parser(tokens);
	}
	else
	{
		tree->parse = WITHOUT_PIPE;
		tree = cmd_withoutpipe(tokens);
	}

	// printf("data[%d] = %s\n", i, tree->args[i]);
	return (0);
}
