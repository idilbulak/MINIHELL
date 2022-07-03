#ifndef PARSER_H
# define PARSER_H

typedef enum e_type
{
	TYPE_PIPE,
	TYPE_INSERTION,
	TYPE_EXTRACTION,
	TYPE_REDIRECTIN,
	TYPE_REDIRECTOUT,
	TYPE_COMMAND,
}	t_type;

typedef struct s_ast
{
	char				**data;
	struct t_ast		*outfile;
	struct t_ast		*infile;
	t_type				type;
}	t_ast;

// ast_utils
void	*print_simple_command(t_ast *tree, t_token *tokens);

t_ast	*parser(t_token *tokens);

#endif
