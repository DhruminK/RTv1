/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 02:07:53 by trobicho          #+#    #+#             */
/*   Updated: 2019/05/13 14:25:09 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing.h"
#include "scene.h"

double	tracing(t_scene *scene, t_vec3 ray_o, t_vec3 ray_d, t_object **obj_min)
{
	int		i;
	double	d_o;
	double	d_s;
	t_vec3	p;

	i = 0;
	p = ray_o;
	d_o = 0.0;
	while (i < MAX_STEP)
	{
		p.x = ray_o.x + d_o * ray_d.x;
		p.y = ray_o.y + d_o * ray_d.y;
		p.z = ray_o.z + d_o * ray_d.z;
		d_s = scene_get_dist(scene, p, obj_min);
		d_o += d_s;
		if (d_o > DIST_MAX || d_s < DIST_MIN)
			break ;
		i++;
	}
	if (d_o > DIST_MAX)
		return (DIST_MAX);
	return (d_o);
}
