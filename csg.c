/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:25:11 by trobicho          #+#    #+#             */
/*   Updated: 2019/05/10 11:26:40 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "transform.h"
#include <math.h>

double	csg_union(t_object *obj, t_vec3 p)
{
	double	d1;
	double	d2;

	d1 = op_transform(&obj->csg->o1, p);
	d2 = op_transform(&obj->csg->o2, p);
	return (fmin(d1, d2));
}

double	csg_sub(t_object *obj, t_vec3 p)
{
	double	d1;
	double	d2;

	d1 = op_transform(&obj->csg->o1, p);
	d2 = op_transform(&obj->csg->o2, p);
	return (fmax(d1, -d2));
}

double	csg_intersect(t_object *obj, t_vec3 p)
{
	double	d1;
	double	d2;

	d1 = op_transform(&obj->csg->o1, p);
	d2 = op_transform(&obj->csg->o2, p);
	return (fmax(d1, d2));
}
