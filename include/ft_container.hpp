#ifndef FT_CONTAINER_HPP
# define FT_CONTAINER_HPP

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

# include <iostream>
# include <string>
# include <deque>
# include <stdlib.h>

# define MAX_RAM 4294967296
# define BUFFER_SIZE 4096
# define CONTOUR "-------------------------------------------------"

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

void    test1_subject(void);
void	test2_vector(void);
void	test3_stack(void);
void	test4_map(void);

#endif