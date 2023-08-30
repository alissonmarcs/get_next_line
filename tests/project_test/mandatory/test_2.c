#include "../../tests.h"

int main()
{
	// arrange
	int fd;
	char *actual_result;

	fd = open("../files/test_2.txt", O_RDONLY);
	printf("test_2.c tries to read test_2.txt: ");

	// assert
	// file with single line and no '\n'
	actual_result = get_next_line(fd);
	assert(strcmp("hello world!", actual_result) == 0);

	free(actual_result);
	close(fd);
	printf("%sall assertions passed\n\033[1;0m", GREEN);

	return (0);
}
