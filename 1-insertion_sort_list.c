#include "sort.h"

/**
 * swap_nodes - Swaps a node with its previous node in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node: Pointer to the node to be swapped
 */

void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev = node->prev, *next = node->next;

	if (prev->prev)
	{
		prev->prev->next = node;
	}
	else
	{
		*list = node;
	}

	node->prev = prev->prev;
	node->next = prev;
	prev->prev = node;
	prev->next = next;

	if (next)
	{
		next->prev = prev;
	}
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                        in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *ins;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	cur = (*list)->next;

	while (cur)
	{
		ins = cur;
		cur = cur->next;

		while (ins->prev && ins->n < ins->prev->n)
		{
			swap_nodes(list, ins);
			print_list(*list);
		}
	}
}
