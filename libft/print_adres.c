/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_adres.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 11:47:28 by snijhuis      #+#    #+#                 */
/*   Updated: 2023/11/15 11:29:09 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adreshulp(long long unsigned n, char *base);

int	print_adres(unsigned long long ptr)
{
	if (ptr == 0)
		return (print_str("(nil)"));
	else if (ptr == (unsigned long long)LONG_MIN)
		return (print_str("0x8000000000000000"));
	else if (ptr == ULONG_MAX)
		return (print_str("0xffffffffffffffff"));
	print_str("0x");
	return (ft_adreshulp(ptr, "0123456789abcdef") + 2);
}

int	ft_adreshulp(long long unsigned n, char *base)
{
	int	count;
	int	o;
	int	c;

	count = 0;
	while (base[count])
		count++;
	o = check_length(n, count);
	if (n >= (long long unsigned)count)
		ft_adreshulp(n / count, base);
	n = n % count;
	c = base[n];
	write(1, &c, 1);
	return (o);
}

// #include "ft_printf.h"
// int ft_print_ptr(unsigned long long ptr, int base)
// {
//     if (ptr == 0)
//         return (ft_printf("(nil)"));

//     else if (ptr == (unsigned long long)LONG_MIN)
//     {
//         ft_printf("0x8000000000000000");
//         return (18);
//     }
//     else if (ptr == ULONG_MAX)
//     {
//         ft_printf("0xffffffffffffffff");
//         return (18);
//     }

//     ft_printf("0x");
//     return (ft_print_lower_hex(ptr, base) + 2);
// }