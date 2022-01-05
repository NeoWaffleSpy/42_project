/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorPicker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:03:39 by ncaba             #+#    #+#             */
/*   Updated: 2021/09/18 21:07:26 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	angle_to_r(int angle) {
	if (angle >= 0 && angle <= 60)
		return (int)((float)(255) * (float)angle / (float)60);
	if (angle >= 60 && angle < 180)
		return (255);
	if (angle >= 180 && angle <= 240)
		return (int)((float) (255) * ((float)(angle) / (float)(-60) + 4));
	if (angle >= 240 && angle <= 300)
		return (0);
	return (0);
}

static int	angle_to_g(int angle) {
	if (angle < 60 || angle > 300)
		return (255);
	if (angle > 120 && angle < 240)
		return (0);
	if (angle >= 60 && angle <= 120)
		return ((int) (float) (255) * ((float)(angle) / (float)(-60) + 2));
	if (angle >= 240 && angle <= 360)
		return ((int) (float) (255) * ((float)(angle) / (float)(60) - 4));
	return (0);
}

static int	angle_to_b(int angle) {
	if (angle >= 0 && angle <= 120)
		return (0);
	if (angle >= 120 && angle <= 180)
		return ((int) (float) (255) * ((float)(angle) / (float)(60) - 2));
	if (angle >= 180 && angle <= 300)
		return (255);
	if (angle >= 300 && angle <= 360)
		return ((int) (float) (255) * ((float)(angle) / (float)(-60) + 6));
	return (0);
}

int		cycle_HSL(int angle)
{
	if (angle < 0)
		angle = - angle;
	angle = angle % 360;
	int r, g, b;

	r = angle_to_r(angle);
	g = angle_to_g(angle);
	b = angle_to_b((angle));
	return (r * 256 * 256) + (g * 256) + (b);
}
