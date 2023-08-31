#include "../../tests.h"

int main()
{
	// arrange
	int fd;
	char *actual_result;

	fd = open("./tests/project_test/files/test_2.txt", O_RDONLY);
	printf("test_2.c attempt to read test_2.txt: ");

	// assert
	// file with single line and no '\n'
	actual_result = get_next_line(fd);
	assert(strcmp("hello world!", actual_result) == 0);

	free(actual_result);
	close(fd);
	printf("%sassertions passed%s\n", GREEN, RESET);

	return (0);
}
