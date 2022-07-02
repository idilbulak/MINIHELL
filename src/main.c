#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../inc/tokenizer.h"
#include "../inc/parser.h"

int	main(void)
{
	char	*str;
	t_token	*tokens;
	t_ast	*tree;

	while (1)
	{
		str = readline("MINIHELL> ");
		if (!str)
			exit(EXIT_FAILURE);
		add_history(str);
		tokens = tokenizer(str, tokens);
		// print_tokens(tokens);
		tree = parser(tokens);
		free(str);
		free(tokens);
		// str = NULL;
	}
}

// gcc -lreadline main.c
// HISTORY_STATE *myhist = history_get_history_state ();