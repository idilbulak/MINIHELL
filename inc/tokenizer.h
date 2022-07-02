#ifndef TOKENIZER_H
# define TOKENIZER_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    STATE_FindStartOfData,
    STATE_FindStartOfToken,
    STATE_ParseQuotedString,
    STATE_ParseUnquotedString,
    STATE_ParseNumber,
    STATE_FindDelimiter,
    STATE_CheckEndOfString,
    STATE_ParseError,
    STATE_EndOfData
}	ParserState;

typedef enum e_tokentype
{
	TOKEN_null,
    TOKEN_delimiter,
    TOKEN_doubleQuotedString,
    TOKEN_singleQuotedString,
    TOKEN_unquotedString
}	t_tokentype;

typedef struct		s_token
{
	char				*data;
	t_tokentype			tokenType;
	struct s_token		*next;
	struct s_token		*prev;
}	t_token;

// tokenizer
ParserState	ifEndOfData(char *str, ParserState parserState);
char	    *findStartOfData(char *str, ParserState parserState);
char	    *findStartOfToken(char *str, ParserState parserState);
char	    *findTypeOfToken(char *str, t_token *new_token, ParserState parserState);
t_token	    *tokenizer(char *line, t_token *tokens);

// tokenlist_utils
t_token	    *init_tokens(t_token *tokens, ParserState parserState);
t_token	    *addto_emptylist(t_token *head, t_token *new);
t_token	    *addto_end(t_token *head, t_token *new);
void	    print_tokens(t_token *head);

// libft
int	        ft_isdigit(int c);
size_t	    ft_strlen(const char *s);
char	    *ft_substr(char const *s, unsigned int start, size_t len);

// tokenizer helper
char	    *parse_quotedString( char *str, t_token *new_token, ParserState parserState);
char	    *find_delimiter( char *str, t_token *new_token, ParserState parserState);
char	    *parse_unquotedString(char *str, t_token *new_token, ParserState parserState);

#endif