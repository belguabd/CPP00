#include <iostream>

int main(int ac, char *av[])
{
	std::string args;

	if (ac != 1)
	{
		for (size_t i = 1; av[i]; i++)
		{
			args = av[i];
			for (size_t j = 0; args[j]; j++)
				args[j] = std::toupper(args[j]);
			std::cout << args;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	return 0;
}
