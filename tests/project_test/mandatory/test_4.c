#include "../../tests.h"

int main()
{
	int fd;
	char expected_result[100];
	char *actual_result;

	fd = open("./tests/project_test/files/test_4.txt", O_RDONLY);
	printf("test_4.c attempt to read test_4.txt: ");

	actual_result = get_next_line(fd);
	strlcpy(expected_result, "unit test!!\n", sizeof expected_result);
	assert(strcmp(expected_result, actual_result) == 0);
	free(actual_result);

	actual_result = get_next_line(fd);
	strlcpy(expected_result, "software engineer\n", sizeof expected_result);
	assert(strcmp(expected_result, actual_result) == 0);
	free(actual_result);

	actual_result = get_next_line(fd);
	assert(actual_result == NULL);
	free(actual_result);

	close(fd);
	printf("%sassertions passed%s\n", GREEN, RESET);

	return (0);
}
