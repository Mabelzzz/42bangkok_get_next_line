#include "get_next_line.h"

// #define Buffer_size 10

int	main(void)
{
	int	fd;
	// int rd;
	char *str;
	int	i;
	t_gnl gnl;

	// *str = NULL;
	fd = open("file.txt", O_RDONLY);
	// str = (char *)malloc(sizeof(char) * 7);
	// str = get_next_line(fd);
	i = 0;
	while (i < 9)
	{
		str = get_next_line(fd);
		printf("return %d ====> |%s|\n", i, str);
		// if (str)
		// 	free(str);
		i++;
	}
	// printf("%s", str);
	
	// rd = read(fd, str, 5);
    // printf("main : |%s|\n",get_str("", "Hel\nLoo\n plll"));

	// printf("sub nl : |%s|\n", sub_newline("0\nadsd\njhd"));
	// printf("get tmp : |%s|\n", get_temp("qui\nyiu\noiy\niuyt"));
	// printf("get tmp : |%s|\n", get_temp("quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\nExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."));

	// str = get_next_line(fd);
	// printf("-------------------------------main1 : |%s|\n", str);
	// free(str);

	// str = get_next_line(fd);
	// printf("-------------------------------main2 : |%s|\n", str);
	// free(str);

	// str = get_next_line(fd);
	// printf("-------------------------------main3 : |%s|\n", str);
	// free(str);

	// str = get_next_line(fd);
	// printf("-------------------------------main4 : |%s|\n", str);
	// free(str);

	// str = get_next_line(fd);
	// printf("-------------------------------main5 : |%s|\n", str);
	// free(str);

	// str = get_next_line(fd);
	// printf("-------------------------------main6 : |%s|\n", str);
	// free(str);

	// str = get_next_line(fd);
	// printf("-------------------------------main7 : |%s|\n", str);
	// free(str);

	// 	str = get_next_line(fd);
	// printf("-------------------------------main8 : |%s|\n", str);
	// rd = read(fd, str, 5);
	// printf("main : %s\n", get_next_line(fd));
	close(fd);
	return (0);
}

// #include "get_next_line.h"
// char *get_tmp(char *buf, char *tmp, t_gnl gnl)
// {
// 	size_t	i;

// 	i = 0;
// 	if (tmp)
// 		free(tmp);
// 	tmp = (char *)malloc(sizeof(char) * (gnl.nbyte - gnl.len + 1));
// 	// tmp[gnl.nbyte - gnl.len] = 0;
// 	while (i < gnl.nbyte - gnl.len)
// 	{
// 		tmp[i] = buf[gnl.len + i];
// 		buf[gnl.len + i] = 0;
// 		i++;
// 		printf("len+i : %zu\n", gnl.len + i);
// 	}
// 	tmp[i] = 0;
// 	return (tmp);
// }