#include "main.h"

/*** For Printing Unsigned Number*****/
/**
 * print_unsigned - Outputs an unsigned number as part of formatted printing.
 * @types: The list of arguments and format specifiers.
 * @buffer: An array buffer used for managing the printing process.
 * @flags: Active formatting flags.
 * @width: The width of the output field.
 * @precision: The specified precision for printing.
 * @size: The size specifier.
 * Return: The count of characters printed in the output.
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

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/*** For Printing Unsigned Number In Octal  ***/
/**
 * print_octal - Unsigned number in octal format to be printed
 * @types: The list of arguments and format specifiers.
 * @buffer: An array buffer used for managing the printing process.
 * @flags: Active formatting flags.
 * @width: The width of the output field.
 * @precision: The specified precision for printing.
 * @size: The size specifier.
 * Return: The count of characters to be printed in the output.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[x--] = '0';

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/***** For Print ing Unsigned Number In Hexsdecimal ****/
/**
 * print_hexadecimal - Displays an unsigned number in hexadecimal format.
 * @types: List of arguments.
 * @buffer: Buffer for printing.
 * @flags: Formatting options.
 * @width: Output width.
 * @precision: Decimal places.
 * @size: Data size.
 * Return: Count of printed characters.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/***** For Printing Unsigned Number In Upper Hexadecimal *****/
/**
 * print_hexa_upper - Displays an unsigned number in uppercase hexadecimal.
 * @types: List of arguments.
 * @buffer: Printing buffer.
 * @flags: Formatting options.
 * @width: Output width.
 * @precision: Decimal places.
 * @size: Data size.
 * Return: Count of printed characters.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'x', width, precision, size));
}

/**** For Printing Hexa Num nN Lower Or Upper ****/
/**
 * print_hexa - Displays a hexadecimal number in lowercase or uppercase.
 * @types: List of arguments.
 * @map_to: Mapping values for the number.
 * @buffer: Printing buffer.
 * @flags: Formatting options.
 * @flag_ch: Additional flags.
 * @width: Output width.
 * @precision: Decimal places.
 * @size: Data size.
 * Return: Count of printed characters.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
