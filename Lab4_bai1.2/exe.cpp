#include <pthread.h>
#include <cstdio>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#define THREADS 2

using namespace std;

void *computePi(void *param)
{
    int temp = *(int *)param;
    int *res_circle_point = (int *)malloc(sizeof(int));
    // *res_circle_point = 0;
    for (int i = 0; i < temp; i++)
    {
        double x = double(rand() % RAND_MAX) / RAND_MAX;
        double y = double(rand() % RAND_MAX) / RAND_MAX;
        double distance = x * x + y * y;
        if (distance <= 1){
            *res_circle_point = *res_circle_point + 1;
        }
        
    }
    return (void *) res_circle_point;
    pthread_exit(0);
    
}

int main(int argc, char *argv[])
{
    pthread_t threadIDS[THREADS];
    double pi;
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    int circle_points = 0;
    int point_per_thread = n / THREADS;

    for (int i = 0; i < THREADS; i++)
    {
        pthread_create(&threadIDS[i], NULL, &computePi, (void *)&point_per_thread);
    }

    for (int i = 0; i < THREADS; i++)
    {
        int *respone;
        pthread_join(threadIDS[i], (void **)&respone);
        circle_points += *respone;
    }

    pi = double(4 * circle_points) / n;
    cout << "Pi = " << pi;

    pthread_exit(NULL);
    return 0;
}