#include <iostream>

int main(int ac, char *av[])
{
	if (ac != 1)
	{
		for (size_t i = 1; av[i]; i++)
		{
			for (size_t j = 0; av[i][j]; j++)
			{
				av[i][j] = std::toupper(av[i][j]);
			}
			std::cout << av[i];
		}
	}
}
