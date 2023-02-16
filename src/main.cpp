#include "../include/ft_container.hpp"

int main(int argc, char** argv) 
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	std::cout << CONTOUR << std::endl;
    std::cout << "result of " << TYPE << " containers" << std::endl;
	std::cout << CONTOUR << std::endl;
    test1_subject();
	std::cout << CONTOUR << std::endl;
	test2_vector();
	std::cout << CONTOUR << std::endl;
	test3_stack();
	std::cout << CONTOUR << std::endl;
	test4_map();
	std::cout << CONTOUR << std::endl;

    return (0);
}