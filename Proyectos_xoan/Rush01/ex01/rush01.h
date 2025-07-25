#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

int		parse_input(char *str, int **views, int *n);
int		**create_grid(int n);
void	free_grid(int **grid, int n);

int		solve(int **grid, int *views, int n);

int		check_all_views(int **grid, int *views, int n);

void	print_solution(int **grid, int n);
void	ft_putstr(char *str);

#endif
