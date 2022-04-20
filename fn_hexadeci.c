#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
* _print_u - prints an unsigned integer
* @u: the list of arguments
* Return: number of printed characters
*/
int _print_u(va_list u)
{
	unsigned int i, num, div, o, n, count = 0;

	n = va_arg(u, unsigned int);
	o = n % 10;
	n = n / 10;
	num = n;
	div = 1;
	if (num > 0)
	{
		while ((num / 10) != 0)
		{
			num = num / 10;
			div = div * 10;
		}
		while (div >= 1)
		{
			i = n / div;
			_putchar(i + '0');
			count++;
			n = n % div;
			div = div / 10;
		}
	}
	_putchar(o + '0');
	count++;
	return (count);
}
/**
* _print_o - prints an octal
* @o: the list of arguments
* Return: number of printed characters
*/
int _print_o(va_list o)
{
	unsigned int octal[10];
	unsigned int count = 0, n = 0;
	int i = 0;

	n = va_arg(o, unsigned int);
	if (n == 0)
	{
		_putchar(0 + '0');
		count++;
	}
	while (n > 0)
	{
		octal[i] = n % 8;
		n = n / 8;
		i++;
	}
	for (--i; i >= 0; i--)
	{
		_putchar(octal[i] + '0');
		count++;
	}
	return (count);
}
