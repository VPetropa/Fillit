#include "fillit.h"

static void	print_solution(char **map)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(*map);
	while (++i < (len + 1))
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

int	main(int argc, char **argv)
{
	int fd;
	char **map;
	t_tetrimino *tetriminos;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
				ft_putstr("uuuups, invalid file\n");
		else if ((map = input_read(fd)) && (ft_strlen(map[0])) && (!map[g_num_tets - 1][TETRIMINO_SIZE - 1]))
		{
			tetriminos = create_tetrimino(map);
			map = solve(tetriminos);
			print_solution(map);
			free(tetriminos);
			ft_memdel((void **)map);
		}
		else
			ft_putstr("upps, invalid Tetro\n");
			close (fd);
	}
	//else
	//	fillit_usage(argv[0]);
	return(0);
}
