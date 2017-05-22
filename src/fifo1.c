#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int res = mkfifo("myfifo", 0777);

	if(res == 0)
		printf("fifo created.\n");
	exit(EXIT_SUCCESS);
}
