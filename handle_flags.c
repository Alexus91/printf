#include "main.h"

/**
 * handle_flags - Matches flags with corresponding values.
 * @flag: A pointer to a potential string of flags.
 * @index: An index counter for the original format string.
 *
 * Return: If flag characters are matched - a corresponding value.
 *         Otherwise - 0.
 */
unsigned char handle_flags(const char *flag, char *index)
{
	int i, j;
	unsigned char ret = 0;

	flag_t flags[] = {
		    {'+', PLUS},
		    {' ', SPACE},
		    {'#', HASH},
		    {'0', ZERO},
		    {'-', NEG},
		    {0, 0}};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*index)++;
				if (ret == 0)
					ret = flags[j].value;
				else
					ret |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}
return (ret);
}
