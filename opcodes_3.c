#include "monty.h"

/**
  * rotl - rotates stack to the top
  * @stack: pointer to the head node pointer of stack
  *
  * @nline: line number
  * Return: 0 on success
  */
void rotl(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	int i, j;
	(void)nline;

	if (stack == NULL || *stack == NULL)
	{
		nop(stack, nline);
	}

	i = (*stack)->n;
	temp = *stack;

	while (temp)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}

	j = temp->n;
	(*stack)->n = j;
	temp->n = i;
}

/**
  * rotlop - rotates stack to the left
  * @stack: pointer to the head node pointer of stack
  *
  * @nline: line number
  * Return: 0 on success
  */
void rotlop(stack_t **stack, unsigned int nline)
{
	stack_t *temp, *last;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;
	last = temp;

	while (last->next)
	{
		last = last->next;
	}

	last->next = temp;
	temp->prev = last;
	temp->next->prev = NULL;
	*stack = temp->next;
	temp->next = NULL;
}


/**
  * rotrop - rotates stack to the right.
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  *
  * Return: 0 on success
  */
void rotrop(stack_t **stack, unsigned int nline)
{
	stack_t *temp, *last;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;
	last = temp;

	while (last->next)
	{
		last = last->next;
	}

	last->prev->next = NULL;
	last->prev = NULL;
	temp->prev = last;
	last->next = temp;
	*stack = last;
}


/**
  * qpush - pushes to queue instead of stack
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  *
  * Return: NAIN
  */
void qpush(stack_t **stack, unsigned int nline)
{
	stack_t *new, *last;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	last = NULL;
	if (*stack)
	{
		last  = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
