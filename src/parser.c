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

	tree = init_tree(tree);
	tree->parse = WITHOUT_PIPE;
	n = n_token(tokens);
	cmd_number = n_command(tokens);
	tree->args = malloc(sizeof(char *) * (cmd_number + 1));
	i = 0;
	while (i < n)
	{
		if (tokens->tokentype == TOKEN_PIPE)
			break ;
		else if (check_ifredirection(tokens) == 1)
		{
			tree->args[i]->type = tokens->tokentype;
			tokens = tokens->next;
			tree->args[i]->data = tokens->data;
		}
		else if (tokens->tokentype == TOKEN_STRING)
		{
			tree->args[i]->type = tokens->tokentype;
			tree->args[i]->data = tokens->data;
		}
		tokens = tokens->next;
		i++;
	}
	return (tree);
}

t_ast	*parser(t_token *tokens)
{
	t_ast	*tree;
	int		n;

	if (check_pipe(tokens) == 42)
	{
		tree = init_tree(tree);
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
		// create pipe node
	}
	else
		tree = cmd_withoutpipe(tokens);

	printf("data[%d] = %s\n", i, tree->args[i]);
	return (0);
}
