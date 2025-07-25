#include "rush01.h"

// Prototipos de las funciones que usa 'main'
void	init_grid(int grid[4][4]);
int		parse_input(char *input_str, int views[16]);
void	print_solution(int grid[4][4]);
int		solve(int grid[4][4], int views[16], int pos);

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	views[16];

	// 1. Validar que el número de argumentos es correcto
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}

	// 2. Inicializar el tablero con ceros
	init_grid(grid);

	// 3. 'Parsear' la entrada y comprobar si es válida
	if (!parse_input(argv[1], views))
	{
		write(1, "Error\n", 6);
		return (0);
	}

	// 4. Intentar resolver el puzzle y, si hay éxito, imprimir la solución
	if (solve(grid, views, 0))
	{
		print_solution(grid);
	}
	else
	{
		// 5. Si no hay solución, imprimir Error
		write(1, "Error\n", 6);
	}
	return (0);
}

void	init_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	parse_input(char *input_str, int views[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input_str[i] != '\0' && count < 16)
	{
		if (input_str[i] >= '1' && input_str[i] <= '4')
		{
			views[count] = input_str[i] - '0';
			count++;
		}
		else if (input_str[i] != ' ')
		{
			return (0); // Carácter no válido
		}
		i++;
	}
	// Asegurarse de que se leyeron exactamente 16 números
	// y de que no hay caracteres extra al final
	if (count != 16 || input_str[i] != '\0')
	{
		return (0);
	}
	return (1);
}

void	print_solution(int grid[4][4])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 3)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		row++;
	}
}
