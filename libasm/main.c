#include "libasm.h"
#include "libasm_bonus.h"
# include <stdio.h>
# include <string.h>
#define BUFFER 1000

int main(int argc, char **argv)
{
	int fd1;
	int fd2;
	char *str1 = "Hello world";
	char *str2 = "ABCDE";
	char *str3 = "12345";
	char *str4 = "libasm";
	char *str5 = "Hello worle";
	char *str6 = "ABCDe";
	char *str7 = "12344";
	char *str8 = "libasm";
	char s1[BUFFER];
	char s2[BUFFER];
	size_t byte1;
	size_t byte2;
	t_list *lst;

	if (argc > 2)
	{
		if (argc == 3 && !strcmp(argv[1], "ft_strlen"))
		{
			printf("   strlen - %zu\n", strlen(argv[2]));
			printf("ft_strlen - %zu\n", ft_strlen(argv[2]));
		}
		else if (argc == 3 && !strcmp(argv[1], "ft_strcpy"))
		{
			printf("   strcpy - %s\n", strcpy(s1, argv[2]));
			printf("ft_strcpy - %s\n", ft_strcpy(s2, argv[2]));
		}
		else if (argc == 4 && !strcmp(argv[1], "ft_strcmp"))
		{
			printf("   strcmp - %d\n", strcmp(argv[2], argv[3]));
			printf("ft_strcmp - %d\n", ft_strcmp(argv[2], argv[3]));
		}
		else if (argc == 3 && !strcmp(argv[1], "ft_strdup"))
		{
			printf("   strdup - %s\n", strdup(argv[2]));
			printf("ft_strdup - %s\n", ft_strdup(argv[2]));
		}
		else if (argc == 3 && !strcmp(argv[1], "ft_read"))
		{
			fd1 = open(argv[2], O_RDONLY);
			fd2 = open(argv[2], O_RDONLY);
			byte1 = read(fd1, s1, BUFFER);
			byte2 = ft_read(fd2, s2, BUFFER);
			printf("   read - %zu - %s\n", byte1, s1);
			printf("ft_read - %zu - %s\n", byte2, s2);
			close(fd1);
			close(fd2);
		}
		else if (argc == 3 && !strcmp(argv[1], "ft_write"))
		{
			write(STDOUT_FILENO, "   write - ", 11);
			byte1 = write(STDOUT_FILENO, argv[2], strlen(argv[2]));
			printf(" - %zu\n", byte1);
			write(STDOUT_FILENO, "ft_write - ", 11);
			byte2 = ft_write(STDOUT_FILENO, argv[2], strlen(argv[2]));
			printf(" - %zu\n", byte2);
		}
	}

	{
		printf("\n--------------------------ft_strlen--------------------------\n");
		printf("   strlen - %zu\n", strlen(str1));
		printf("ft_strlen - %zu\n", ft_strlen(str1));
		printf("   strlen - %zu\n", strlen(str2));
		printf("ft_strlen - %zu\n", ft_strlen(str2));
		printf("   strlen - %zu\n", strlen(str3));
		printf("ft_strlen - %zu\n", ft_strlen(str3));
		printf("   strlen - %zu\n", strlen(str4));
		printf("ft_strlen - %zu\n", ft_strlen(str4));
		printf("\n-------------------------------------------------------------\n");
	}

	{
		printf("\n--------------------------ft_strcpy--------------------------\n");
		printf("   strcpy - %s\n", strcpy(s1, str1));
		printf("ft_strcpy - %s\n", ft_strcpy(s1, str1));
		printf("   strcpy - %s\n", strcpy(s1, str2));
		printf("ft_strcpy - %s\n", ft_strcpy(s2, str2));
		printf("   strcpy - %s\n", strcpy(s1, str3));
		printf("ft_strcpy - %s\n", ft_strcpy(s2, str3));
		printf("   strcpy - %s\n", strcpy(s1, str4));
		printf("ft_strcpy - %s\n", ft_strcpy(s2, str4));
		printf("\n-------------------------------------------------------------\n");
	}
	{
		printf("\n--------------------------ft_strcmp--------------------------\n");
		printf("   strcmp - %d\n", strcmp("a", "b"));
		printf("ft_strcmp - %d\n", ft_strcmp("a", "b"));
		printf("   strcmp - %d\n", strcmp(str1, str5));
		printf("ft_strcmp - %d\n", ft_strcmp(str1, str5));
		printf("   strcmp - %d\n", strcmp(str2, str6));
		printf("ft_strcmp - %d\n", ft_strcmp(str2, str6));
		printf("   strcmp - %d\n", strcmp(str3, str7));
		printf("ft_strcmp - %d\n", ft_strcmp(str3, str7));
		printf("   strcmp - %d\n", strcmp(str4, str8));
		printf("ft_strcmp - %d\n", ft_strcmp(str4, str8));
		printf("\n-------------------------------------------------------------\n");
	}

	{
		printf("\n--------------------------ft_strdup--------------------------\n");
		printf("   strdup - %s\n", strdup(str1));
		printf("ft_strdup - %s\n", ft_strdup(str1));
		printf("   strdup - %s\n", strdup(str2));
		printf("ft_strdup - %s\n", ft_strdup(str2));
		printf("   strdup - %s\n", strdup(str3));
		printf("ft_strdup - %s\n", ft_strdup(str3));
		printf("   strdup - %s\n", strdup(str4));
		printf("ft_strdup - %s\n", ft_strdup(str4));
		printf("\n-------------------------------------------------------------\n");
	}

	{
		printf("\n---------------------------ft_read---------------------------\n");
		errno = 0;
		byte1 = read(42, s1, BUFFER);
		byte2 = ft_read(42, s2, BUFFER);
		printf("%s\n   read - %zu - errno - %d\n", s1, byte1, errno);
		printf("%s\nft_read - %zu - errno - %d\n", s2, byte2, errno);

		errno = 0;
		fd1 = open("files/alphabet", O_RDONLY);
		fd2 = open("files/alphabet", O_RDONLY);
		byte1 = read(fd1, s1, BUFFER);
		byte2 = ft_read(fd2, s2, BUFFER);
		printf("%s\n   read - %zu - errno - %d\n", s1, byte1, errno);
		printf("%s\nft_read - %zu - errno - %d\n", s2, byte2, errno);
		close(fd1);
		close(fd2);

		errno = 0;
		fd1 = open("files/marge", O_RDONLY);
		fd2 = open("files/marge", O_RDONLY);
		byte1 = read(fd1, s1, BUFFER);
		byte2 = ft_read(fd2, s2, BUFFER);
		printf("%s\n   read - %zu - errno - %d\n", s1, byte1, errno);
		printf("%s\nft_read - %zu - errno - %d\n", s2, byte2, errno);
		close(fd1);
		close(fd2);
		printf("\n-------------------------------------------------------------\n");
	}

	{
		printf("\n---------------------------ft_write--------------------------\n");
		errno = 0;
		write(STDOUT_FILENO, "   write - ", 11);
		byte1 = write(42, str1, strlen(str1));
		printf(" - %zu - errno - %d\n", byte1, errno);
		write(STDOUT_FILENO, "ft_write - ", 11);
		byte2 = ft_write(42, str1, strlen(str1));
		printf(" - %zu - errno - %d\n", byte2, errno);

		errno = 0;
		write(STDOUT_FILENO, "   write - ", 11);
		byte1 = write(STDOUT_FILENO, str2, strlen(str2));
		printf(" - %zu - errno - %d\n", byte1, errno);
		write(STDOUT_FILENO, "ft_write - ", 11);
		byte2 = ft_write(STDOUT_FILENO, str2, strlen(str2));
		printf(" - %zu - errno - %d\n", byte2, errno);

		errno = 0;
		write(STDOUT_FILENO, "   write - ", 11);
		byte1 = write(STDOUT_FILENO, str3, strlen(str3));
		printf(" - %zu - errno - %d\n", byte1, errno);
		write(STDOUT_FILENO, "ft_write - ", 11);
		byte2 = ft_write(STDOUT_FILENO, str3, strlen(str3));
		printf(" - %zu - errno - %d\n", byte2, errno);

		errno = 0;
		write(STDOUT_FILENO, "   write - ", 11);
		byte1 = write(STDOUT_FILENO, str4, strlen(str4));
		printf(" - %zu - errno - %d\n", byte1, errno);
		write(STDOUT_FILENO, "ft_write - ", 11);
		byte2 = ft_write(STDOUT_FILENO, str4, strlen(str4));
		printf(" - %zu - errno - %d\n", byte2, errno);
		printf("\n-------------------------------------------------------------\n");
	}
	{
		lst = malloc(sizeof(t_list));

		lst->data = ft_strdup("A");
		lst->next = malloc(sizeof(t_list));

		(lst->next)->data = ft_strdup("B");
		(lst->next)->next = malloc(sizeof(t_list));

		((lst->next)->next)->data = ft_strdup("C");
		((lst->next)->next)->next = NULL;


		ft_list_push_front(&lst, ft_strdup("3"));
		ft_list_push_front(&lst, ft_strdup("2"));
		ft_list_push_front(&lst, ft_strdup("1"));

		printf("%d\n", ft_list_size(lst));
		while (lst)
		{
			printf("%s\n", (char *)lst->data);
			lst = lst->next;
		}
	}
	return 0;
}
