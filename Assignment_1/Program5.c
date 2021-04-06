/* Registration no-2019CA15
   Name- Kumari Simran
   Program-05) C Program to change current working directory and display the inode details for each file in the new directory using the system calls: opendir( ),
   readdir( ), closedir( ), getcwd( ), chdir( ). */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    char dir[100],d[50];   
	printf("Present working Directory is : %s\n", getcwd(dir, 100)); 

	chdir(".."); 
 
	printf("Changed Directory is : %s\n", getcwd(dir, 100));

    if(argc==2)
    {
        bzero(d,sizeof(d));
        strcat(d,"ls ");
        strcat(d,"-i ");
        strcat(d,argv[1]);
        system(d);
    }
    else
    printf("\nInvalid No. of inputs");

    char buff[100];
    DIR *dp = NULL;
    struct dirent *dptr = NULL;
    // Buffer for storing the directory path
    memset(buff,0,sizeof(buff));

    //copy the path set by the user
    strcpy(buff,getcwd(dir, 100));

    // Open the directory stream
    if(NULL == (dp = opendir(getcwd(dir, 100)) ))
    {
        printf("\n Cannot open Input directory [%s]\n",getcwd(dir, 100));
        exit(1);
    }
    else
    {
        // Check if user supplied '/' at the end of directory name.
        // Based on it create a buffer containing path to new directory name 'newDir'
        if(buff[strlen(buff)-1]=='/')
        {
            strncpy(buff+strlen(buff),"newDir/",7);
        }
        else
        {
            strncpy(buff+strlen(buff),"/newDir/",8);
        }

        printf("\n Creating a new directory [%s]\n",buff);
        // create a new directory
        mkdir(buff,S_IRWXU|S_IRWXG|S_IRWXO);
        printf("\n The contents of directory [%s] are as follows \n",getcwd(dir, 100));
        // Read the directory contents
        while(NULL != (dptr = readdir(dp)) )
        {
            printf(" [%s] ",dptr->d_name);
        }
        // Close the directory stream
        closedir(dp);
        // Remove the new directory created by us
        rmdir(buff);
        printf("\n");
    }

    return 0;
}