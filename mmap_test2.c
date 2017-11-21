#include<sys/mman.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
typedef struct{
    char name[4];
        int age;
}people;

int main(int argc,char **argv)//map a normal file as shared mem:
{

    int fd,i;
    const char *path = "/home/denny/code/linux/mmap/maptest";
    people *p_map;

    fd=open(path,O_CREAT|O_RDWR,00777);
    /* 映射文件内容到本进程的地址空间 */
    p_map=(people*)mmap(NULL, sizeof(people)*10, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    for(i=0;i<10;i++)
    {
        //打印文件的内容
        printf("name:%s  age:%d;\n",(*(p_map+i)).name, (*(p_map+i)).age);

    }

    munmap(p_map,sizeof(people)*10);

    return 0;
}
