#include "../inc/tokenizer.h"
#include "../inc/parser.h"
#include <stdio.h>

int	check_pipe(t_token *tokens)
{
	while (tokens->next != NULL)
	{
		if (tokens->tokenType == 1)
			return(42);
		tokens = tokens->next;
	}
	return (0);
}

int	check_greater(t_token *tokens)
{
	while (tokens->next != NULL)
	{
		if (tokens->tokenType == 2)
			return(42);
		tokens = tokens->next;
	}
	return (0);
}

int	check_less(t_token *tokens)
{
	while (tokens->next != NULL)
	{
		if (tokens->tokenType == 3)
			return(42);
		tokens = tokens->next;
	}
	return (0);
}

int	check_doublegreater(t_token *tokens)
{
	while (tokens->next != NULL)
	{
		if (tokens->tokenType == 4)
			return(42);
		tokens = tokens->next;
	}
	return (0);
}

int	check_doubleless(t_token *tokens)
{
	while (tokens->next != NULL)
	{
		if (tokens->tokenType == 5)
			return(42);
		tokens = tokens->next;
	}
	return (0);
}