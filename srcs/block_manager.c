#include "ft_malloc.h"


t_block	*create_new_block(void *start_ptr, size_t size)
{
	t_block	*block;

	block = start_ptr;
	block->size = size;
	block->free = 0;
	block->ptr = start_ptr + SIZE_BLOCK;
	block->next = NULL;

	return block;
}

void	*assign_new_block(t_block *block, size_t size)
{
	while (block->next)
	{
		if (block->size >= size && block->free == 0)
		{
			block->free = 1;
			return block;
		}
		block = block->next;
	}
	if (block->size >= size && block->free == 0)
	{
		block->free = 1;
		return block;
	}

	block->next = create_new_block(block + SIZE_BLOCK + block->size, size);
	block->next->free = 1;
	return (block->next);
}

void	*get_tiny_allocated_block(size_t size)
{
	t_block		*block;

	if (g_page.tiny_region && !g_page.tiny_region->head_block)
	{
		block = create_new_block(g_page.tiny_region + SIZE_TINY_REGION, size);
		g_page.tiny_region->head_block = block;
		block->free = 1;
		return block;
	}

	return (assign_new_block(g_page.tiny_region->head_block, size));
}

void	*get_small_allocated_block(size_t size)
{
	t_block	*block;

	if (g_page.small_region && !g_page.small_region->head_block)
	{
		block = create_new_block(g_page.small_region + SIZE_SMALL_REGION, size);
		g_page.small_region->head_block = block;
		block->free = 1;
		return block;
	}


	return (assign_new_block(g_page.small_region->head_block, size));
}

void	*get_heavy_allocated_block(size_t size)
{
	t_block	*block;

	if (g_page.heavy_region && !g_page.heavy_region->head_block)
	{
		return NULL;
	}
	return NULL;
}
