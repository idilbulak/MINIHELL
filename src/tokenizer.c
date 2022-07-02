#include "../inc/tokenizer.h"

ParserState	ifEndOfData(char *str, ParserState parserState)
{
	if (*str == '\0')
		parserState = STATE_EndOfData;
	return (parserState);
}

char	*findStartOfData(char *str, ParserState parserState)
{
	while (*str == '\n' || *str == '\r')
	{
		parserState = STATE_FindStartOfData;
		str++;
	}
	return (str);
}

char	*findStartOfToken(char *str, ParserState parserState)
{
	while (*str == ' ' || *str == '\t')
	{
		parserState = STATE_FindStartOfToken;
		str++;
	}
	return (str);
}

char	*findTypeOfToken(char *str, t_token *new_token, ParserState parserState)
{
	if (*str == '|' || *str == '>' || *str == '<')
	{
		parserState = STATE_FindDelimiter;
		str = find_delimiter(str, new_token, parserState);
	}
	else
	{
		if (*str == '"' || *str == '\'')
		{
			str++;
			parserState = STATE_ParseQuotedString;
			str = parse_quotedString(str, new_token, parserState);
		}
		else if (*str != '\0')
		{
			parserState = STATE_ParseUnquotedString;
			str = parse_unquotedString(str, new_token, parserState);
		}
	}
	return (str);
}

t_token	*tokenizer(char *str, t_token *tokens)
{
	t_token		*new_token;
	ParserState	parserState;

	parserState = STATE_FindStartOfData;
	tokens = init_tokens(tokens, parserState);
	while (parserState != STATE_ParseError && parserState != STATE_EndOfData)
	{
		// printf("str:%s\n", str);
		parserState = ifEndOfData(str, parserState);
		str = findStartOfData(str, parserState);
		str = findStartOfToken(str, parserState);
		new_token = init_tokens(new_token, parserState);
		str = findTypeOfToken(str, new_token, parserState);
		if (tokens == NULL)
			tokens = addto_emptylist(tokens, new_token);
		else
			addto_end(tokens, new_token);
		str++;
	}
	return(tokens);
	// print_tokens(tokens);
}
