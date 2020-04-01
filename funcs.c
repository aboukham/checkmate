
#include "check_mate.h"

int		check_pawn(char **s, int r, int c)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == PAWN)
			{
				if (r == i - 1 && (c == j - 1 || c == j + 1))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);	
}

int		check_rook(char **s, int r, int c)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == ROOK)
			{
				if (r == i && check_horizontal(s, r, c, j))
					return (1);
				if (c == j && check_vertical(s, c, r, i))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);	
}

int		check_queen(char **s, int r, int c)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == QUEEN)
			{
				if (r == i && check_horizontal(s, r, c, j))
					return (1);
				if (c == j && check_vertical(s, c, r, i))
					return (1);
				if (ft_abs((r - i) / (c - j)) == 1)
					if (check_diagonal(s, r, c, i, j) == 1)
						return (1);
			}
			j++;
		}
		i++;
	}
	return (0);	
}

int		check_bishop(char **s, int r, int c)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == BISHOP)
			{
				if (ft_abs((r - i) / (c - j)) == 1)
					if (check_diagonal(s, r, c, i, j) == 1)
						return (1);
			}
			j++;
		}
		i++;
	}
	return (0);	
}
