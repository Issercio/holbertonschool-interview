#ifndef HOLBERTON_H
#define HOLBERTON_H

int _putchar(char c);
int is_numeric(char *s);
void multiply_and_carry(char *num1, char *num2, int *temp,
	int len1, int len2, int len_result);
void trim_leading_zeros(char *result, int len);
char *multiply_numbers(char *num1, char *num2);

#endif
