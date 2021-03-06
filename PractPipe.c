#include <stdio.h>
#include<unistd.h>

int main() {
    int pipefds[2];
    int returnstatus;
    int pid;
    char writemessages[2][20]={"Hi", "Hello"};
    char readmessage[20];
    returnstatus = pipe(pipefds);
    if (returnstatus == -1){
        printf("Unable to create pipe\n");
        return 1;
    }
    pid = fork();
    
    //child process
    if (pid > 0){
        read(pipefds[0], readmessage, sizeof(readmessage));
        printf("child Process - Reading from pipe - Message 2 is %s\n", readmessage);
    }
    else
    {
        //Parent Process
        printf("Parent Process - Writing to pipe - Message 1 is %s\n", writemessages[0]);
        write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
        printf("Parent Process - Writing to pipe - Message 2 is %s\n", writemessages[1]);
        write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
    }
    return 0;
    
}



//OUTPUT:

svkm@svkm2:~$ gcc PractPipe.c
svkm@svkm2:~$ ./a.out

Parent Process - Writing to pipe - Message 1 is Hi
Parent Process - Writing to pipe - Message 2 is Hello
child Process - Reading from pipe - Message 2 is Hi

svkm@svkm2:~$ 

