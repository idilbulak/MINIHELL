#include "../inc/tokenizer.h"
#include <stdio.h>

char	*parse_quotedString( char *str, t_token *new_token, ParserState parserState)
{
	char	*temp_str;
	int		len;

	temp_str = str;
	len = 0;
	while (*str != '"' && *str != '\'')
	{
		len++;
		str++;
	}
	if (*str == '"')
		new_token->tokenType = TOKEN_STRING;
	else if (*str == '\'')
		new_token->tokenType = TOKEN_STRING;
	new_token->data = ft_substr(temp_str, 0, len);
	return(str);
}

char	*parse_unquotedString(char *str, t_token *new_token, ParserState parserState)
{
	char	*temp_str;
	int		len;

	temp_str = str;
	len = 0;
	while (*str != ' ' && *str != '\0')
	{
		if (*str == '|' || *str == '>' || *str == '<')
			break;
		len++;
		str++;
	}
	new_token->tokenType = TOKEN_STRING;
	new_token->data = ft_substr(temp_str, 0, len);
	return(str);
}

char	*lessthan_helper(char *str, t_token *new_token)
{
	if (*str == '<' && *(str + 1) != '<')
	{
		new_token->tokenType = TOKEN_LESS;
		new_token->data = ft_substr(str, 0, 1);
	}
	else if (*str == '<' && *(str + 1) == '<')
	{
		new_token->tokenType = TOKEN_DOUBLELESS;
		new_token->data = ft_substr(str, 0, 2);
		str++;
	}
	return (str);
}

char	*greaterthan_helper(char *str, t_token *new_token)
{
	if (*str == '>' && *(str + 1) != '>')
	{
		new_token->tokenType = TOKEN_GREATER;
		
		new_token->data = ft_substr(str, 0, 2);
	}
	else if (*str == '>' && *(str + 1) == '>')
	{
		new_token->tokenType = TOKEN_DOUBLEGREATER;
		new_token->data = ft_substr(str, 0, 2);
		str++;
	}
	return (str);
}

char	*find_delimiter( char *str, t_token *new_token, ParserState parserState)
{
	if (*str == '|')
	{
		new_token->tokenType = TOKEN_PIPE;
		new_token->data = ft_substr(str, 0, 1);	
	}
	else if (*str == '<')
		str = lessthan_helper(str, new_token);

	else if (*str == '>')
	{
		str = greaterthan_helper(str, new_token);
	}
	return(str);
}