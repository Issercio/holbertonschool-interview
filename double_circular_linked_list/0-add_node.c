#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - adds a node at the end of a double circular linked list
 * @list: address of the head of the list
 * @str: string to duplicate into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new;
	List *tail;

	if (list == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	tail = (*list)->prev;

	new->next = *list;
	new->prev = tail;
	tail->next = new;
	(*list)->prev = new;

	return (new);
}

/**
 * add_node_begin - adds a node at the beginning of a double circular list
 * @list: address of the head of the list
 * @str: string to duplicate into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = add_node_end(list, str);
	if (new == NULL)
		return (NULL);

	*list = new;

	return (new);
}
