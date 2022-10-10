#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(){
    pid_t pid_B, pid_C, pid_D, pid_E, pid_F, pid_G;
    pid_B = fork();
    if(pid_B == 0) {
        sleep(5);
        cout << "Process B: " << getpid();
        exit(0);
    }else{
        pid_C = fork();
        if(pid_C == 0){
            sleep(10);
            cout << "Process C: " << getpid();
            pid_E = fork();
            if(pid_E == 0){
                sleep(20);
                cout << "Process E: " << getpid();
            }else{
                pid_F = fork();
                if(pid_F == 0){
                    sleep(25);
                    cout << "Process F: " << getpid();
                }else{
                    pid_G = fork();
                    if(pid_G == 0){
                        sleep(30);
                        cout << "Process G: " << getpid();
                    }
                }
            }
            exit(0);
          
        }else{
            pid_D = fork();
            if(pid_D == 0){
                sleep(15);
                cout << "Process D: " << getpid();
                exit(0);
            }else{
                cout << "Process A: " << getpid();
            }
        }
    }

    return 0;
}