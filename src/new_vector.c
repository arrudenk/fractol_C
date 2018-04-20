

#include "../includes/fractol.h"

t_vec4		vec4(double x, double y, double z, double w, double f)
{
	t_vec4		v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	v.f = f;
	return (v);
}

