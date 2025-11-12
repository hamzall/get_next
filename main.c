#include <stdio.h>
#include "get_next_line.h"





#include <fcntl.h>

int main()
{

    int fd = open("f", O_RDONLY);

    char *line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(10);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);


    return 0;
}