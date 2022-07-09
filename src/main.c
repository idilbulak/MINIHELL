/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 10:25:01 by ibulak        #+#    #+#                 */
/*   Updated: 2022/07/06 15:01:29 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	int		j;

	while (1)
	{
		j = 0;
		str = readline("MINIHELL> ");
		if (!str)
			exit(EXIT_FAILURE);
		add_history(str);
		tokens = tokenizer(str, tokens);
		printf("before\n");
		print_tokens(tokens);
		printf("after pipe\n");
		int	n = n_token(tokens);
		tree = init_tree(tree); //bunu da disari almalisin 
		tree->args = malloc(sizeof(t_args) * (n + 1));  //n hesaplamalisiiiin pipelar disinda tokenlar
		tree = parser(tokens);
		// print_tree(tree);
		free(str);
		free(tokens);
		free(tree);
		// str = NULL;
	}
}

// gcc -lreadline main.c
// HISTORY_STATE *myhist = history_get_history_state ();