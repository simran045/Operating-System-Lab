/* Registration No- 2019CA15
   Name - Kumari Simran
   Program-03) C Write a program to implement
   1. Create a file
   2. Read contents of a file
   3. Write to a file
   4. Link and unlink a file
   5. Copy file
   6. Read contents of a file in a reverse order
  Using the system calls: open( ), close( ), read( ), write( ), lseek( ), link( ), unlink( ).*/

#include<stdio.h>
#include<string.h>
#include <unistd.h>  // for link and unlink


int main()
{
	//Create
	char fn[10],pat[10],temp[200];
	FILE *fp;
	
	//Copy
	FILE *f1,*f2;
	char fn1[100],fn2[100];

	//Read
	FILE *fpread;
        char fnread[100];

	//Write
	char sw='a';
        FILE *fwrite;
        char fnwrite[100];
	
	//Link and Unlink
	char path1[100];
        char path2[100];
	
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
	  case 1: printf("Enter file name to be created\n");
	          scanf("%s",fn);
	           fp=fopen(fn,"w");
	            fclose(fp);
		    break;
	case 2:
		printf("Enter file name to be Read\n");
        	scanf("%s",fnread);
	        fpread=fopen(fnread,"r");
	        char ch=fgetc(fpread);
	        while(ch != EOF)
	        {
	                printf("%c",ch);
	                ch=fgetc(fpread);
	        }
	        fclose(fpread);
		break;

	 case 3:
		printf("Enter file name\n");
                scanf("%s",fnwrite);
       		fwrite = fopen(fnwrite, "w");
       		int flag=1;
		if(fwrite == NULL)
       		{
       		   printf("Error!");
       		  // exit(1);
       		  flag=0;
       		}
		if(flag)
		{
       		       printf("Write Content (Write '#' and hit Enter to save):\n");
       	           	while(sw!='#')
       		         {
        	 	        sw=getchar();
        	        	fprintf(fwrite,"%c", sw);	
	       	         }
		}
	       	fclose(fwrite);
		break;
	 case 4: 
		printf("Enter file name along with the path\n");
	        scanf("%s",&path1);
	        printf("Enter directory name along with the path\n");
	        scanf("%s",&path2);
		printf("Enter l to link a file.\nEnter u to unlink a file\n : ");
		char clink;
		scanf("\n%c",&clink);

		if(clink=='L'||clink=='l')
		{
	           link (path1, path2); printf("File linked\n");
		}
		else if(clink=='u'||clink=='U')
		{
	            unlink(path1);  printf("File unlinked.\n");
		}
		else printf("Wrong Key Entered!");


		break;


	 case 5:
		 printf("Enter file name to be copied\n");
		scanf("%s",fn1);
		printf("Enter new file name\n");
		scanf("%s",fn2);
		
		f1=fopen(fn1,"r");
		f2=fopen(fn2,"w");
		
		char c=fgetc(f1);
		
		while(c != EOF)
		{
       		        fprintf(f2,"%c", c);
			c=fgetc(f1);
		}
		fclose(f1);
          	fclose(f2);
        	break;
		}

}
