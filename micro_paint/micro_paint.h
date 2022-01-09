/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:13:05 by lprates           #+#    #+#             */
/*   Updated: 2022/01/09 11:11:48 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct	s_drawing
{
	int		height;
	int		width;
	char	background;
	char	**matrix;
}				t_drawing;

typedef struct	s_rectangle
{
	char	type;
	float	height;
	float	width;
	float	tlx;
	float	tly;
	char	drawn_char;
}				t_rectangle;


#endif
