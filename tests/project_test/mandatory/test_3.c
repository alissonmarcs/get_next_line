#include "../../tests.h"

int main()
{
	// arrange
	int fd;
	char *actual_result;

	fd = open("./tests/project_test/files/test_3.txt", O_RDONLY);
	printf("test_3.c attempt to read test_3.txt: ");

	// assert
	// first line of file with only '\n'
	actual_result = get_next_line(fd);
	assert(strcmp("\n", actual_result) == 0);
	free(actual_result);

	// we are in the end of file, must return NULL
	actual_result = get_next_line(fd);
	assert(actual_result == NULL);
	free(actual_result);

	close(fd);
	printf("%sassertions passed%s\n", GREEN, RESET);

	return (0);
}
