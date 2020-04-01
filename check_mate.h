
#ifndef CHECK_MATE_H
#define CHECK_MATE_H

#include <unistd.h>
#define SUCCESS		("Success\n")
#define FAILURE		("Fail\n")
#define	PIECES		("PRBQ")
#define CHECKERS	(4)
#define PAWN		('P')
#define ROOK		('R')
#define BISHOP		('B')
#define QUEEN		('Q')


typedef struct	s_line
{
	int			slope;
	int			delta;
}				t_line;

typedef int	(*check_func)(char **, int, int);

int		check_pawn(char **, int, int);
int		check_rook(char **, int, int);
int		check_bishop(char **, int, int);
int		check_queen(char **, int, int);


int		check_horizontal(char **s, int r, int c, int j);
int		check_vertical(char **s, int c, int r, int i);
int		check_diagonal(char **s, int r, int c, int i, int j);

int		ft_abs(int x);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *s);

#endif
