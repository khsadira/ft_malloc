# include "ft_malloc.h"

int main()
{
	char *tmp2;
	char *tmp;
	if (!(tmp = ft_malloc(PAGE_SIZE)) || !(tmp2 = ft_malloc(PAGE_SIZE/32 + -1)))
	{
		printf ("we got a null\n");
		return EXIT_FAILURE;
	}
	for (int i =0; i < 5; i++) {
		tmp2[i] = 'a' + i % 26;
		tmp[i] = 'e' + i%26;
	}
	for (int i =0; i < 120005; i ++) {
		tmp[i] = 'a'+i%26;
	}
	//printf("%s\n%s\n", tmp, tmp2);
	return EXIT_SUCCESS;
}