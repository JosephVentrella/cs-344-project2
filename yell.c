#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

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
			for (int i = 0; i < count; ++i)
			{
				buf[i] = toupper(buf[i]);
			}
			write(1, buf, count);
		}
	}
	else{
		for (int i = 1; i < argc; ++i)
		{
			fd = open(argv[i], O_RDWR);
			count = read(fd, buf, sizeof buf);
			if(fd < 0){
				perror(argv[i]);
			}
			for (int i = 0; i < count; ++i)
			{
				buf[i] = toupper(buf[i]);
			}
			write(1, buf, count);
			write(1, "\n", 1);
			close(fd);
		}
	}
	return 0;
}