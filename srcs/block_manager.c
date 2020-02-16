#include "ft_malloc.h"

void	*find_next_allocated_block(t_block *block)
{
	return block;
}

void	*get_first_region_block(void *region)
{
	return NULL;
}

t_block	*create_new_block(void *start_ptr, size_t size)
{
	t_block	*block;

	block = start_ptr;
	block->size = size;
	block->free = 0;
	block->ptr = block + SIZE_BLOCK;
	block->next = NULL;
	return block;
}

void	*get_tiny_allocated_block(size_t size)
{
	t_block		*block;

	block = g_page.tiny_region->head_block;
	if (block == NULL)
	{
		block = create_new_block(g_page.tiny_region + SIZE_TINY_REGION, size);
		g_page.tiny_region->head_block = block;
		block->free = 1;
		return block;
	}
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

void	*get_small_allocated_block(size_t size)
{
	return NULL;
}

void	*get_heavy_allocated_block(size_t size)
{
	return NULL;
}
