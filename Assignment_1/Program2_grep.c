/* Registration no-2019CA15
   Name- Kumari Simran
   Program-02) C Program to Simulate grep Command in Linux */

#include<stdio.h>
#include<string.h>

void main(int argc , char *argv[])
{
               FILE *fp;
               char line[100];

              // initialsing the file pointer to read
              fp = fopen(argv[2],"r");
   
             // reading line by line and comparing each word in line
             while(fscanf(fp , "%[^\n]\n" , line)!=EOF)
            {
                      if(strstr(line , argv[1]) !=NULL)
                     {
                             // print that line
                             printf("%s\n" , line);
                      }
                     else
                    {
                            continue;
                    }
           }
            fclose(fp);
}