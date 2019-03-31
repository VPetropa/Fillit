#include "fillit.h"

static void	move_tetro_up_left(t_tetrimino *tet)
{
	int	i;
	int	pos_x;
	int	pos_y;

	while (tet)
	{
		i = -1;
		pos_x = SIZE - 1;
		pos_y = SIZE - 1;
		while (++i < SIZE)
		{
			if (tet->x[i] < pos_x)
				pos_x = tet->x[i];
			if (tet->y[i] < pos_y)
				pos_y = tet->y[i];
		}
		i = -1;
		while (++i < SIZE)
		{
			tet->x[i] -= pos_x;
			tet->y[i] -= pos_y;
		}
		tet = tet->next;
	}
}

char		**create_map(int size)
{
	char		**map;
	int		row;
	int		col;
	
	if (!(map = (char **)malloc(sizeof(char *) * SIZE)))
		return (0);
	row = 0;
	while (row < size)
	{
		if (!(map[row] = (char *)malloc(sizeof(char) * size + 1)))
			return (0);
		row++;
	}
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
			map[row][col++] == EMPTY;
		map[row][col] = '\0';
		row++;
	}
	return (map);
}

double		ft_sqrt(double x)
{
	long i;

	i = 1;
	if (x < 0)
		return (0);
	while (i * i < x)
		i++;
	return (i);
}

static void	set_tetrimino(t_tetrimino *tet, char **map, int y, int x)
{
	int	row;
	int	col;
	int	i;

	i = 0;
	col = 0;
	while (tet->height > row)
	{
		row = 0;
		while (tet->width > row)
		{
			if (tet->x[i] == col && tet->y[i] == row)
			{
				map[col + y][row + x] = tet->letter;
				i++;
			}
			row++;
		}
		col++;
	}
}

static int	check_placement(t_tetrimino *tet, char **map, int x, int y)
{
	int	row;
	int	col;
	int	i;

	i = 0;
	col = 0;
	while (tet->height > col)
	{
		row = 0;
		while (tet->width > row)
		{
			if (tet->x[i] == col && tet->y[i] == row && i < SIZE)
			{
				if (map[col + y][row + x] != EMPTY)
					return (0);
				i++;
			}
			row++;
		}
		col++;
	}
	set_tetrimino(tet, map, y, x);
	return (1);
}

static int	solve_map(char **map, t_tetrimino *tet, int size)
{
	int	x;
	int	y;
	char 	letter;

	if(!tet->next)
		return(1);
	y = -1;
	letter = tet->letter;
	while (++y <= (size - tet->width))
	{
		x = -1;
		while (++x <= (size - tet->width))
		{
			if (check_placement(tet, map, y, x))
			{
				if (solve_map(map, tet->next, size))
					return (1);
				tet->letter = EMPTY;
				set_tetrimino(tet, map, y, x);
				tet->letter = letter;
			}
		}
	}
	return (0);
}

char		**solve(t_tetrimino *tet)
{
	char	**map;
	int	size;

	if (!tet)
		return (0);
	size = ft_sqrt(g_num_tets * SIZE);
	map = create_map(size);
	move_tetro_up_left(tet);
	while(!solve_map(map, tet, size))
	{
		ft_memdel((void **)map);
		size++;
		map = create_map(size);
	}
	return (map);
}
