/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:12:43 by lprates           #+#    #+#             */
/*   Updated: 2022/01/09 11:17:37 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	get_settings(FILE *input, t_drawing *drawing)
{
	int	scanfcount;
	int i;
	int	j;

	i = -1;
	j = -1;
	scanfcount = fscanf(input, "%i %i %c", &drawing->width, &drawing->height, &drawing->background);
	if (scanfcount != 3)
		return (1);
	drawing->matrix = (char **)malloc(sizeof(char*) * drawing->height);
	while (++i < drawing->height)
	{
		drawing->matrix[i] = (char *)malloc(sizeof(char) * drawing->width);
		if (!drawing->matrix[i])
			return (1);
	}
	i = -1;
	if (!drawing->matrix)
		return (1);
	if (drawing->height <= 0 || drawing->height > 300 || drawing->width <= 0
		|| drawing->width > 300)
		return (1);
	while (++i < drawing->height)
	{
		j = -1;
		while (++j < drawing->width)
			drawing->matrix[i][j] = drawing->background;
	}
	return (0);
}

void	print_drawing(t_drawing *drawing)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < drawing->height)
	{
		j = -1;
		while (++j < drawing->width)
		{
			write(1, &drawing->matrix[i][j], 1);
		}
		write(1, "\n", 1);
	}
}

void	fill_drawing(t_drawing *drawing, t_rectangle *rectangle)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < drawing->height)
	{
		j = -1;
		while (++j < drawing->width)
		{
			if (rectangle->tlx - j < 1.F ||)
			write(1, &drawing->matrix[i][j], 1);
		}
		write(1, "\n", 1);
	}
}

int	read_op_file(FILE *input)
{
	t_drawing	drawing;
	t_rectangle	rectangle;
	int	i;
	int	j;
	int	scanref;

	i = -1;
	j = -1;
	scanref = 6;
	if (get_settings(input, &drawing))
		return (1);
	while (scanref == 6)
	{
		scanref = fscanf(input, "%c %f %f %f %f %c", rectangle.type, rectangle.tlx,
					rectangle.tly, rectangle.width, rectangle.height, rectangle.drawn_char);
		fill_drawing(&drawing, &rectangle);
	}
	print_drawing(&drawing);
	return (0);
}

int	main(int argc, char *argv[])
{
	FILE *input;
	if (argc != 2)
	{
		ft_putstr("Error: argument\n");
		return (1);
	}
	input = fopen(argv[1], "r");
	if (!input || read_op_file(input))
	{
		ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	return (0);
}
