#include "ft_malloc.h"

void	*return_good_malloc(t_block *lst, size_t size)
{
	while (lst)
	{
		if (lst->free == 0 && lst->size >= size)
		{
			lst->free = 1;
			return (lst->ptr);
		}
		lst = lst->next;
	}
	printf("NEED TO REALLOCATE\n");
	return NULL;
}

void	*find_good_malloc(size_t size)
{
	if (size > TINY_SIZE) {
		printf("IN SMALL\n");
		return return_good_malloc(g_page.h_small_block, size);
	}
	printf("IN TINY\n");
	return return_good_malloc(g_page.h_tiny_block, size);
}
