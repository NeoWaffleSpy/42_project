

void			draw_line(t_shapes shape, t_data *data)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;

	dx = abs(shape->pos_end[0]-shape->pos_start[0]);
	sx = shape->pos_start[0]<shape->pos_end[0] ? 1 : -1;
	dy = -abs(shape->pos_end[1]-shape->pos_start[1]);
	sy = shape->pos_start[1]<shape->pos_end[1] ? 1 : -1;
	err = dx+dy;
	while (TRUE)
	{
		draw_pixel(data, shape->pos_start[0], shape->pos_start[1], 0x00FFFF00);
		if (shape->pos_start[0] == shape->pos_end[0] &&
			shape->pos_start[1] == shape->pos_end[1])
			break;
		e2 = 2*err;
		if (e2 >= dy)
		{
			err += dy;
			shape->pos_start[0] += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			shape->pos_start[1] += sy;
		}
	}
}
