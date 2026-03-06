#include "palindrome.h"

/**
 * is_palindrome - checks whether an unsigned long is a palindrome
 * @n: number to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long div = 1;
	unsigned long leading;
	unsigned long trailing;

	if (n < 10)
		return (1);

	while (n / div >= 10)
		div *= 10;

	while (n > 0)
	{
		leading = n / div;
		trailing = n % 10;
		if (leading != trailing)
			return (0);

		/* Remove leading and trailing digits */
		n = (n % div) / 10;
		if (div < 100)
			break;
		div /= 100;
	}

	return (1);
}
