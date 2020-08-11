#include "../cublib.h"

int     ft_tolower(int c)
{
        if (c >= 'A' && c <= 'Z')
                return (c + 32);
        return (c);
}

int	nospacegetmapindex(char *str)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str && str[i])
	{
		if (iswall(str[i]) && iswall(str[i + 2]) && iswall(str[i + 3]))
			return (1);
		i++;
	}
	return (-1);
}

char *removes(char *str, t_var *var)
{
	int i = 0;

	while (str[i])
	{
		if (getmapindex(var) != -1)
		{
			if (str[i] == 'S')
				str[i] = '3';
			else if (str[i] == 'N')
				str[i] = '2';
			else if (str[i] == 'W')
				str[i] = '4';
			else if (str[i] == '2')
				str[i] = '6';
			else if (str[i] == 'E')
				str[i] = '5';
		}	
		i++;
	}
	return (str);
}

void    getparamfile(int fd, char **line, t_var *var)
{
    int ret;
	int i;
	char *to_free;
	char *str;

    ret = 0;
	i = 0;
    while ((ret = get_next_line(fd, line)) > 0)
	{	
			*line = removes(*line, var);
		var->paramfile = ft_strjoin(var->paramfile ? var->paramfile : "", *line);
		*line ? free(*line) : 0;
	}
}

int  ft_strcmp(char *str, char *str2)
{
    int i;

    i = 0;
    if (ft_strlen(str) != ft_strlen(str2))
        return (0);
    while (str[i])
    {
        if (str[i] == str2[i])
            i++;
        else
            return (0);
    }
    return (1);
}