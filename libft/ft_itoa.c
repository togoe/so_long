/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:50:30 by mderome           #+#    #+#             */
/*   Updated: 2021/06/14 09:50:32 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup2(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * 2);
	dest[i] = s[i];
	i++;
	dest[i] = '\0';
	return (dest);
}

static int	len_digit(long int nb, int sign)
{
	unsigned int	nb_digit;

	if (nb == 0)
		return (1);
	nb_digit = 0;
	while (nb)
	{
		nb /= 10;
		nb_digit++;
	}
	if (sign == -1)
		nb_digit++;
	return (nb_digit);
}

static char	*convert_nbr(char *str, long nb2, unsigned int len, int sign)
{
	str[len] = '\0';
	while (nb2)
	{
		str[--len] = nb2 % 10 + '0';
		nb2 /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int				sign;
	unsigned int	len;
	char			*str;
	long			nb2;

	sign = 1;
	if (n == 0)
		return (ft_strdup2("0"));
	if (n < 0)
	{
		sign *= -1;
		nb2 = (long)n * -1;
	}
	else
		nb2 = (long)n;
	len = len_digit(nb2, sign);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str = convert_nbr(str, nb2, len, sign);
	return (str);
}
