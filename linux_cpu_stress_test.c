// Author: William Selby
// Linux cpu stress test

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(){
    int i;
    time_t start_time, end_time;
    double cpu_time_used;
    
    start_time = time(NULL);
    for(i=0; i<100000; i++){
        system("cat /dev/urandom > /dev/null");
    }
    end_time = time(NULL);
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to execute stress test: %f\n", cpu_time_used);
    return 0;
}
