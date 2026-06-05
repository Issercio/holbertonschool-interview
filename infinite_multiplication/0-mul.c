#include "holberton.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_numeric - Check if a string contains only digits
 * @s: String to check
 *
 * Return: 1 if string is numeric, 0 otherwise
 */
int is_numeric(char *s)
{
	if (s == NULL || s[0] == '\0')
		return (0);

	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * multiply_numbers - Multiply two numeric strings
 * @num1: First number as string
 * @num2: Second number as string
 *
 * Return: Result as string (allocated with malloc)
 */
char *multiply_numbers(char *num1, char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len_result = len1 + len2;
	char *result;
	int *temp;
	int i, j, pos, prod;

	result = malloc(len_result + 1);
	if (result == NULL)
		exit(98);

	temp = malloc(len_result * sizeof(int));
	if (temp == NULL)
	{
		free(result);
		exit(98);
	}

	/* Initialize temp array to 0 */
	for (i = 0; i < len_result; i++)
		temp[i] = 0;

	/* Long multiplication: multiply each digit of num1 with each digit of num2 */
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			pos = i + j + 1;
			prod = (num1[i] - '0') * (num2[j] - '0');
			temp[pos] += prod;
		}
	}

	/* Handle carries from right to left */
	for (i = len_result - 1; i > 0; i--)
	{
		temp[i - 1] += temp[i] / 10;
		temp[i] %= 10;
	}

	/* Convert to string */
	for (i = 0; i < len_result; i++)
		result[i] = temp[i] + '0';
	result[len_result] = '\0';

	free(temp);

	/* Skip leading zeros */
	i = 0;
	while (i < len_result - 1 && result[i] == '0')
		i++;

	if (i > 0)
	{
		int new_len = len_result - i;
		for (j = 0; j <= new_len; j++)
			result[j] = result[i + j];
	}

	return (result);
}

/**
 * main - Entry point, multiplies two numbers
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *result;
	int i;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	if (!is_numeric(argv[1]) || !is_numeric(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	result = multiply_numbers(argv[1], argv[2]);

	for (i = 0; result[i] != '\0'; i++)
		_putchar(result[i]);
	_putchar('\n');

	free(result);

	return (0);
}
