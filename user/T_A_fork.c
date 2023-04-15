#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
    int pid = fork();

    printf("fork() returned %d\n", pid);

    if(pid == 0)  printf("child\n");
    else  printf("parent\n");
    
    exit(0);
}
