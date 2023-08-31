#include "../../tests.h"

int main()
{
	int fd1;
	int fd2;
	char *line_received;
	char line_expected[100];

	fd1 = open("./tests/project_test/files/test_1.txt", O_RDONLY);
	fd2 = open("./tests/project_test/files/test_2.txt", O_RDONLY);

	printf("test_1.c attempt to read test_1.txt and test_2.txt: ");

	line_received = get_next_line(fd1);
	strlcpy(line_expected, "i love cats\n", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd2);
	strlcpy(line_expected, "hello world!", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0); 
	free(line_received);

	line_received = get_next_line(fd1);
	strlcpy(line_expected, "\n", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd2);
	assert(line_received == NULL);
	free(line_received);

	line_received = get_next_line(fd1);
	strlcpy(line_expected, "follow me on github:\n", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd1);
	strlcpy(line_expected, "https://github.com/alissonmarcs/\n", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd1);
	strlcpy(line_expected, "\n", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd1);
	strlcpy(line_expected, "follow me on twitter: alissonmarcs\n", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd1);
	strlcpy(line_expected, "\n", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd1);
	strlcpy(line_expected, "youtube.com", sizeof line_expected);
	assert(strcmp(line_expected, line_received) == 0);
	free(line_received);

	line_received = get_next_line(fd1);
	assert(line_received == NULL);
	free(line_received);

	close(fd1);
	close(fd2);

	printf("%sassertions passed%s\n", GREEN, RESET);
}
