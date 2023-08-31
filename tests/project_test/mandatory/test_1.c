#include "../../tests.h"

int main()
{
	// arrange
	int fd;
	char expected_result[100];
	char *actual_result;

	fd = open("./tests/project_test/files/test_1.txt", O_RDONLY);

	printf("test_1.c attempt to read test_1.txt: ");

	// asserts

	// arbritrary line
	actual_result = get_next_line(fd);
	strlcpy(expected_result, "i love cats\n", sizeof expected_result);
	assert(strcmp(expected_result, actual_result) == 0);
	free(actual_result);

	// line empty
	actual_result = get_next_line(fd);
	strlcpy(expected_result, "\n", sizeof expected_result);
	assert(strcmp(expected_result, actual_result) == 0);
	free(actual_result);

	// arbritrary line
	actual_result = get_next_line(fd);
	strlcpy(expected_result, "follow me on github:\n", sizeof expected_result);
	assert(strcmp(expected_result, actual_result) == 0);
	free(actual_result);

	// arbitrary line
	actual_result = get_next_line(fd);
	strlcpy(expected_result, "https://github.com/alissonmarcs/\n", sizeof expected_result);
	assert(strcmp(expected_result, actual_result) == 0);
	free(actual_result);

	// empty line
	actual_result = get_next_line(fd);
	strlcpy(expected_result, "\n", sizeof expected_result);
	assert(strcmp(expected_result, actual_result) == 0);
	free(actual_result);

	// arbitrary line
	actual_result = get_next_line(fd);
	strlcpy(expected_result, "follow me on twitter: alissonmarcs\n", sizeof expected_result);
	assert(strcmp(expected_result, actual_result) == 0);
	free(actual_result);

	// line empty
	actual_result = get_next_line(fd);
	strlcpy(expected_result, "\n", sizeof expected_result);
	assert(strcmp(expected_result, actual_result) == 0);
	free(actual_result);

	// last line of tested file don't have '\n'
	actual_result = get_next_line(fd);
	strlcpy(expected_result, "youtube.com", sizeof expected_result);
	assert(strcmp(expected_result, actual_result) == 0);
	free(actual_result);

	// comming to an end of file, it shount return NULL
	actual_result = get_next_line(fd);
	assert(actual_result == NULL);
	free(actual_result);

	close(fd);

	printf("%sassertions passed%s\n", GREEN, RESET);

	return (0);
}
