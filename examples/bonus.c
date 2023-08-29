#include "../get_next_line.h"

#include <fcntl.h> // to acess open()
#include <stdio.h>

int main()
{
	int file1;
	int file2;
	char *line;

	file1 = open("file1.txt", O_RDONLY);
	file2 = open("file2.txt", O_RDONLY);

	line = get_next_line(file1);
	printf("%s", line);
	free(line);

	line = get_next_line(file2);
	printf("%s", line);
	free(line);

	line = get_next_line(file1);
	printf("%s", line);
	free(line);

	close(file1);
	close(file2);
}
