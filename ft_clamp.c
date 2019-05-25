/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 21:06:11 by dkhatri           #+#    #+#             */
/*   Updated: 2019/05/10 21:23:37 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		ft_clamp(double *d, double start, double end)
{
	if (*d < start)
		*d = start;
	else if (*d > end)
		*d = end;
}