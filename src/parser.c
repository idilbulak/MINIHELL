#include "../inc/tokenizer.h"
#include "../inc/parser.h"
#include <stdio.h>

int	check_delimiter(t_token *tokens)
{
	while (tokens->next != NULL)
	{
		if (tokens->tokenType == 1)
			return(42);
		tokens = tokens->next;
	}
	return (0);
}

t_ast	*init_tree(t_ast *tree)
{
	tree = malloc(sizeof(t_ast));
	if (!tree)
		exit(EXIT_FAILURE);
	return(tree);
}

t_ast	*simple_command(t_token *tokens)
{
	t_ast	*tree;
	int		n;
	int		i;

	tree = init_tree(tree);
	n = n_token(tokens);
	tree->data = (char **)malloc(sizeof(char*)*(n + 1));
	tokens = tokens->next;
	tree->type = TYPE_COMMAND;
	tree->data[0] = tokens->data;
	i = 1;
	while(i <= n)
	{
		tree->data[i] = tokens->next->data;
		tokens = tokens->next;
		i++;
	}
	while (tokens->prev != NULL)
		tokens = tokens->prev;
	print_simple_command(tree, tokens);
	return(tree);
}

t_ast	*multiple_commands(t_token *tokens)
{
	t_ast	*tree;

	tree = init_tree(tree);
	printf("not done yet!\n");
	
}

t_ast	*parser(t_token *tokens)
{
	t_ast	*tree;
	int n;

	if (check_delimiter(tokens) == 42)
		tree = multiple_commands(tokens);
	else
		tree = simple_command(tokens);
		



	// printf("n = %d\n", n);
	// printf("parser");
	// print_tokens(tokens);


	return(0);
}