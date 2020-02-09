# include "ft_malloc.h"

static void		*add_big_block(void *big_alloc, size_t size)
{
	t_block	*new_block;

	new_block = (t_block *)big_alloc;
	new_block->size = size;
	new_block->ptr = big_alloc + SIZE_BLOCK;
	new_block->free = 0;
	new_block->prev = g_page.l_big_block;
	new_block->next = NULL;

	if (g_page.h_big_block == NULL)
	{
		g_page.h_big_block = new_block;
		g_page.l_big_block = new_block;
	}
	else
	{
		g_page.l_big_block->next = new_block;
		g_page.l_big_block = new_block;
	}
	return new_block->ptr;
}

static void		*create_big_malloc(size_t size)
{
	void	*big_alloc;
	t_block	*new_block;

	if ((big_alloc = mmap(0, SIZE_BLOCK + size, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0)) == (void *)-1) {
		perror("mmap_failed");
		return NULL;
	}

	return add_big_block(big_alloc, size);
}

void		*ft_malloc(size_t size)
{
	if (size > SMALL_SIZE)
		return create_big_malloc(size);
	if (!g_page.h_tiny_block) {
		printf("JE GO INITIALIZE\n");
		if ((initialize_malloc()))
			return NULL;
	}
	return find_good_malloc(size);
}

