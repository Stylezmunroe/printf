#include "main.h"

/**** FOR PRINTING CHARACTERS ***/
/**
 * print_char - Prints a character as part of a formatted output.
 * @types: The list of arguments and format specifiers.
 * @buffer: An array buffer used for managing the print.
 * @flags: Active formatting flags.
 * @width: The width of the output field.
 * @precision: The specified precision.
 * @size: The size specifier.
 * Return: The count of characters printed.
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**** FOR PRINTING A STRING ***/
/**
 * print_string - Outputs a string as part of formatted printing.
 * @types: The list of arguments and format specifiers.
 * @buffer: An array buffer for managing the print operation.
 * @flags: Active formatting flags.
 * @width: The output field width.
 * @precision: The specified precision for printing.
 * @size: The size specifier.
 * Return: The count of characters successfully printed.
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
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
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**** FOR PRINTIMG PERCENT SIGN ***/
/**
 * print_percent - Outputs a percent sign as part of formatted printing.
 * @types: The list of arguments and format specifiers.
 * @buffer: An array buffer used to manage the printing process.
 * @flags: Active formatting flags.
 * @width: The width of the output field.
 * @precision: The specified precision for printing.
 * @size: The size specifier.
 * Return: The count of characters printed in the output.
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

/*** FOR PRINTING INT ****/
/**
 * print_int - Outputs an integer as part of formatted printing.
 * @types: The list of arguments and format specifiers.
 * @buffer: An array buffer used for managing the printing process.
 * @flags: Active formatting flags.
 * @width: The output field width.
 * @precision: The specified precision for printing.
 * @size: The size specifier.
 * Return: The count of characters printed in the output.
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_numbar(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/*** FOR PRINTING BINARY ***/
/**
 * print_binary - Unsigned number in binary format to be printed
 * @types: The list of arguments and format specifiers.
 * @buffer: An array buffer utilized for managing the printing operation.
 * @flags: Active formatting flags.
 * @width: The width of the output field.
 * @precision: The specified precision for printing.
 * @size: The size specifier.
 * Return: The count of characters printed in the output.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
