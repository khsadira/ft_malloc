# include "ft_malloc.h"

static int initializer()
{
	void	*big_alloc;
	t_block	*new_block;
	size_t	current_size;

	if ((big_alloc = mmap(0, INIT_SIZE, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0)) == (void *)-1) {
		perror("mmap_failed");
		return EXIT_FAILURE;
	}

	current_size = 0;
	while (current_size < INIT_SIZE)
	{
		if (SIZE_BLOCK + TINY_SIZE + current_size > INIT_SIZE)
			return EXIT_SUCCESS;

		new_block = (t_block *)(big_alloc + (current_size));
		current_size += SIZE_BLOCK;

		new_block->size = TINY_SIZE;
		new_block->ptr = big_alloc + current_size;
		new_block->free = 0;

		new_block->prev = g_page.l_tiny_block;
		new_block->next = NULL;

		if (current_size == SIZE_BLOCK)
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
	return EXIT_SUCCESS;
}


static void	*create_big_malloc(size_t size)
{
	void	*big_alloc;
	t_block	*new_block;
	size_t	current_size;

	if ((big_alloc = mmap(0, SIZE_BLOCK + size, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0)) == (void *)-1) {
		perror("mmap_failed");
		return NULL;
	}

	current_size = 0;
	new_block = (t_block *)(big_alloc + (current_size));
	current_size += SIZE_BLOCK;

	new_block->size = size;
	new_block->ptr = big_alloc + current_size;
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
	printf("start big = %d\n", (int)new_block->ptr);
	return new_block->ptr;
}

void		*ft_malloc(size_t size)
{
	if (size > SMALL_SIZE)
		return create_big_malloc(size);
	if (!g_page.h_tiny_block)
		if ((initializer()))
			return NULL;
	return find_good_malloc(size);
}

