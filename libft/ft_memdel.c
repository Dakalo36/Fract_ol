/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnematan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 17:02:48 by dnematan          #+#    #+#             */
/*   Updated: 2016/05/14 17:03:43 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	int count;
	int count1;

	count = 0;
	while ((char *)ap[count])
	{
		count1 = 0;
		while ((char *)&ap[count1] != '\0')
		{
			free(&ap[count1]);
			count1++;
		}
		free(&ap[count]);
		count++;
	}
}
