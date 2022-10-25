#include "get_next_line.h"

char	*sub_newline(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (check_newline(str) + 1));
	if (!line)
		return (NULL);
	while (str[i] != '\0')
	{
		line[i] = str[i];
		if (str[i] == '\n')
			break;
		i++;
	}
	line[i + 1] = 0;
	return (line);
}
char	*get_temp(char	*str)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	// if (!str)
	// {
	// 	return (NULL);
	// }
	// printf("str ---:|%s|\n\n", str);
	// printf("\nnl : %zu  len : %zu ", i, ft_strlen(str));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	i = check_newline(str);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tmp)
	{
		free (str);
		return (NULL);
	}
	j = 0;
	while (str[i] != 0)
	{
		tmp[j++] = str[i++];
	}
	tmp[j] = 0;
	// printf("len tmp : %zu\n", ft_strlen(tmp));
	// if (str)
	free(str);
	// printf("ft tmp : |%s| \n", tmp);
	return (tmp);
}
char	*read_file(int fd, char *tmp, t_gnl gnl)
{
		// char	*str;
		char	buf[BUFFER_SIZE + 1];
		char 	*str;

		gnl.nbyte = 1;
		while (gnl.nbyte)
		{
			gnl.nbyte = read(fd, buf, BUFFER_SIZE);
			buf[gnl.nbyte - 1] = 0;
			if (gnl.nbyte == 0 && tmp)
			{
				break;
			}
			if (gnl.nbyte <= 0)
			{
				
				free (tmp);
				return NULL;
			}
			str = (char *)malloc(sizeof(char) * (gnl.nbyte + 1));
			if (!str)
			{
				// free(tmp);
				return NULL;
			}
			str[gnl.nbyte] = 0;
			str = ft_strlcpy(str, buf, gnl.nbyte + 1);
			// printf("cpy tmp : |%s|\nbuf : |%s|\n", tmp, buf);
			tmp = ft_strjoin(tmp, str);
			// free(tmp);
			// printf("str : |%s|\n tmp : |%s| zu: %zu\n", str, tmp, check_newline(str));
			if (check_newline(tmp) != 0)
				break ;
		}
		// printf("---tmp 2 : %s\n", str);
		// printf("be str----|%s|\n\n", str);
		return (tmp);
}

char	*get_next_line(int fd)
{
	t_gnl gnl;
	// int		nl;
	char	*line;
	char	*str;
	static	char *tmp;

	gnl.fl = 1;

	// tmp = NULL;
	str = NULL;
	line = NULL;
	// line = malloc(sizeof(char) * 1);
	// line[0] = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// printf("\n be tmp : |%s| nbyt : %zu\n", tmp, gnl.nbyte);
	if (tmp && check_newline(tmp) != 0)
	{		
		// free(line);
		line = sub_newline(tmp);
		// printf("\nline : |%s|\n", line);
		tmp = get_temp(tmp);
		// printf("\ntmp : |%s|\n", tmp);
		// return (line);
		// printf("1----tmp----|%s|\n\n", tmp);
	}
	else
	{
		// printf("a----\n\n");
		// free(str);
		// if (tmp)
			str = read_file(fd, tmp, gnl);
			// printf("===|%s|===\n", str);
		// if (!tmp)
		// 	str = read_file(fd, str, gnl);
		// printf("---tmp 3 : %s\n", str);
		// printf("af str----|%s|\n\n", str);
		if (check_newline(str) != 0 || gnl.nbyte == 0)
		{
			
			// printf("str----|%s|\n\n", str);
			line = sub_newline(str);
			// printf("str----|%s|\n\n", str);
			if (check_newline(str) != 0)
				tmp = get_temp(str);
			else
				free(str);
			// printf("2----tmp----|%s|\n\n", tmp);	
		}
		
	}
	// if (!tmp)
	// 	free(tmp);
	
	

	// 	if (check_newline(buf) != 0)
	// 	{
	// 		tmp = get_tmp(buf, tmp, gnl);
	// 		i = -1;
	// 	}
	// 	if (i == 0)
	// 	{
	// 		line = ft_strjoin(tmp, buf);
	// 		free(tmp);
	// 	}
	// 	else
	// 	{
	// 		line = ft_strjoin(str, buf);
	// 		free(str);
	// 	}		
	// 	free(buf);
	// 	str = ft_strdup(line);
	// 	free(line);	
	// 	if (i == -1)
	// 		break;
	// 	i++;
	// }

	return (line);
}