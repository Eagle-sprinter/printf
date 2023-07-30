#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - A function printing a char.
 * @types: The argument list
 * @buffer: The buffer array handling print
 * @flags:  To computes active flags
 * @width: The width
 * @precision: The specification of precision
 * @size: The specifier of size
 * Return: The number of printed chars.
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - A function printing a string
 * @types: The list of arguments
 * @buffer: The buffer array handling print
 * @flags:  To calculate active flags
 * @width: get width.
 * @precision: The specification of precision
 * @size: The specifier of size
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, o;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (o = width - length; o > 0; o--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (o = width - length; o > 0; o--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - A function printing the percentage sign.
 * @types: The argument list
 * @buffer: The buffer array handling print
 * @flags:  To calculates active flags
 * @width: To get the width.
 * @precision: The specification of precision
 * @size: The specifier of size
 * Return: The number of printed chars
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - A function print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int o = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[o--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[o--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, o, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - A function that prints an unsigned int
 * @types: The argument list
 * @buffer: The buffer array handling print
 * @flags:  To compute active flags
 * @width: To get the width.
 * @precision: The specification precision
 * @size: The specifier of size
 * Return: The numbers of printed chars
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int e, f, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	e = va_arg(types, unsigned int);
	f = 2147483648; /* (2 ^ 31) */
	a[0] = e / f;
	for (g = 1; g < 32; g++)
	{
		f /= 2;
		a[g] = (e / f) % 2;
	}
	for (g = 0, sum = 0, count = 0; g < 32; g++)
	{
		sum += a[g];
		if (sum || g == 31)
		{
			char z = '0' + a[g];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
