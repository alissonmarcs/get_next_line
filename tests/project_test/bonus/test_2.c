#include "../../tests.h"

int main()
{
	int fd1;
	int fd2;
	char *line_received;
	char line_expected[100];

	fd1 = open("./tests/project_test/files/test_3.txt", O_RDONLY);
	fd2 = open("./tests/project_test/files/test_4.txt", O_RDONLY);

	printf("test_2.c attempt to read test_3.txt and test_4.txt: ");

	line_received = get_next_line(fd1);
	strlcpy(line_expected, "\n", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd2);
	strlcpy(line_expected, "unit test!!\n", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd1);
	assert(line_received == NULL);
	free(line_received);

	line_received = get_next_line(fd2);
	strlcpy(line_expected, "software engineer\n", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd2);
	assert(line_received == NULL);
	free(line_received);

	close(fd1);
	close(fd2);

	printf("%sassertions passed%s\n", GREEN, RESET);
}
