#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - The printf function
 * @format: The format.
 * Return: Returning printed chars
 */
int _printf(const char *format, ...)
{
	int t, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (t = 0; format && format[t] != '\0'; t++)
	{
		if (format[t] != '%')
		{
			buffer[buff_ind++] = format[t];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[t], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &t);
			width = get_width(format, &t, list);
			precision = get_precision(format, &t, list);
			size = get_size(format, &t);
			++t;
			printed = handle_print(format, &t, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - A function that prints the contents of the buffer
 * @buffer: An array of chars
 * @buff_ind: The index at which to add the next char, representing the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
