#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * dk_v - Maps a card value string to its rank (Ace..King -> 0..12)
 * @v: Value string
 * Return: Rank index
 */
int dk_v(const char *v)
{
	if (!v)
	{
		return (0);
	}

	if (strcmp(v, "Ace") == 0)
	{
		return (0);
	}
	if (strcmp(v, "Jack") == 0)
	{
		return (10);
	}
	if (strcmp(v, "Queen") == 0)
	{
		return (11);
	}
	if (strcmp(v, "King") == 0)
	{
		return (12);
	}
	if (v[0] == '1' && v[1] == '0' && v[2] == '\0')
	{
		return (9);
	}
	if (v[0] >= '2' && v[0] <= '9' && v[1] == '\0')
	{
		return ((v[0] - '0') - 1);
	}
	return (0);
}

/**
 * dk_cmp - qsort comparator for deck nodes
 * @a: Pointer to first element (deck_node_t *)
 * @b: Pointer to second element (deck_node_t *)
 * Return: <0 if a<b, 0 if equal, >0 if a>b
 */
int dk_cmp(const void *a, const void *b)
{
	const deck_node_t *x;
	const deck_node_t *y;
	int k1, k2, v1, v2;

	x = *(const deck_node_t * const *)a;
	y = *(const deck_node_t * const *)b;

	k1 = (int)x->card->kind;
	k2 = (int)y->card->kind;
	if (k1 != k2)
	{
		return (k1 - k2);
	}

	v1 = dk_v(x->card->value);
	v2 = dk_v(y->card->value);
	return (v1 - v2);
}

/**
 * dk_fill - Copies list nodes into an array
 * @d: Head of the deck list
 * @a: Array of node pointers
 * Return: Number of nodes copied
 */
size_t dk_fill(deck_node_t *d, deck_node_t **a)
{
	size_t i;

	i = 0;
	while (d)
	{
		a[i] = d;
		++i;
		d = d->next;
	}
	return (i);
}

/**
 * dk_link - Relinks nodes according to sorted array order
 * @deck: Address of the head pointer
 * @a: Sorted array of node pointers
 * @n: Number of nodes
 */
void dk_link(deck_node_t **deck, deck_node_t **a, size_t n)
{
	size_t i;

	for (i = 0; i < n; ++i)
	{
		a[i]->prev = (i == 0) ? NULL : a[i - 1];
		a[i]->next = (i + 1 == n) ? NULL : a[i + 1];
	}
	*deck = a[0];
}

/**
 * sort_deck - Sorts a deck of cards (Ace->King, Spade->Diamond)
 * @deck: Double pointer to the head of the deck list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *a[52];
	size_t n;

	if (!deck || !*deck)
	{
		return;
	}

	n = dk_fill(*deck, a);
	if (n < 2)
	{
		return;
	}

	qsort(a, n, sizeof(deck_node_t *), dk_cmp);
	dk_link(deck, a, n);
}
