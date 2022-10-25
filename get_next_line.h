#ifndef GET_NEXT_LINE_H
#   define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 8
#endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#include <stdio.h>


// #define BUFFER_SIZE 300

typedef struct s_gnl{
	 char	*str;
	//  char	*line;
	// char	*buf_tmp;

	// char	*tmp;
	// char	*buf;
	size_t	nbyte;
	// size_t cnt_read;
	// size_t	str_len;
	// size_t	len;
	int		fl;
	// int		cnt;

	// int		len;
	// int		str_len;
}	t_gnl;

char	*get_temp(char	*str);
char	*get_tmp(char *buf, char *tmp, t_gnl gnl);
char	*sub_newline(char *str);
char	*read_file(int fd, char *str, t_gnl gnl);
char	*get_next_line(int fd);
// char	*ft_strjoin(t_gnl gnl);
char	*ft_strjoin(char *s1, char *s2);
// int check_newline(t_gnl gnl);
char	*get_str(char *str, char *tmp);
size_t	check_newline(char *buf);
char	*get_tmp(char *buf, char *tmp, t_gnl gnl);
size_t	ft_strlen(const char *str);
char	*ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *str);
#endif