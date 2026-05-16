#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *fptr;
    char buffer[255];

    fptr = fopen("teste.ext", "rb");
    if (fptr == NULL)
      return -2;

    fseek(fptr, 0, SEEK_END);
    long fileSize = ftell(fptr);
    rewind(fptr);

    char *fileContent = malloc(fileSize + 1);

    size_t bytesRead = fread(fileContent, 1, fileSize, fptr);
    fileContent[bytesRead] = '\0';
    // printf("read: %s", fileContent);

    fclose(fptr);

    printf("\n");
    
    const char delims[] = " ";
    char *token = strtok(fileContent, delims);

    while (token != NULL) {
      printf("token: %s\n", token);
      token = strtok(NULL, delims);
    }

    free(fileContent);
    return 0;
}
