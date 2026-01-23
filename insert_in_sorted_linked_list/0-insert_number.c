#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be inserted
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	/* Insert at the beginning if head is NULL or number is smaller */
	if (*head == NULL || number < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	/* Find the correct position to insert */
	current = *head;
	while (current->next != NULL && current->next->n < number)
		current = current->next;

	/* Insert the node */
	new->next = current->next;
	current->next = new;

	return (new);
}
