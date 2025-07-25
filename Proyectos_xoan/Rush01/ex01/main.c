#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_solution(int **grid, int n)
{
	int	row;
	int	col;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			ft_putchar(grid[row][col] + '0');
			if (col < n - 1)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	**grid;
	int	*views;
	int	n;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (!parse_input(argv[1], &views, &n))
	{
		ft_putstr("Error\n");
		return (1);
	}
	grid = create_grid(n);
	if (!grid)
	{
		free(views);
		ft_putstr("Error\n");
		return (1);
	}
	if (!solve(grid, views, n))
		ft_putstr("Error\n");
	free(views);
	free_grid(grid, n);
	return (0);
}
