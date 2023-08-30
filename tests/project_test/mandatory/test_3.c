#include "../../tests.h"

int main()
{
	// arrange
	int fd;
	char *actual_result;

	fd = open("../files/test_3.txt", O_RDONLY);
	printf("test_3.c tries to read test_3.txt: ");

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
	printf("%sall assertions passed\n\033[1;0m", GREEN);

	return (0);
}
