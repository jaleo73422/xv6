#include "kernel/types.h"
#include "user/user.h"

int main() {
	char *argv[3];
	argv[0] = "echo";
	argv[1] = "hello";
	argv[2] = 0;
	exec("echo", argv);
	printf("exec error\n");
	exit(0);
}
