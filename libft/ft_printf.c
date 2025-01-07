/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 10:01:48 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/15 14:03:40 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *input, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, input);
	count = 0;
	while (*input != '\0')
	{
		if (*input == '%' && *(input + 1) == '\0')
			return (-1);
		if (*input == '%' && ft_strchr("spcdixXu%", *(input + 1)))
			count += print_cases(*(++input), ap);
		else
			count += write(1, input, 1);
		input++;
	}
	va_end(ap);
	return (count);
}

// finds and points to the start of the arguments
// 	{
// 		return (print_char(symbols[n]));
// 	}
// 	else
// 	{
// 		count = print_digit(n / base, base);

// 		return (count + print_digit(n % base, base));
// 	}
// }

// unsigned long long int
//&c

// return inteteger hoeveelheid characters heeft geprint

// 0x voor een adres. adres is een void * (nummer) omgezet naar

// int	ft_printf(const char *input, ...);
// int	print_cases (char character, va_list ap);
// int print_char(int c);
// int print_str(char *str);
// int	ft_putnbr(long n, char *base);
// int check_length (long n, int count);
// int print_adres (unsigned long long ptr);

// // int	main (void)
// // {

// // 	char *string1 = "ABC%\0EF";
// // 	char string2[] = "123456";
// // 	// int c;
// // 	// c = 6487;
// // 	// char *d;
// // 	// d = &c;
// // 	// ft_printf("%p\n", d);
// // 	// printf("%p", d);
// // 	// printf("hi %d there", ft_printf("rubsenman%c", 's'));
// // 	// ft_printf(" NULL %s NULL ", NULL);
// // 	// printf(" %p %p ", LONG_MIN, LONG_MAX);
// // 	printf("%d\n", printf(" %d \n", -1));
// // 	printf("%d\n", ft_printf(" %d \n", -1));

// //     return (0);
// // }
// int	main(void)
// {
// 	int		i;
// 	int		j;
// 	char	string1[] = "AB%WWDEF";
// 	char	*string2;

// 	// 	char			char1 = 'q', char2 = '\t', char3 = 'string';
// 	// 	char			str1[] = "Hello", str2[] = "", *str3 = NULL;
// 	// 	int				int1 = 16, int2 = -2147483648, int3 = 2147483650;
// 	// 	unsigned int	uint1 = 145, uint2 = -50, uint3 = 4294967296;
// 	// 	int				hu1 = 16, hu2 = -5000, hu3 = 4294967296;
// 	// 	int				hl1 = 9946843, hl2 = -2147483648, hl3 = 2147483650;
// 	// 	int				ptr1 = 40, ptr2 = NULL, ptr3 = 'c', ptr4 = -1;
// 	//  printf("Chars %%: %c, %c, %c\n", char1, char2, char3);
// 	// 	ft_printf("Chars %%: %c, %c, %c\n\n", char1, char2, char3);
// 	// 	printf("Strings: %s, %s, %s\n", str1, str2, str3);
// 	// 	ft_printf("Strings: %s, %s, %s\n\n", str1, str2, str3);
// 	// 	printf("Ints: %d, %i, %d\n", int1, int2, int3);
// 	// 	ft_printf("Ints: %d, %i, %d\n\n", int1, int2, int3);
// 	// 	printf("Unsigned: %u, %u, %u\n", uint1, uint2, uint3);
// 	// 	ft_printf("Unsigned: %u, %u, %u\n\n", uint1, uint2, uint3);
// 	// 	printf("Hex Upper: %X, %X, %X\n", hu1, hu2, hu3);
// 	// 	ft_printf("Hex Upper: %X, %X, %X\n\n", hu1, hu2, hu3);
// 	// 	printf("Hex Lower: %x, %x, %x\n", hl1, hl2, hl3);
// 	// 	ft_printf("Hex Lower: %x, %x, %x\n\n", hl1, hl2, hl3);
// 	// 	printf("ptrs: %p, %p, %p, %p \n", ptr1, ptr2, ptr3, ptr4);
// 	// 	ft_printf("ptrs: %p, %p, %p, %p \n\n", ptr1, ptr2, ptr3, ptr4);
// 	// 	printf("mix: %% %c %s %d %x\n", char1, str1, int1, hl1);
// 	// 	ft_printf("mix: %% %c %s %d %x\n\n", char1, str1, int1, hl1);
// 	string2 = "123456";
// 	ft_printf("%s", "return (value check:\n"));
// 	i = ft_printf(string1, string2);
// 	printf("\n%d\n", i);
// 	j = printf(string1, string2);
// 	printf("\n%d", j);
// 	if (i != j)
// 	{
// 		printf("\n\nThe value is incorrect!\ni = %d\nj = %d\n\n", i, j);
// 	}
// 	return (0);
// }