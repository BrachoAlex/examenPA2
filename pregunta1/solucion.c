#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE* myfile; 
    myfile = fopen("sayings.txt", "r"); 
    if (NULL == myfile) {
        printf("NOT FILE IN DIRECTORY \n");
        return 0;
    }
    char data[51][80];
        int i=0 ;
    while (fgets(data[i], 80, myfile) != NULL) {
        i++;
    }
        srand(getpid());
        int randNum = rand()%51;
        printf("%s",data[randNum]);        
    fclose(myfile);
    return 0;
}