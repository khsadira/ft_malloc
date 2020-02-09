# include "ft_malloc.h"

int main()
{
	char *tmp2;
	char *tmp;

	if ((tmp = ft_malloc(PAGE_SIZE / 31)) == NULL && (tmp2 = ft_malloc(PAGE_SIZE / 32 + -1)) == NULL)
	{
		printf ("we got a null\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < PAGE_SIZE/2; i++) {
		if (ft_malloc(PAGE_SIZE/33) == NULL)
			printf("we got stuck\n");
	}
	for (int i =0; i < 5; i++) {
		tmp2[i] = 'a' + i % 26;
		tmp[i] = 'e' + i % 26;
	}
	for (int i =0; i < PAGE_SIZE / 31; i ++) {
		tmp[i] = 'a' + i % 26;
	}
	return EXIT_SUCCESS;
}