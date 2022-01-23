#include "libft.h"

char    *ft_strjoin_gnl(char *s1, char *s2)
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