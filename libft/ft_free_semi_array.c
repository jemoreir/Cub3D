/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_semi_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:46:09 by jemoreir          #+#    #+#             */
/*   Updated: 2026/09/15 15:46:09 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_semi_array(char **array, int c)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (i < c)
		free(array[i++]);
	free(array);
}
