#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double max = A[0],min = A[0];
    double sum = 0;
    double sumHarmo = 0;
    double ruom = 1;
    for(int i = 0; i<N; i++){
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
        sumHarmo +=  1/A[i];
        sum += A[i];
        ruom*= A[i];
    }
    
    B[0] = sum/N;
    
    double sumsum = 0 ;
    for(int j = 0; j<N;j++){
      sumsum += pow((A[j]-B[0]),2);
    }
   

    B[1] = sqrt(sumsum/N);
    B[2] = pow(ruom,1.0/N);
    B[3] = N/sumHarmo;
    B[4] = max;
    B[5] = min;
}