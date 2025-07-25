#include "rush01.h"

static int	count_numbers(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
				count++;
		}
		i++;
	}
	return (count);
}

static void	fill_views(char *str, int *views_arr, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && count < (n * 4))
	{
		if (str[i] >= '1' && str[i] <= (n + '0'))
		{
			views_arr[count] = str[i] - '0';
			count++;
		}
		i++;
	}
}

int	parse_input(char *str, int **views, int *n)
{
	int	total_views;
	int	i;

	total_views = count_numbers(str);
	if (total_views == 0 || total_views % 4 != 0)
		return (0);
	*n = total_views / 4;
	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '1' && str[i] <= (*n + '0')) || str[i] == ' '))
			return (0);
		i++;
	}
	*views = (int *)malloc(sizeof(int) * total_views);
	if (!(*views))
		return (0);
	fill_views(str, *views, *n);
	return (1);
}

int	**create_grid(int n)
{
	int	**grid;
	int	i;

	grid = (int **)malloc(sizeof(int *) * n);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < n)
	{
		grid[i] = (int *)malloc(sizeof(int) * n);
		if (!grid[i])
		{
			free_grid(grid, i);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

void	free_grid(int **grid, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
