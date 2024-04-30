#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *insertion_point = current->prev;
		listint_t *next_node = current->next;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			insertion_point = insertion_point->prev;
		}
		if (insertion_point == NULL)
		{
			(*list)->prev = current;
			current->next = *list;
			current->prev->next = next_node;
			if (next_node != NULL)
				next_node->prev = current->prev;
			current->prev = NULL;
			*list = current;
		}
		else if (insertion_point != current->prev)
		{
			current->next->prev = next_node;
			if (next_node != NULL)
				next_node->prev = current->prev;
			current->next = insertion_point->next;
			insertion_point->next = current;
			current->prev->next = next_node;
			current->prev = insertion_point;
		}
		current = next_node;
		print_list(*list);
	}
}
