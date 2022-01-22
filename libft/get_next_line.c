#include "libft.h"

int     ft_strlen_gnl(char *str)
{
    int i;

    i = 0;
    if (!str)
        return(0);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin_gnl(char *s1, char *s2)
{
    int     i;
    int     j;
    char    *str;

    if (!s1 && !s2[0])
        return (NULL);
    i = 0;
    j = 0;
    if (!(str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1))))
    {
        free(s1);
        return (NULL);
    }
    while (s1 && s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    if (s1)
    {
        free(s1);
    }
    return (str);
}

int     ft_check_n(char *buf)
{
    int i;

    i = 0;
    while (buf && buf[i])
    {
        if (buf[i] == '\n')
            return (i + 1);
        i++;
    }
    return (0);
}

char    *ft_get_line(char *line)
{
    int     i;
    int     j;
    char    *str;

    i = ft_check_n(line);
    if (i == 0)
        return (line);
    j = 0;
    if (!(str = malloc(sizeof(char) * (i + 1))))
    {
        free(line);
        return (NULL);
    }
    while (j < i)
    {
        str[j] = line[j];
        j++;
    }
    str[j] = '\0';
    free(line);
    return (str);
}

void    get_new_buf(char *buf)
{
    int     i;
    int     j;

    j = 0;
    i = ft_check_n(buf);
    if (i <= 0)
    {
        while (buf[j])
        {
            buf[j] = '\0';
            j++;
        }
    }
    else
    {
        while (buf[i])
        {
        
            buf[j] = buf[i];
            j++;
            i++;
        }
        buf[j] = '\0';
    }
}

char    *get_next_line(int fd)
{
    char            *line = NULL;
    static char     buf[BUFFER_SIZE + 1];
    int             ret;
    
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    ret = 1;
    line = ft_strjoin_gnl(line, buf);
    while (ft_check_n(buf) == 0 && ret != 0)
    {
        ret = read(fd, buf, BUFFER_SIZE);
        if (ret < 0)
        {
            free(line);
            return (NULL);
        }
        buf[ret] = '\0';
        line = ft_strjoin_gnl(line, buf);
    }
    line = ft_get_line(line);
    get_new_buf(buf);
    return (line);
}