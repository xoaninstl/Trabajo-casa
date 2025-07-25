#include "rush01.h"

static int	is_safe(int **grid, int n, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (grid[row][i] == num)
			return (0);
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

static int	find_solution(int **grid, int *views, int n, int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == n * n)
	{
		if (check_all_views(grid, views, n))
		{
			print_solution(grid, n);
			return (1);
		}
		return (0);
	}
	row = pos / n;
	col = pos % n;
	num = 1;
	while (num <= n)
	{
		if (is_safe(grid, n, row, col, num))
		{
			grid[row][col] = num;
			if (find_solution(grid, views, n, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

static void	init_grid(int **grid, int n)
{
	int	row;
	int	col;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	solve(int **grid, int *views, int n)
{
	init_grid(grid, n);
	return (find_solution(grid, views, n, 0));
}
