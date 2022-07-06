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

	tree = init_tree(tree);
	tree->parse = WITHOUT_PIPE;
	tree->infile = NULL;
	tree->outfile = NULL;
	n = n_token(tokens);
	tree->data = (char **)malloc(sizeof(char *) * (n + 1));
	i = 0;
	while (i < n)
	{
		if (check_ifredirection(tokens) != 1)
		{
			tree->data[i]->args = NULL;
			tree->data[i]->type = tokens->tokentype;
			tree->data[i]->path = NULL;
		}
		else
		{
			tree->data[i]->type = tokens->tokentype;
			if (tokens->tokentype == TOKEN_STRING)
			{
				tree->data[i]->args = tokens->data;
				tree->data[i]->path = NULL;
			}
			else if (tokens->tokentype == TOKEN_FILEPATH)
			{
				tree->data[i]->args = NULL;
				tree->data[i]->path = tokens->data;
			}
		}
		tokens = tokens->next;
		i++;
	}
	// while(tokens->)
	// print_simple_command(tree, tokens);
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
		tree->outfile = cmd_withoutpipe(tokens);
		tree->infile = parser(tokens);
		tree->data = NULL;
	}
	else
		tree = cmd_withoutpipe(tokens);
	return (0);
}
