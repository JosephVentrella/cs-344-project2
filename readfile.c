#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	char buf[2048];
	int fd = open(argv[1], O_RDWR);
	int count;
	count = read(fd, buf, sizeof buf);
	write(1, buf, count);
	close(fd);
	write(1, "\n", 1);

	return 0;
}