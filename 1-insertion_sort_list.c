#include "sort.h"

/**
 * swaplist - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of linked list
 * @big: First node to swap
 * @small: Second node to swap
 */

void swaplist(listint_t **list, listint_t *big, listint_t *small)
{
        if (big->prev)
                big->prev->next = small;
        else
		*list = small;
        if (small->next)
                small->next->prev = big;
        
        small->prev = big->prev;
        big->prev = small;
        big->next = small->next;
        small->next = big;
}

/**
 *insertion_sort_list - sorts an array of integers in ascending order
 *@list: struct of elments to be storted
 */

void insertion_sort_list(listint_t **list)
{
        listint_t *key, *temp;

        if (list == NULL || (*list)->next == NULL || (*list) == NULL)
                return;
        key = (*list)->next;

        while (key)
        {
                temp = key->prev;
                while (temp && (key->n < temp->n))
                {
                        swaplist(list, temp, key);
                        print_list(*list);
                        temp = key->prev;
                }
                key = key->next;
        }
        
}
