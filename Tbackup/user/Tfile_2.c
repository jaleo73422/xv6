#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main() {
        int fd = open("Tfile_2.txt", O_WRONLY | O_CREATE);
        
	int w = write(fd, "123456789\n", 4);
	printf("%d %d \n", fd, w);
        exit(0);
}
