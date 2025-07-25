#include "rush01.h"

static int	count_visible(int *line, int n)
{
	int	i;
	int	max_h;
	int	visible;

	i = 0;
	max_h = 0;
	visible = 0;
	while (i < n)
	{
		if (line[i] > max_h)
		{
			max_h = line[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

static int	check_cols(int **grid, int *views, int n)
{
	int	i;
	int	j;
	int	*line;

	line = (int *)malloc(sizeof(int) * n);
	if (!line)
		return (0);
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			line[j] = grid[j][i];
		if (count_visible(line, n) != views[i])
			return (free(line), 0);
		j = -1;
		while (++j < n)
			line[j] = grid[n - 1 - j][i];
		if (count_visible(line, n) != views[n + i])
			return (free(line), 0);
	}
	free(line);
	return (1);
}

static int	check_rows(int **grid, int *views, int n)
{
	int	i;
	int	j;
	int	*line;

	line = (int *)malloc(sizeof(int) * n);
	if (!line)
		return (0);
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			line[j] = grid[i][j];
		if (count_visible(line, n) != views[2 * n + i])
			return (free(line), 0);
		j = -1;
		while (++j < n)
			line[j] = grid[i][n - 1 - j];
		if (count_visible(line, n) != views[3 * n + i])
			return (free(line), 0);
	}
	free(line);
	return (1);
}

int	check_all_views(int **grid, int *views, int n)
{
	if (!check_cols(grid, views, n))
		return (0);
	if (!check_rows(grid, views, n))
		return (0);
	return (1);
}
