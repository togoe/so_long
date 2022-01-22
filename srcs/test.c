# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#define BUFFER_SIZE 5

char **ft_split(char *stock, char c);
int     ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return(0);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    int     i;
    int     j;
    char    *str;

    if (!s1 && !s2[0])
        return (NULL);
    i = 0;
    j = 0;
    if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
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

int     rectangular_map(char **vars)
{
    int     len_ref;
    int     len;
    int     i;

    len_ref = ft_strlen(vars[0]);
    i = 0;
    while (vars[i])
    {
        len = ft_strlen(vars[i]);
        if (len != len_ref)
            return (0);
        i++;
    }
    printf ("%s\n", "map ok");
    return (i);
}

int     main()
{
    int     fd;
    int     ret;
    char    buf[BUFFER_SIZE + 1];
    char    *stock = NULL;
    char    **s_split = NULL;
    fd = open("test.txt", O_RDONLY);
    ret = read(fd, buf, BUFFER_SIZE);
    buf[ret] = '\0';
    //printf("avant boucle: %s\n", buf);
    while (ret != 0)
    {
        stock = ft_strjoin(stock, buf);
        //printf("stock dans boucle: %s\n", stock);
        ret = read(fd, buf, BUFFER_SIZE);
        buf[ret] = '\0';
        //printf("fin boucle buf:%s\n", buf);
    }
    close(fd);
    s_split = ft_split(stock, '\n');
    free(stock);
    int i = 0;
    while (s_split[i])
    {
        printf("%s %d\n", s_split[i], i);
        i++;
    }
    int nb_line;

    nb_line = rectangular_map(s_split);
    if (!nb_line)
        printf("%s\n", "map not good");
    
    printf("%d\n", nb_line);
}