/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:33:59 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 04:40:52 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*check_sig(int *sig, char *str)
{
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sig *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	long long	res;
	long long	n;
	int			sig;

	sig = 1;
	res = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
			str++;
	str = check_sig(&sig, str);
	while (*str >= '0' && *str <= '9')
	{
		n = res;
		res = res * 10 + *str - 48;
		if (res < n)
			ft_error(NULL);
		if (n != res / 10 && sig == -1)
			return (0);
		else if (n != res / 10 && sig == 1)
			return (-1);
		str++;
	}
	if ((sig == 1 && res >= 2147483647) || (res >= 2147483648 && sig == -1))
		ft_error(NULL);
	return (res * sig);
}
