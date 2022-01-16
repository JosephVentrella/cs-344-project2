#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{
	char buf[2048];
	int fd;
	int count;
	if (argc == 1)
	{
		while(argc == 1){
			int fd = 0;
			count = read(fd, buf, sizeof buf);
			write(1, buf, count);
		}
	}
	else{
		for (int i = 1; i < argc; ++i)
		{
			fd = open(argv[i], O_RDONLY);
			if(fd < 0){
				perror(argv[i]);
				continue;
			}
			while(read(fd, &count, 1) == 1)
				write(1, &count, 1);
			close(fd);
		}
	}
	return 0;
}