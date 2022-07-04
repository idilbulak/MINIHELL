#include "../inc/tokenizer.h"
#include "../inc/parser.h"
#include <stdio.h>

t_ast	*init_tree(t_ast *tree)
{
	tree = malloc(sizeof(t_ast));
	if (!tree)
		exit(EXIT_FAILURE);
	return(tree);
}

void	*print_simple_command(t_ast *tree, t_token *tokens)
{
	int	i;

	i = 0;
	printf("type:[%d]\n", tree->type);
	while(i < n_token(tokens))
	{
		printf("data[%d]: %s\n", i, tree->data[i]);
		i++;
	}
}