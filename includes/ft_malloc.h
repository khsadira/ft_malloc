#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<sys/mman.h>

# define 	PAGE_SIZE	getpagesize()
# define 	TINY_SIZE	PAGE_SIZE / 32
# define 	SMALL_SIZE	PAGE_SIZE
# define 	INIT_SIZE	64 * PAGE_SIZE
# define 	SIZE_BLOCK	sizeof(t_block)

typedef struct	s_block {
	size_t			size;
	int				free;
	void			*ptr;
	struct s_block	*next;
	struct s_block	*prev;
}				t_block;

typedef struct	s_page {
	t_block	*h_tiny_block;
	t_block	*l_tiny_block;
	t_block	*h_small_block;
	t_block	*l_small_block;
	t_block *h_big_block;
	t_block *l_big_block;
}				t_page;

t_page	g_page;

void	*ft_malloc(size_t size);
int 	initialize_malloc();
void	*find_good_malloc(size_t size);

void	ft_free(void *ptr);

#endif