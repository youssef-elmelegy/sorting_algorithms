#include "sort.h"

/**
 * len - returns length of list
 * @list: head
 *
 * Return: length of list
 */
size_t len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * switch_nodes - function swaps nodes at pointer p with the following node
 * @list: head of list
 * @p: pointer to node
 */
void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *first, *sec, *third, *fourth;

	first = (*p)->prev;
	sec = *p;
	third = (*p)->next;
	fourth = (*p)->next->next;
	sec->next = fourth;

	if (fourth)
		fourth->prev = sec;
	third->next = sec;
	third->prev = sec->prev;

	if (first)
		first->next = third;
	else
		*list = third;
	sec->prev = third;
	*p = third;
}

/**
 * cocktail_sort_list - function sorts a doubly linked list using
 * the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int sorted = 0;

	if (!list || !*list || len(*list) < 2)
		return;
	p = *list;
	while (!sorted)
	{
		sorted = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				sorted = 0;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (sorted)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				sorted = 0;
				p = p->prev;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}

