#include "main.h"

/**
 * get_flags - Evaluate and determine the active formatting flags
 * @fmt: The formatted string representing the desired output
 * @j: An input parameter utilized in the evaluation process
 * Return: The set of flags that are currently active
 */
int get_flags(const char *fmt, int *j)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, curr_j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_j = *j + 1; format[curr_j] != '\0'; curr_j++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[curr_j] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*j = curr_j - 1;

	return (flags);
}
