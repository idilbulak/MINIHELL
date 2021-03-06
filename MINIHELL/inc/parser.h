#ifndef PARSER_H
# define PARSER_H

#include "tokenizer.h"

typedef enum e_parse
{
	WITH_PIPE,
	WITHOUT_PIPE
}	t_parse;

typedef struct s_data
{
	char			*args;
	t_tokentype		type;
	char			*path;
}	t_data;

typedef struct s_ast
{
	t_data			**data;
	struct t_ast			*outfile;
	struct t_ast			*infile;
	t_parse			parse;
}	t_ast;

// ast_utils
void	*print_simple_command(t_ast *tree, t_token *tokens);
t_ast	*init_tree(t_ast *tree);

// parser checks
int	check_pipe(t_token *tokens);
int	check_greater(t_token *tokens);
int	check_less(t_token *tokens);
int	check_doublegreater(t_token *tokens);
int	check_doubleless(t_token *tokens);

// parser without pipe
t_ast	*simple_command(t_token *tokens);
t_ast	*parse_greater(t_token *tokens);
t_ast	*parse_less(t_token *tokens);
t_ast	*parse_doublegreater(t_token *tokens);
t_ast	*parse_doubleless(t_token *tokens);


t_ast	*parser(t_token *tokens);

#endif
