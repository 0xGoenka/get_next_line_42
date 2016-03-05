/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:26:29 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/03 17:05:21 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	help(long long int n, char **res)
{
	if (n == 0)
	{
		*res = ft_strdup("0");
		return (0);
	}
	if (n == -2147483648)
	{
		*res = ft_strdup("-2147483648");
		return (0);
	}
	return (1);
}

char		*ft_itoa(long long int n)
{
	int		tmp;
	char	*res;
	int		a;

	a = 0;
	tmp = nu_len(n, 10);
	if (help(n, &res) == 0)
		return (res);
	if (n < 0)
	{
		a = 1;
		n = -n;
	}
	res = ft_strnew(tmp + 1 + a);
	res[0] = '-';
	while (tmp > 0)
	{
		tmp--;
		res[tmp + a] = n % 10 + 48;
		n = n / 10;
	}
	return (res);
}
