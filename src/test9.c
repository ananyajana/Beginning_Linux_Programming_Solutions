#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

struct book
{
	char name[10];
	int pages;
};

int main()
{
	int wr_fd;
	struct book bk;

	bk.pages = 10;
	printf("enter the name of the book: ");
	scanf(" %s", &bk.name);

	wr_fd = open("a.txt", O_WRONLY | O_APPEND);
        write(wr_fd, &bk, sizeof(bk));
}	
