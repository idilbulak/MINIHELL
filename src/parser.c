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

t_ast	*parser(t_token *tokens)
{
	t_ast	*tree;

	if (check_delimiter(tokens) == 42)
		printf("yes\n");
	else
		printf("no\n");



	printf("%d\n", tokens->tokenType);
	// printf("parser");
	print_tokens(tokens);


	return(0);
}