#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>

void critical_code_segment(FILE* fp){
        for(int j = 0; j < 4; ++j){
            fprintf(fp, "1");
            fflush(fp);
            usleep(1);
        }
}

int main(void)
{
    FILE *fp;
    if((fp=fopen("./Build/SharedFile.txt", "a")) == NULL) {
        perror("fopen: ");
        exit(EXIT_FAILURE);
    }
    sem_t* sem = sem_open("TestSemaphore.sem",
                                      O_CREAT,
                                      S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH, //644
                                      1);
    if(sem == SEM_FAILED){
        perror("sem_open: ");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 10; ++i){
        sem_wait(sem);
        critical_code_segment(fp);
        sem_post(sem);
        usleep(700);
    }
    sem_close(sem);
    if(sem_unlink("TestSemaphore.sem") == -1 ){
        perror("sem_unlink: ");
    }
    fclose(fp);
    return EXIT_SUCCESS;
}
