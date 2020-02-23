# include "ft_malloc.h"

int main() {
	ft_malloc(150);
	ft_malloc(25);
	ft_malloc(21);
	ft_malloc(TINY_SIZE - 5);
	ft_malloc(TINY_SIZE + 100);
	ft_malloc(TINY_SIZE + 100);
	ft_malloc(TINY_SIZE + 35300);

	show_alloc_mem();
	return EXIT_SUCCESS;
}