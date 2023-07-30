#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - A function printing the value of a pointer var
 * @types: The argument list
 * @buffer: The buffer array handling print
 * @flags:  To compute active flags.
 * @width: To obtain the width.
 * @precision: The specification of precision 
 * @size: The specifier of size
 * Return: The number of printed chars
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - A function that prints ASCII codes in hexa of non-printable chars
 * @types: The argument list
 * @buffer: The buffer array handling print
 * @flags:  To compute active flags
 * @width: To obtain the width
 * @precision: The specification of precision
 * @size: The specifier of size
 * Return: The number of printed chars
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int p = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[p] != '\0')
	{
		if (is_printable(str[p]))
			buffer[p + offset] = str[p];
		else
			offset += append_hexa_code(str[p], buffer, p + offset);

		p++;
	}

	buffer[p + offset] = '\0';

	return (write(1, buffer, p + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - A function printing a reverse string
 * @types: The argument list
 * @buffer: The buffer array handling print
 * @flags:  To compute active flags
 * @width: To obtain the width
 * @precision: The specification of precision
 * @size: The specifier of size
 * Return: The number of printed chars
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int p, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (p = 0; str[p]; p++)
		;

	for (p = p - 1; p >= 0; p--)
	{
		char z = str[p];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - A function printing a string in rot13
 * @types: The argument list
 * @buffer: the buffer array handling print
 * @flags:  To compute active flags
 * @width: To obtain the width
 * @precision: The specification of precision
 * @size: The specifier of size
 * Return: The numbers of printed chars
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int m, n;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (m = 0; str[m]; m++)
	{
		for (n = 0; in[n]; n++)
		{
			if (in[n] == str[m])
			{
				x = out[n];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[n])
		{
			x = str[m];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
