#include "fillit.h"

static char		***split_tetrimino(char **map)
{
	int 	i;
	char	***fullmap;

	i = 0;
	if (!(fullmap = (char ***)malloc(sizeof(char **) * g_num_tets + 1)))
		return (0);
	while (i < g_num_tets)
	{
		fullmap[i] = ft_strsplit(map[i], '\n');
		i++;
	}
	return (fullmap);
}

static t_tetrimino	*create_new_tetrimino(int size)
{
	int		i;
	t_tetrimino	*new;
	t_tetrimino	*head;

	if (!(new = (t_tetrimino *)malloc(sizeof(t_tetrimino) + 1)))
		return (0);
	head = new;
	i = 0;
	while (i < size)
	{
		if (!(new->next = (t_tetrimino *)malloc(sizeof(t_tetrimino) + 1)))
			return (0);
		new = new->next;
		i++; //could maybe have to increment in the while condition)
	}
	ft_memset(new, 0, (sizeof(t_tetrimino) + 1));
	return (head);
}

static void     set_dimensions(t_tetrimino *tet)
{
	int row;
	int col;
	int width;
	int height;

	row = -1;
	width = 0;
	height = 0;
	while (++row < SIZE)
	{
		col = -1;
		while (++col < SIZE)
		{
			(tet->x[row] == tet->x[col]) ? width++ : width;
			(tet->y[row] == tet->y[col]) ? height++ : height;
		}
	}
	if ((width % SIZE) || (height % SIZE))
	{
		width += 4;
		height += 4;
	}
	tet->width = (width / 4);
	tet->height = (height / 4);
}

static t_tetrimino	*final_tetriminos(char ***fullmap, t_tetrimino *tet, char letter, int *counter)
{
	t_tetrimino *head;

	head = tet;
	counter[0] = -1;
	while (++counter[0] < g_num_tets)
	{
		counter[3] = 0;
		counter[1] = -1;
		while (++counter[1] < SIZE)
		{
			counter[2] = -1;
			while (++counter[2] < SIZE)
			{
				if (fullmap[counter[0]][counter[1]][counter[2]] == BLOCK)
				{
					tet->x[counter[3]] = counter[1];
					tet->y[counter[3]++] = counter[2];
				}
			}
		}
		set_dimensions(tet);
		tet->letter = letter++;
		tet = tet->next;
	}
	return(head);
}

/*static void	set_dimensions(t_tetrimino *tet)
{
	int row;
	int col;
	int width;
	int height;

	row = -1;
	width = 0;
	height = 0;
	while (++row < SIZE)
	{
		col = -1;
		while (++col < SIZE)
		{
			(tet->x[row] == tet->x[col]) ? width++ : width;
			(tet->y[row] == tet->y[col]) ? height++ : height;
		}
	}
	if ((width % SIZE) || (height % SIZE))
	{
		width += 4;
		height += 4;
	}
	tet->width = (width / 4);
	tet->height = (height / 4);
}*/

t_tetrimino	*create_tetrimino(char **map)
{
	int		*counter;
	char		***fullmap;
	t_tetrimino	*tetrimino;

	if (!(counter = (int *)malloc(sizeof(int) * SIZE)))
		return (0);
	if (!(fullmap = (char ***)malloc(sizeof(char**) * g_num_tets + 1)))
		return (0);
	tetrimino = create_new_tetrimino(g_num_tets);
	fullmap = split_tetrimino(map);
	return (final_tetriminos(fullmap, tetrimino, LETTER, counter));
}
