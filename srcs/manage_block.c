#include "ft_malloc.h"

void		*return_good_malloc(t_block *lst, size_t size)
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
	return (void *)-1;
}

void		*find_good_malloc(size_t size)
{
	void	*ret;

	ret = size > TINY_SIZE?return_good_malloc(g_page.h_small_block, size):return_good_malloc(g_page.h_tiny_block, size);
	if (ret == (void *)-1) {
		initialize_malloc();
		find_good_malloc(size);
	}
	return ret;
}

static int	add_tiny_blocks(void *big_alloc, size_t current_size, t_block *new_block)
{

	while (current_size < INIT_SIZE / 3)
	{
		if (SIZE_BLOCK + TINY_SIZE + current_size > INIT_SIZE / 3)
			return current_size;
		new_block = (t_block *)(big_alloc + (current_size));
		current_size += SIZE_BLOCK;
		new_block->size = TINY_SIZE;
		new_block->ptr = big_alloc + current_size;
		new_block->free = 0;
		new_block->prev = g_page.l_tiny_block;
		new_block->next = NULL;
		if (g_page.h_tiny_block == NULL)
		{
			g_page.h_tiny_block = new_block;
			g_page.l_tiny_block = new_block;
		}
		else {
			g_page.l_tiny_block->next = new_block;
			g_page.l_tiny_block = new_block;
		}
		current_size += TINY_SIZE + SIZE_BLOCK;
	}
	return current_size;
}

static int	add_small_blocks(void *big_alloc, size_t current_size, t_block *new_block)
{
	while (current_size < INIT_SIZE)
	{
		if (SIZE_BLOCK + SMALL_SIZE + current_size > INIT_SIZE)
			return current_size;
		new_block = (t_block *)(big_alloc + (current_size));
		current_size += SIZE_BLOCK;
		new_block->size = SMALL_SIZE;
		new_block->ptr = big_alloc + current_size;
		new_block->free = 0;
		new_block->prev = g_page.l_small_block;
		new_block->next = NULL;
		if (g_page.h_small_block == NULL) {
			g_page.h_small_block = new_block;
			g_page.l_small_block = new_block;
		}
		else {
			g_page.l_small_block->next = new_block;
			g_page.l_small_block = new_block;
		}
		current_size += SMALL_SIZE + SIZE_BLOCK;
	}
	return current_size;
}

int 		initialize_malloc()
{
	void	*big_alloc;
	size_t	current_size;
	t_block	*new_block;

	if ((big_alloc = mmap(0, INIT_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == (void *)-1) {
		perror("mmap_failed");
		return EXIT_FAILURE;
	}
	current_size = 0;
	current_size = add_tiny_blocks(big_alloc, current_size, new_block);
	add_small_blocks(big_alloc, current_size, new_block);
	return EXIT_SUCCESS;
}