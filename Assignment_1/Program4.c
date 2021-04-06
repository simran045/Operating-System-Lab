/* Registration No-2019CA15
   Name- Kumari Simran
   Program-04) C program to determine the size of a file using the lseek command. Once you found out the size, calculate the number of blocks assigned for the file. Compare these results with the similar results obtained when using the function stat.*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int ac, char *av[]) {
    if ( ac < 2 ) 
        return 0;
    int fd = open(av[1],O_RDONLY);
    int size = lseek(fd, 0, SEEK_END);
    printf("size using lseek command: ");
        printf("%d\n", size);
    close(fd);
    
    printf("size using stat function: ");
    struct stat stbuf;
    stat( av[1], &stbuf);
    printf ("%ld\n", stbuf.st_size);
    printf("File system block size is = %ld\n", stbuf.st_blksize);
    return 0;
}