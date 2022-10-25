#include "get_next_line.h"

char	*get_tmp(char *buf, char *tmp, t_gnl gnl)
{
	size_t	len;
	size_t	i;

	len = check_newline(buf);
	i = 0;
	tmp = (char *)malloc(sizeof(char) * (gnl.nbyte - len + 1));
	while (i < gnl.nbyte - len)
	{
		tmp[i] = buf[len + i];
		buf[len + i] = 0;
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

size_t check_newline(char *buf)
{
	size_t	len;

	if(!buf)
		return (0);
	len = 0;
	while (buf[len] != '\0')
	{
		if (buf[len] == '\n')
			return (len + 1);
		len++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *str)
{
	char	*new;
	int		index;

	new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	index = 0;
	while (str[index] != 0)
	{
		new[index] = str[index];
		index++;
	}
	new[index] = 0;
	return (new);
}

char	*ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize > 0)
	{
		while (dstsize >= 1 && src[index] != 0)
		{
			dst[index] = src[index];
			index++;
			dstsize--;
		}
		dst[index] = 0;
	}
	return (dst);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(&str[s1_len], s2, s2_len + 1);
	str[s1_len + s2_len] = 0;
	free(s1);
	free(s2);
	return (str);
}

// char	*ft_strjoin(char const *tmp, char const *buf, size_t buf_len, t_gnl gnl)
// {
// 	char	*str;

// 	if (!tmp && !buf)
// 		return (NULL);
// 	if (!tmp)
// 		return ((char *)buf);
// 	if (!buf)
// 		return ((char *)tmp);
// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	str = malloc(sizeof(char) * (gnl.str_len + gnl.buf_len +1));
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, tmp, gnl.str_len + 1);
// 	ft_strlcpy(&str[tmp_len], buf, gnl.buf_len + 1);
// 	return (str);
// }