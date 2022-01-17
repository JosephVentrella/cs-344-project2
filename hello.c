#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x = 12;
	float y = 3.14;
	char s[] = "Hello World!\n";
	printf("x is %d, y is %f\n%s", x, y, s);
	for (int i = 0; i < 5; ++i)
	{
		printf("%d x 5 = %d\n", i, i * 5);
	}
	return 0;
}