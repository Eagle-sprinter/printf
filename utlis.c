#include "main.h"

/**
 * is_printable - A function evaluating whether the char is printable
 * @c: The char to evaluate
 *
 * Return: Return 1 if c is printable, 0 otherwise.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - A function appending ASCII in hexadecimal code to the buffer
 * @buffer: The array of chars to append to
 * @i: The index where the appending starts
 * @ascii_code: The ASCII CODE
 * Return: Return 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - A function verifying whether the char is a digit
 * @c: The evaluated char
 *
 * Return: Return 1 if c is a digit, otherwise 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - A function casting a number to the size specified
 * @num: The cast number
 * @size: The number indicating the type to cast
 *
 * Return: The cast value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - A function casting a number to the size specified
 * @num: the number to cast
 * @size: The number that indicates the cast type
 *
 * Return: The cast value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
