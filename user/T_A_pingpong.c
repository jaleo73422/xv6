#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    int parent_fd[2];
    int child_fd[2];
    char buffer[100];

    pipe(parent_fd);
    pipe(child_fd);

    int pid = fork();
    
    if(pid == 0) {
        read(parent_fd[0], buffer, 4);
        printf("%d: received ping \n", getpid());
        close(parent_fd[0]);
        write(child_fd[1], "pong", 4);
        close(child_fd[1]);
    }
    else {
        write(parent_fd[1], "ping", 4);
        close(parent_fd[1]);
        read(child_fd[0], buffer, 4);
        close(child_fd[0]);
        printf("%d: received pong \n", getpid());
    }
    exit(0);
}
