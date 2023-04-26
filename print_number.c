#include "main.h"

/**
 * _isdigit - func
 * @c: ssd
 *
 * Return: 1
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - fumc
 * @s: sds
 *
 * Return: int
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
/**
 * print_numer - func
 * @str: sd
 * @parems: pase
 *
 * Return: char
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UNIT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}
/**
 * print_number_right_shift - func
 * @str: sd
 * @params: params
 *
 * Return: char
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) || 
			(!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params-.unsign)
		n += _putchar('+');
	else if
