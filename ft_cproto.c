

#include "gnl_orig/get_next_line.h"
#include "ft_fprintf/lprintf.h"


int	main(int argc, char **argv)
{
	int cfile;
	int output;
	char *line;
	char *linebef;
	
	cfile = open(argv[1], O_RDONLY);
	line = NULL;
	int i = 0;
	char *end;
	while (i < ft_atoi(argv[2]))
	{
	end = ft_strjoin(ft_strjoin(argv[1], ft_putnbr_base(i, DEC)), ".c");
	output = open(end, O_RDWR | O_APPEND | O_CREAT | O_TRUNC);
	ft_fprintf(output, "#include \"../cublib.h\"");
	i++;
	}
}
