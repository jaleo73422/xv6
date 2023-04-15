#include "kernel/types.h"
#include "user/user.h"

int main() {
    char buffer[64];

    while(1) {
    	int n = read(0, buffer, sizeof(buffer) / sizeof(char));
    	
	if(n <= 0)  break;
        write(1, buffer, n);
    }
    exit(0);
}
