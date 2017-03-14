#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void critical_code_segment(FILE* fp){
	for(int i = 0; i < 100; ++i){
   		fprintf(fp, "2");
		fflush(fp);
		sleep(1);
	}
}

int main(void)
{
	FILE *fp;
	    if((fp=fopen("./Build/SharedFile.txt", "a")) == NULL) {
        perror("fopen: ");
        exit(EXIT_FAILURE);
    }
	critical_code_segment(fp);
	fclose(fp);
	return EXIT_SUCCESS;
}