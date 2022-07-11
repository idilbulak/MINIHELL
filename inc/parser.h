#ifndef PARSER_H
# define PARSER_H

#include "tokenizer.h"

// typedef enum e_parse
// {
// 	WITH_PIPE,
// 	WITHOUT_PIPE
// }	t_parse;

typedef struct s_args
{
	char			**data;
	t_tokentype		type;
}	t_args;

typedef struct s_ast
{
	t_args			**args;
	int				cmd_number;
}	t_ast;

typedef struct	s_filed
{
	int		tmpin;
	int		tmpout;
    int     redirect_out;
	int		in;
	int		out;
}	t_filed;

// parser
int		calculate_n_args(t_token *tokens);
int		calculate_index_token(t_token *tokens, char *token);
int		calculate_n_str(t_token *tokens);
char	**split_token(t_token *tokens);
int	calculate_n_cmd(t_token *tokens);
t_ast	*parser(t_token *tokens);

// ast utils
t_ast	*init_tree(t_ast *tree, t_token *tokens);
void	print_tree(t_ast *tree, t_token *tokens);

//checks
int	if_pipe(t_token *tokens);
int	check_pipe(t_token *tokens);
int	check_redirection(t_token *tokens);
int	parser_checks(t_token *tokens);


void	executor(t_ast *ast);
#endif
