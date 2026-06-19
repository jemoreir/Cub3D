/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:24:30 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/22 19:42:46 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;
	char			*r;

	cc = (char) c;
	i = 0;
	r = 0;
	while (s[i])
	{
		if (s[i] == cc)
			r = (char *) &s[i];
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	if (r != 0)
		return (r);
	return (NULL);
}
// int main ()
// {
// 	char s[] = "01012101102100.";
// 	printf("%s\n", ft_strrchr(s, '1'));
// }