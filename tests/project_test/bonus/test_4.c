#include "../../tests.h"

int main()
{
	int fd1;
	char *line_received;

	fd1 = open("./tests/project_test/files/test_5.txt", O_RDONLY);
	
	printf("test_4.c attempt to read test_5.txt: ");

	line_received = get_next_line(fd1);
	assert(line_received == NULL);

	printf("%sthe assertion passed%s\n", GREEN, RESET);
	close(fd1);
}
