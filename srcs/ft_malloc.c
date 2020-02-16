# include "ft_malloc.h"

static void		*create_big_alloc(size_t size)
{
	void	*big_alloc;

	if ((big_alloc = mmap(0, size, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0)) == (void *)-1)
	{
		perror("mmap_failed");
		return NULL;
	}
	return big_alloc;
}

int		initialize()
{
	void				*big_alloc;

	if (!(big_alloc = create_big_alloc(INIT_SIZE)))
		return (1);
	g_page.tiny_region = big_alloc;
	g_page.small_region = big_alloc + TINY_REGION_SIZE;
	return (0);
}

void		*ft_malloc(size_t size)
{
	void	*ret;

	if (!g_page.tiny_region || !g_page.small_region)
		initialize();

	if (size < TINY_SIZE)
		ret = get_tiny_allocated_block(size);
	else if (size < SMALL_SIZE)
		ret = get_small_allocated_block(size);
	else
		ret = get_heavy_allocated_block(size);

	return ret;
}

