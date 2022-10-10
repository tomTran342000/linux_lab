#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(){
    pid_t pid_B, pid_C;
    pid_B = fork();
    if(pid_B == 0){
        sleep(5);
        cout << "This is process B with pid: " << getpid() << endl;;
        exit(0);
    }else{
        pid_C = fork();
        if(pid_C == 0){
            sleep(6);
            cout << "this is process C with pid: " << getpid() << endl;
            exit(0);
        }else{
            
            //wait(NULL);
            sleep(1);
            kill(pid_B, SIGTERM);
            kill(pid_C, SIGTERM);
            // waitpid(pid_B, NULL, 0);
            // waitpid(pid_C, NULL, 0);
            cout << "this is process A with pid: " << getpid() << endl;
            
        }
    }
    return 0;
}