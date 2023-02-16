#include "../include/ft_container.hpp"

#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
    #define TYPE "std"
#else
	#include "../include/map.hpp"
	#include "../include/stack.hpp"
	#include "../include/vector.hpp"
    #define TYPE "ft"
#endif

template<typename T>
class MutantStack : public ft::stack<T>
{
    public:
        MutantStack() {}
        MutantStack(const MutantStack<T>& src) { *this = src; }
        MutantStack<T>& operator=(const MutantStack<T>& rhs) 
        {
            this->c = rhs.c;
            return *this;
        }
        ~MutantStack() {}

        typedef typename ft::stack<T>::container_type::iterator iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
};

void    test1_subject(void)
{
    //=================================================================//
	std::cout << T_GRY << "basic: construction" << T_DFT << std::endl;
	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	//=================================================================//
	std::cout <<  T_GRY << "vector (1): push_back" << T_DFT << std::endl;
	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}

	std::cout << T_GRY << "vector (2): swap" << T_DFT << std::endl;
	ft::vector<Buffer>().swap(vector_buffer);

	std::cout << T_GRY << "vector (3): at" << T_DFT << std::endl;
	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	//=================================================================//
	std::cout <<  T_GRY << "map (1): insert" << T_DFT << std::endl;
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	std::cout <<  T_GRY << "map (2): access" << T_DFT << std::endl;
	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}

	//=================================================================//
	std::cout << T_GRY << "stack (1): push" << T_DFT << std::endl;
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);

	std::cout << T_GRY << "stack (2): iterator" << T_DFT << std::endl;
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
}

