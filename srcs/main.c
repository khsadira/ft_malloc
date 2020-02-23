# include "ft_malloc.h"

int main() {
	char *str = ft_malloc(150);
	char *str2 = ft_malloc(25);
	char *str3 = ft_malloc(21);
	char *str4 = ft_malloc(TINY_SIZE - 5);
	char *str5 = ft_malloc(TINY_SIZE + 100);
	char *str6 = ft_malloc(TINY_SIZE + 1252);
	char *str7 = ft_malloc(TINY_SIZE + 35300);
	char *str8 = ft_malloc(SMALL_SIZE + 30000);

	show_alloc_mem();
	int i = 0;
	while (i < 150) {
		str[i] = 'a' + i % 25;
		i++;
	}
	str[i] = 0;

	i = 0;
	while (i < 25) {
		str2[i] = 'a' + i % 25;
		i++;
	}
	str2[i] = 0;

	i = 0;
	while (i < 21) {
		str3[i] = 'a' + i % 25;
		i++;
	}
	str3[i] = 0;

	i = 0;
	while (i < TINY_SIZE - 5) {
		str4[i] = 'a' + i % 25;
		i++;
	}
	str4[i] = 0;

	i = 0;
	while (i < TINY_SIZE + 100) {
		str5[i] = 'a' + i % 25;
		i++;
	}
	str5[i] = 0;

	i = 0;
	while (i < TINY_SIZE + 1252) {
		str6[i] = 'a' + i % 25;
		i++;
	}
	str6[i] = 0;


	i = 0;
	while (i < TINY_SIZE + 35300) {
		str7[i] = 'a' + i % 25;
		i++;
	}
	str7[i] = 0;


	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", str, str2, str3, str4, str5, str6, str7, str8);
	return EXIT_SUCCESS;
}