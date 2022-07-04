#include "../inc/tokenizer.h"
#include <stdio.h>

t_token	*init_tokens(t_token *tokens, ParserState parserState)
{
	tokens = malloc(sizeof(t_token));
	if (!tokens)
		parserState = STATE_ParseError;
	tokens->next = NULL;
	tokens->data = NULL;
	tokens->prev = NULL;
	tokens->tokenType = TOKEN_null;
	return(tokens);
}

t_token	*addto_emptylist(t_token *head, t_token *new)
{
	head->data = new->data;
	head->tokenType = new->tokenType;
	return (head);
}

t_token	*addto_end(t_token *head, t_token *new)
{
	t_token	*temp_prev;
	t_token	*temp_next;

	temp_next = malloc(sizeof(t_token));
	temp_next->prev = NULL;
	temp_next->data = new->data;
	temp_next->tokenType =new->tokenType;
	temp_next->next = NULL;
	temp_prev = head;
	while (temp_prev->next != NULL)
		temp_prev = temp_prev->next;
	temp_prev->next = temp_next;
	temp_next->prev = temp_prev;
	return (head);
}

void	print_tokens(t_token *head)
{
	t_token	*current;
	int		i;

	current = head;
	i = 0;
	if (!head)
		return ;
	while (current != NULL )
	{
		printf("token[%d]: %s  type:%u", i, current -> data, current->tokenType);
		printf("\n");
		i++;
		current = current->next;
	}
	printf("\n");
	free(current);
}

int	n_token(t_token *tokens)
{
	int	n;

	n = 0;
	while (tokens->next != NULL)
	{
		tokens = tokens->next;
		n++;
	}
	return (n);
}

int	check_ifredirection(t_token *tokens)
{
	if (tokens->tokenType == 2 || tokens->tokenType == 3
			|| tokens->tokenType == 4 || tokens->tokenType == 5)
		return(1);
	return(0);
}

int	n_token_withoutredirection(t_token *tokens)
{
	int n;

	n = 0;
	while (tokens->next != NULL)
	{
		if (check_ifredirection(tokens) == 1)
			tokens = tokens->next;
		else
		{
			n++;
			tokens = tokens->next;
		}
	}
	return (n);
}