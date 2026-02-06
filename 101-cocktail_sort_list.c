#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Cocktail Shaker 
 *                      sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *current;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = *list;
	end = NULL;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		current = start;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				listint_t *temp = current->next;
				current->next = temp->next;
				temp->prev = current->prev;

				if (current->prev)
					current->prev->next = temp;
				else
					*list = temp;

				if (temp->next)
					temp->next->prev = current;

				temp->next = current;
				current->prev = temp;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}
		end = current;

		if (!swapped)
			break;

		swapped = 0;
		current = end;
		while (current->prev != start->prev)
		{
			if (current->n < current->prev->n)
			{
				listint_t *temp = current->prev;
				current->prev = temp->prev;
				temp->next = current->next;

				if (temp->prev)
					temp->prev->next = current;
				else
					*list = current;

				if (current->next)
					current->next->prev = temp;

				current->next = temp;
				temp->prev = current;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}
		start = current;
	}
}
