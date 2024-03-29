#include "main.h"

/**
* _printf - printf function implemented
* @format: format
* Return: Printed Chars
*/

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;

	int flags, width, precision,

	size, buff_ind = 0;

	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];

			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
		}
	}

}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: array of chars
 * @buff_ind: Index at which to add next char, represents the length
*/

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

