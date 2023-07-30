#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - A function printing an unsigned int
 * @types: The argument list
 * @buffer: The buffer array handling print
 * @flags:  To compute active flags
 * @width: To get the width
 * @precision: The specification of precision
 * @size: The specifier of size
 * Return: The number of printed chars
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - A function printing an unsigned number
 * @types: The argument list
 * @buffer: The buffer array handling print
 * @flags:  To compute active flags
 * @width: To get the width
 * @precision: The specification of precision
 * @size: The specifier of size
 * Return: The number of printed chars
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int p = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[p--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[p--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[p--] = '0';

	x++;

	return (write_unsgnd(0, p, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - A function that prints an unsigned number in hexadecimal notation
 * @types: The argument list
 * @buffer: The buffer array handling print
 * @flags:  To compute active flags
 * @width: To obtain the width
 * @precision: The specification of precision
 * @size: The specifier of size
 * Return: The number of printed chars
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - A function printing an unsigned number in upper hexadecimal notation
 * @types: The argument list
 * @buffer: The buffer array handling print
 * @flags:  To compute active flags
 * @width: To get the width
 * @precision: The specification of precision
 * @size: The specifier of size
 * Return: The number of printed chars
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - A function printing hexadecimal numbers in upper or lower
 * @types: The argument list
 * @map_to: The array of values mapping the number to
 * @buffer: The buffer array to handling print
 * @flags:  To compute active flags
 * @flag_ch: To calculate active flags
 * @width: To get the width
 * @precision: The specification of precision
 * @size: The specifier of size
 * @size: The specification of size
 * Return: the number of printed chars
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int p = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[p--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[p--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[p--] = flag_ch;
		buffer[p--] = '0';
	}

	p++;

	return (write_unsgnd(0, p, buffer, flags, width, precision, size));
}
