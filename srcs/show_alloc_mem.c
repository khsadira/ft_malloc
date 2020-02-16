#include "ft_malloc.h"

static long long int 	show_tiny_mem()
{
	long long int	total_size;
	t_block			*block;

	total_size = 0;
	if (g_page.tiny_region != NULL)
		printf("TINY: %#X\n", (int)g_page.tiny_region);
	block = g_page.tiny_region->head_block;
	while (block)
	{
		printf("%#X - %#X : %zu octets\n", (int) block->ptr, (int) block->ptr + (int) block->size, block->size);
		total_size += block->size;
		block = block->next;
	}
	return total_size;
}

static long long int	show_small_mem()
{
	long long int	total_size;
	t_block			*block;

	total_size = 0;
	if (g_page.small_region != NULL)
		printf("SMALL: %#X\n", (int)g_page.small_region);
	block = get_first_region_block(g_page.small_region);
	while ((block = find_next_allocated_block(block)))
	{
		printf("%#X - %#X : %zu octets\n", (int) block->ptr, (int) block->ptr + (int) block->size, block->size);
		total_size += block->size;
		block = block->next;
	}
	return total_size;
}

static long long int	show_large_mem()
{
	long long int	total_size;
	t_block			*block;

	total_size = 0;
	if (g_page.heavy_region != NULL)
		printf("HEAVY: %#X\n", (int)g_page.heavy_region);
	block = get_first_region_block(g_page.heavy_region);
	while ((block = find_next_allocated_block(block)))
	{
		printf("%#X - %#X : %zu octets\n", (int) block->ptr, (int) block->ptr + (int) block->size, block->size);
		total_size += block->size;
		block = block->next;
	}
	return total_size;
}

void 				show_alloc_mem()
{
	t_block	*block;
	long long int total_size;

	total_size = 0;
	total_size += show_tiny_mem();
	total_size += show_small_mem();
	total_size += show_large_mem();

	printf("Total : %zu\n", total_size);
}