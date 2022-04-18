#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/**
 * _printf - produces output according to a format
 * @format: number of arguments passed to the function
 * Return: the resulting sum
 */
int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0, j = 0;
	char buff[100] = {0};
	char *str_arg;

	va_start(vl, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				/* Convert char */
				case 'c':
					{
						  buff[j] = (char)va_arg(vl, int);
						  j++;
						break;
					}
					/* copy string */
				case 's':
					{
						  str_arg = va_arg(vl, char*);
						  strcpy(&buff[j], str_arg);
						  j += strlen(str_arg);
						break;
					}
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout);
	va_end(vl);
	return (j);
}
