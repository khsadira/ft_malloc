#include "ft_malloc.h"

static long long int 	show_tiny_mem()
{
	long long int	total_size;
	t_block			*block;

	total_size = 0;
	if (g_page.tiny_region != NULL)
	{
		printf("TINY: %#x\n", (int) g_page.tiny_region);
		block = g_page.tiny_region->head_block;
		printf("je suis al\n");
		while (block) {
			if (block->free == 1) {
				printf("%#x - %#x : %zu octets\n", (int) block->ptr, (int) block->ptr + (int) block->size, block->size);
				total_size += (long long int) block->size;
			}
			block = block->next;
		}
	}
	return total_size;
}

static long long int	show_small_mem()
{
	long long int	total_size;
	t_block			*block;

	total_size = 0;
	if (g_page.small_region != NULL)
	{
		printf("SMALL: %#x\n", (int) g_page.small_region);
		block = get_first_region_block(g_page.small_region);
		while (block) {
			if (block->free == 1) {
				printf("%#x - %#x : %zu octets\n", (int) block->ptr, (int) block->ptr + (int) block->size, block->size);
				total_size += (long long int) block->size;
			}
			block = block->next;
		}
	}
	return total_size;
}

static long long int	show_large_mem()
{
	long long int	total_size;
	t_block			*block;

	total_size = 0;
	if (g_page.heavy_region != NULL)
	{
		printf("HEAVY: %#x\n", (int) g_page.heavy_region);
		block = get_first_region_block(g_page.heavy_region);
		while (block) {
			if (block->free == 1) {
				printf("%#x - %#x : %zu octets\n", (int) block->ptr, (int) block->ptr + (int) block->size, block->size);
				total_size += (long long int) block->size;
			}
			block = block->next;
		}
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

	printf("Total : %lld\n", total_size);
}