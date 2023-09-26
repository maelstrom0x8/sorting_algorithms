#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a linked-list with
 * the Insertion Sort algorithm
 * @list: List input
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *next;
	int current_value;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		current_value = current->n;
		previous = current->prev;
		next = current->next;

		while (previous && previous->n > current_value)
		{

			previous->next = next;
			if (next)
				next->prev = previous;

			current->next = previous;
			current->prev = previous->prev;

			if (previous->prev)
				previous->prev->next = current;
			else
				*list = current;

			previous->prev = current;

			previous = current->prev;
			next = current->next;
			print_list(*list);
		}

		current = next;
	}
}
