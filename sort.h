#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print_array.c */
void print_array(const int *array, size_t size);

/* print_list.c */
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);
void swap_list(listint_t **list, listint_t *big, listint_t *small);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void swap_quick(int *a, int *b);
int key_founder(int *arr, int start, int end, size_t size);
void parts_sorting(int *arr, int start, int end, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);
void switch_nodes(listint_t **list, listint_t **p);

#endif

