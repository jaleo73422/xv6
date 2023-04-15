#include "kernel/types.h"
#include "user/user.h"

int main() {
    int pid = 0;
    int status = 0;

    pid = fork();

    if(pid == 0) {
        char *argv[] = {"echo", "this", "is", "echo", 0};
        
	exec("echoooooo", argv);
        printf("exec failed! \n");
        exit(1);
    } else {
        printf("parent waiting \n");
        wait(&status);
        printf("this child exited with status %d \n", status);
    }

    exit(0);
    return 0;
}
