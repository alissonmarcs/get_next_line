#include "../../tests.h"

int main()
{
	int fd;
	char *actual_result;

	fd = open("./tests/project_test/files/test_5.txt", O_RDONLY);
	printf("test_5.c attempt to read test_5.txt: ");

	actual_result = get_next_line(fd);
	assert(actual_result == NULL);

	free(actual_result);
	close(fd);
	printf("%sassertions passed%s\n", GREEN, RESET);
	return (0);
}
