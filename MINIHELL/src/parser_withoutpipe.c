#include "../inc/tokenizer.h"
#include "../inc/parser.h"
#include <stdio.h>

// t_ast	*parse_greater(t_token *tokens)
// {
// 	t_ast	*tree;

// 	tree = init_tree(tree);
// 	if (tokens->tokentype == TOKEN_GREATER)
// 	{
// 		tree->data = NULL;
// 		tree->type = TOKEN_GREATER;
// 	}
// 	tokens = tokens->next;
// 	tree = simple_command(tokens);
// 	return (tree);
	
// }

// t_ast	*parse_less(t_token *tokens)
// {
// 	t_ast	*tree;

// 	tree = init_tree(tree);
// 	printf("less!\n");
// 	return (tree);
// }

// t_ast	*parse_doublegreater(t_token *tokens)
// {
// 	t_ast	*tree;

// 	tree = init_tree(tree);
// 	printf("double greater!\n");
// 	return (tree);
// }

// t_ast	*parse_doubleless(t_token *tokens)
// {
// 	t_ast	*tree;

// 	tree = init_tree(tree);
// 	printf("double less!\n");
// 	return (tree);
// }