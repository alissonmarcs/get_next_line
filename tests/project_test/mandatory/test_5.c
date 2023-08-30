#include "../../tests.h"

int main()
{
	int fd;
	char *actual_result;

	fd = open("../files/test_5.txt", O_RDONLY);
	printf("test_5.c tries to read test_5.txt: ");

	actual_result = get_next_line(fd);
	assert(actual_result == NULL);

	free(actual_result);
	close(fd);
	printf("%sthe asertion passed\n\033[1;0m", GREEN);

	return (0);
}
