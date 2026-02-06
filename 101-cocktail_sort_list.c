#include "sort.h"

/**
 * _swap - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @l: Left node (must come immediately before @r)
 * @r: Right node (must come immediately after @l)
 */
void _swap(listint_t **list, listint_t *l, listint_t *r)
{
	if (!list || !*list || !l || !r || l->next != r)
	{
		return;
	}

	l->next = r->next;
	if (r->next)
	{
		r->next->prev = l;
	}

	r->prev = l->prev;
	if (l->prev)
	{
		l->prev->next = r;
	}
	else
	{
		*list = r;
	}

	r->next = l;
	l->prev = r;
}

/**
 * fwd - Performs the forward pass of cocktail sort
 * @list: Double pointer to the head of the list
 * @lb: Left bound (exclusive)
 * @rb: Right bound (exclusive)
 * Return: 1 if swapped happened, 0 otherwise
 */
static int fwd(listint_t **list, listint_t *lb, listint_t **rb)
{
	listint_t *c;
	int s = 0;

	c = (lb) ? lb : *list;
	while (c->next != *rb)
	{
		if (c->n > c->next->n)
		{
			_swap(list, c, c->next);
			s = 1;
			print_list(*list);
		}
		else
		{
			c = c->next;
		}
	}
	*rb = c;
	return (s);
}

/**
 * bwd - Performs the backward pass of cocktail sort
 * @list: Double pointer to the head of the list
 * @lb: Left bound (exclusive)
 * @rb: Right bound (exclusive)
 * Return: New left bound after the pass
 */
static listint_t *bwd(listint_t **list, listint_t *lb, listint_t *rb)
{
	listint_t *c;

	c = rb;
	while (c->prev != lb)
	{
		if (c->n < c->prev->n)
		{
			_swap(list, c->prev, c);
			print_list(*list);
		}
		else
		{
			c = c->prev;
		}
	}
	return (c);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail Shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *lb, *rb;
	int s;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	lb = NULL;
	rb = NULL;

	while (1)
	{
		s = fwd(list, lb, &rb);
		if (!s)
		{
			break;
		}
		lb = bwd(list, lb, rb);
	}
}
