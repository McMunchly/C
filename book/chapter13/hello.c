#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    
    if(argv[1] != NULL) {
        printf("Hello, %s\n", argv[1]);
    } else {
        printf("Name not specified\n");
    }
    return 0;
}