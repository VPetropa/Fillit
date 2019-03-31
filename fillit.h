#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BLOCK '#'
# define EMPTY '.'
# define LETTER 'A'
# define NEW_LINE '\n'
# define SIZE 4
# define TETRIMINO_SIZE 21
# define TETRIMINO_MAX_TOTAL (26 - (LETTER - 'A'))

# define BUFF_SIZE TETRIMINO_SIZE * TETRIMINO_MAX_TOTAL

int g_num_tets;

typedef struct		s_tetrimino
{
	char		letter;
	int		x[4];
	int		y[4];
	int		width;
	int		height;
	struct s_tetrimino *next;
}			t_tetrimino;

void	ft_putstr_fd(char const *s, int fd);
size_t	ft_strlen(const char *s);
void	ft_memdel(void **ap);
void	ft_putstr(char const *s);
void 	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
size_t	ft_wordcount(const char *s, char c);
size_t	ft_wordlen(const char *s, char c);
char	**ft_strsplit(char const *s, char c);
void	ft_putchar(char c);

char 	**input_read(int fd);
t_tetrimino	*create_tetrimino(char **map);
char		**solve(t_tetrimino *tet);

#endif
