
#include "check_mate.h"

check_func	checkers[CHECKERS] = \
{
	check_pawn,
	check_rook,
	check_bishop,
	check_queen
};

int		main(int ac, char *av[])
{
	char	**s;
	int		i;
	int		j;
	int		k;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	s = &av[1];	
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'K')
			{
				k = 0;
				while (k < CHECKERS)
				{
					if (checkers[k](s, i, j) == 1)
					{
						write(1, SUCCESS, ft_strlen(SUCCESS));
						return (0);
					}
					k++;
				}
				write(1, FAILURE, ft_strlen(FAILURE));
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
