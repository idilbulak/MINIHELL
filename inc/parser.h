#ifndef PARSER_H
# define PARSER_H

typedef enum e_type
{
	TYPE_delimiter,
	TYPE_string
}	t_type;

typedef enum e_dataType
{
	DATA_doubleQuotedString,
    DATA_singleQuotedString,
    DATA_unquotedString
}	t_dataType;

typedef struct		s_data
{
	t_dataType	dataType;
	char		*data;
}	t_data;

typedef struct		s_delimiter
{
	t_data				*infile;
	struct t_ast		*outfile;
}	t_delimiter;

typedef struct		s_ast
{
	t_type				type;
	t_delimiter			*in_out_files;
}	t_ast;

t_ast	*parser(t_token *tokens);

#endif