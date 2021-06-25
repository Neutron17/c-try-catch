#include <stdio.h>
#include <errno.h>
#include "errHandler.h" 

int main(int argc, const char *argv[]) {
    try {
        FILE* fptr = fopen("nonExisting_file.txt", "rw");
        if(!fptr) {
            if(errno == ENOENT) /* ENOENT = No such file or directory */
                throw(FileNotFoundException);
            throw(IOException);
        }
        throw(Nothing);
    }catch(FileNotFoundException) {
        printf("FileNotFoundException\n");
        errorB();
    }catch(IOException) {
        printf("IOException\n");
        errorB();
    } else {
        printf("else\n");
        error();
    }entry;
}
