#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/file.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>

typedef struct{
    char name[4];
    int age;

}people;

int main(int argc, char *argv[])
{

    const char *path="/home/denny/code/linux/mmap/maptest";
    int fd, i;
    people *p_map;
    char name_t;

    fd = open(path, O_CREAT|O_RDWR|O_TRUNC, 00777);
    lseek(fd, sizeof(people)*5-1, SEEK_SET);
    write(fd, "", 1);
    
     /* 映射文件内容到本进程的地址空间 */
    p_map = mmap(NULL, sizeof(people)*10, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    
    name_t = 'a';
    for(i=0; i<10; i++)
    {
        /* 拷贝数据给mmap映射的地址空间 */
        name_t+=1;
        memcpy((*(p_map+i)).name, &name_t, 2);
        (*(p_map+i)).age=20+i;
    }

    printf("initializeover\n");
    sleep(10);

    munmap(p_map,sizeof(people)*10);
    printf("umap ok\n");

    return 0;
}
