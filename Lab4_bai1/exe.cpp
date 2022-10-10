#include <iostream>
using namespace std;

double randomNumber(){
    return double(rand() % RAND_MAX) / RAND_MAX;
}

int main(){
    double x, y, pi, distance;
    int circle_points = 0, total_points = 0;
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        x = randomNumber();
        y = randomNumber();

        distance = x * x + y * y;
        if(distance <= 1)
            circle_points++;
    
        total_points++;
    
        
        
    }
    pi = double(4*circle_points) / total_points;
    cout << "Pi = " << pi;

    return 0;
}