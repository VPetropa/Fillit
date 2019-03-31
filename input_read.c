#include "fillit.h"

static int	valid_char(char *tetrimino)
{
	int	i;
	int	height;
	int	blocks;
	int	chars;

	i = 0;
	height = 0;
	blocks = 0;
	chars = 0;
	while ((tetrimino[i] == EMPTY || tetrimino[i] == BLOCK || tetrimino[i] == '\n') && tetrimino[i] != '\0' && height != SIZE)
	{
		if (tetrimino[i] == EMPTY || tetrimino[i] == BLOCK)
		{
			if (tetrimino[i] == BLOCK)
				blocks++;
			chars++;
		}
		if (tetrimino[i++] == '\n')
			height++;
	}
	if (((chars) == SIZE * SIZE) && (height == SIZE) && (blocks == SIZE) && (tetrimino[i] == '\n' || tetrimino[i] == '\0'))
		return (1);
	return (0);
}

static int	valid_tetrimino(char **tetrimino)
{
	int	count;
	int	row;
	int	col;

	count = 0;
	row = -1;
	while (SIZE > ++row)
	{
		col = -1;
		while (SIZE > ++col)
		{
			if (tetrimino[row][col] == BLOCK && row < 3)
				tetrimino[row + 1][col] == BLOCK ? count++ : count;
			if (tetrimino[row][col] == BLOCK && row > 0)
				tetrimino[row - 1][col] == BLOCK ? count++ : count;
			if (tetrimino[row][col] == BLOCK && col < 3)
				tetrimino[row][col + 1] == BLOCK ? count++ : count;
			if (tetrimino[row][col] == BLOCK && col > 0)
				tetrimino[row][col - 1] == BLOCK ? count++ : count;
		}
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

static int	valid_check(char *map)
{
	if (valid_char(map))
		if (valid_tetrimino((ft_strsplit(map, '\n'))))
			return(1);
	return(0);
}

char	**input_read(int fd)
{
	int i;
	char **map;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * BUFF_SIZE)))
		return (0);
	while (i < TETRIMINO_MAX_TOTAL)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * TETRIMINO_SIZE)))
			return (0);
		ft_bzero(map[i], TETRIMINO_SIZE);
		if (!(read(fd, map[i], TETRIMINO_SIZE)))
			return (map);
		if (!(valid_check(map[i])))
			return (0);
		i++;
		g_num_tets = i;
	}
	return (0);
}
