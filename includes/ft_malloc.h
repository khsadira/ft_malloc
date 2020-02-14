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
# define	SIZE_TINY_META size(t_tiny_metadata)
# define 	SIZE_SMALL_META sizeof(t_small_metadata)
# define 	SIZE_HEAVY_META sizeof(t_heavy_metadata)

# define 	TINY_REGION_SIZE 	TINY_SIZE * 800
# define 	SMALL_REGION_SIZE	SMALL_SIZE * 100

typedef struct	s_block {
	size_t			size;
	char 			free;
	void			*ptr;
	struct s_block	*next;
}				t_block;

typedef struct	s_tiny_metadata {
	s_block		next_tiny_metadata

}				t_tiny_metadata;

typedef struct	s_small_metadata {
}				t_small_metadata;

typedef struct 	s_heavy_metadata {
	*s_heavy_metadata
}				t_heavy_metadata;

typedef struct	s_page {
	t_tiny_metadata		tiny_metadata;
	t_small_metadata	small_metadata;
	t_heavy_metadata	heavy_metadata;
}				t_page;

t_page	g_page;


#endif