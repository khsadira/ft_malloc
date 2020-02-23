#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<sys/mman.h>

# define 	PAGE_SIZE	getpagesize()

# define 	TINY_SIZE	PAGE_SIZE / 16
# define 	SMALL_SIZE	PAGE_SIZE * 40

# define 	INIT_SIZE	PAGE_SIZE * 4096

# define 	SIZE_BLOCK	sizeof(t_block)
# define	SIZE_TINY_REGION sizeof(t_tiny_region)
# define 	SIZE_SMALL_REGION sizeof(t_small_region)
# define 	SIZE_HEAVY_REGION sizeof(t_heavy_region)

# define 	TINY_REGION_SIZE 	TINY_SIZE * 800
# define 	SMALL_REGION_SIZE	SMALL_SIZE * 100

typedef struct	s_block {
	size_t			size;
	char 			free;
	void			*ptr;
	struct s_block	*next;
}				t_block;

typedef struct	s_tiny_region {
	struct s_tiny_region	*next_tiny_region;
	t_block					*head_block;
	t_block 				*next_block_free;
}				t_tiny_region;

typedef struct	s_small_region {
	struct s_small_region	*next_small_region;
	t_block					*head_block;
	t_block 				*next_block_free;
}				t_small_region;

typedef struct 	s_heavy_region {
	struct s_heavy_region	*next_heavy_region;
	t_block					*head_block;
	t_block 				*next_block_free;
}				t_heavy_region;

typedef struct	s_page {
	t_tiny_region	*tiny_region;
	t_small_region	*small_region;
	t_heavy_region	*heavy_region;
}				t_page;

t_page	g_page;

void	*ft_malloc(size_t size);
int		initialize();
void	show_alloc_mem();
void	*get_tiny_allocated_block(size_t size);
void	*get_small_allocated_block(size_t size);
void	*get_heavy_allocated_block(size_t size);
t_block *create_new_block(void *start_ptr, size_t size);

#endif