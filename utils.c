
#include "check_mate.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (0);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		check_horizontal(char **s, int r, int c, int j)
{
	char	*p;	
	int		start;
	int		end;
	
	p = s[r];
	start = c > j ? j : c;
	end = c > j ? c : j;
	while (++start < end)
	{
		if (ft_strchr(PIECES, p[start]))
			return (0);
	}
	return (1);
}

int		check_vertical(char **s, int c, int r, int i)
{
	int		start;
	int		end;
	
	start = r > i ? i : r;
	end = r > i ? r : i;
	while (++start < end)
	{
		if (ft_strchr(PIECES, s[start][c]))
			return (0);
	}
	return (1);
}

int		ft_abs(int x)
{
	return (x < 0 ? -x : x);
}

void	line_equation(t_line *l, int r, int c, int i, int j)
{
	l->slope = ft_abs(((c - j) / (r - i)));
	l->delta = r - l->slope * c;
}

int		dot_product(int x1, int y1, int x2, int y2)
{
	return (x1 * x2 - y1 * y2);
}

int		check_diagonal(char **s, int r, int c, int i, int j)
{
	t_line	l;
	int		m;
	int		n;
	int		kac;
	int		kab;

	line_equation(&l, r, c, i, j);
	m = 0;
	while (s[m])
	{
		n = 0;
		while (s[m][n]) // A(n, m), B(c, r), C(j, i)
		{
			if (m == n * l.slope + l.delta)
			{
				kac = dot_product(c - n, r - m, j - n, i - m);
				kab = dot_product(c -n, r - m, c - n, r - m);
				if (kab > kac && kac > 0)
					if (ft_strchr(PIECES, s[m][n]))
						return (0);
			}
			n++;
		}
		m++;
	}
	return (1);
}
