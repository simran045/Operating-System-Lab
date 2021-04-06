/* Registration No-2019CA15
   Name- Kumari Simran
   Program- 02) C Program to Simulate the ls Command in Linux Operating system */

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h> //header file that contains constructs that facilitate directory traversing
void main()
{
    char dirname[20];
    DIR*p;
    struct dirent *d; //returns a pointer to a dirent structure describing the next directory entry in the directory stream associated with dir
    printf("\n Enter directory name:");
    scanf("%s",dirname);
    p=opendir(dirname); //Opens a directory so that it can be read with readdir() 
    if(p==NULL)
    {
        perror("\n Cannot find the specified directory");
        exit(-1);
    }
    while(d=readdir(p))
    printf("\n%s\n",d->d_name);
}