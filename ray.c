/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:18:54 by trobicho          #+#    #+#             */
/*   Updated: 2019/05/13 14:26:36 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include "vector.h"
#include "mlx.h"
#include "pixel.h"
#include "ray.h"
#include "light.h"

static t_vec3	pixel_to_ray(t_mymlx *ml, int x, int y)
{
	double	d_s;
	t_vec3	r;
	double	lx;
	double	ly;

	d_s = 1.0;
	lx = ((double)x / ml->w) - 0.5;
	ly = ((double)y / ml->h) - 0.5;
	r.x = ml->cam.right.x * lx + ml->cam.up.x * ly + ml->cam.dir.x * d_s;
	r.y = ml->cam.right.y * lx + ml->cam.up.y * ly + ml->cam.dir.y * d_s;
	r.z = ml->cam.right.z * lx + ml->cam.up.z * ly + ml->cam.dir.z * d_s;
	return (vec_normalize(r));
}

void			ray_scan_hor(t_mymlx *ml, int y)
{
	int				x;
	t_vec3			color;
	t_ray_inf		ray;
	t_pixw			pixw;

	ray.r_o = ml->cam.pos;
	x = 0;
	while (x < ml->w)
	{
		ray.r_d = pixel_to_ray(ml, x, ml->h - y);
		color = get_color(&ml->scene, ray, 5);
		pixw.x = x;
		pixw.y = y;
		pixw.w = ml->ray_w;
		putpixel_vec_w(ml, pixw, color);
		x += ml->ray_w;
	}
}
