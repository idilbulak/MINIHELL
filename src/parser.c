#include "../inc/tokenizer.h"
#include "../inc/parser.h"
#include <stdio.h>

t_ast	*cmd_withoutpipe(t_token *tokens)
{
	t_ast	*tree;
	int		n;
	int		i;

	tree = init_tree(tree);
	// n = n_token_withoutredirection(tokens);
	// i = 0;
	// while(i < n_token(tokens))
	// {
	// 	if (check_ifredirection(tokens))
	// 		break;
	// 	tree->args->data = (char **)malloc(sizeof(char*)*(n + 1));
	// 	tree->data[i] = tokens->next->data;
	// 	tokens = tokens->next;
	// 	i++;
	// }
	// while (tokens->prev != NULL)
	// 	tokens = tokens->prev;
	// print_simple_command(tree, tokens);
	return(tree);
}

t_ast	*parser(t_token *tokens)
{
	t_ast	*tree;
	int n;

	if (check_pipe(tokens) == 42)
	{
		tree = init_tree(tree);
		tree->type = WITH_PIPE;
		tree->infile = cmd_withoutpipe(tokens);
		tree->outfile = parser(tokens);
		tree->args = NULL;
	}
	else
		tree = cmd_withoutpipe(tokens);
	// print_tokens(tokens);


	return(0);
}