#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	if ((char)c == '\0')
		return (0);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		x;
	int		y;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		dst[x] = s1[x];
		x++;
	}
	y = 0;
	while (s2[y] != '\0')
	{
		dst[x + y] = s2[y];
		y++;
	}
	dst[x + y] = '\0';
	free(s1);
	return (dst);
}

char *get_conteudo(int fd, char *conteudo)
{
    char *buff;
    int valueread;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buff == 0)
        return (NULL);
    valueread = 1;
    while(!ft_strchr(conteudo, '\n') && valueread != 0)
    {
        valueread = read(fd, buff, BUFFER_SIZE);
        if(valueread == -1)
            {
                free(buff);
                return(NULL);
            }
            buff[valueread] = '\0';
            conteudo = ft_strjoin(conteudo, buff);
    }
    free(buff);
    return (conteudo);
}

char *get_linha(char *conteudo)
{
    char *linha;
    int index;

    index = 0;
    while(conteudo[index] && conteudo[index] != '\n')
        index++;
    linha = (char *)malloc(sizeof(char) * (index + 2));
    index = 0;
    while(conteudo[index] && conteudo[index] != '\n')
    {
       linha[index] = conteudo[index];
       index++;
    }
    if(conteudo[index] == '\n')
    {
        linha[index] = conteudo[index];
        index++; 
    }
    linha[index] = '\0';
    return(linha);
}

char *get_next_line(int fd)
{
    static char *conteudo;
    char *linha;
    
    conteudo = get_conteudo(fd, conteudo);
    if (conteudo == 0)
        return(0);
    linha = get_linha(conteudo);
    free(conteudo);
    return(linha);
}

int main(void)
{
    char filedescriptor;
    char *str;

    filedescriptor = open("teste", 'r');
    str = get_next_line(filedescriptor);
    printf("str:%s", str);
    
    close(filedescriptor);
    return (0);
}
