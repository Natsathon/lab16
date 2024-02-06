#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *data, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << fixed << setprecision(2) << *(data + i * col + j) << " ";
        }
        cout << endl;
    }
}

void randData(double *data, int row, int col) {
    for (int i = 0; i < row * col; ++i) {
        *(data + i) = (rand() % 101) / 100.0;
    }
}

void findRowSum(const double *data, double *sum, int row, int col) {
    for (int i = 0; i < row; ++i) {
        *(sum + i) = 0;
        for (int j = 0; j < col; ++j) {
            *(sum + i) += *(data + i * col + j);
        }
    }
}

void findColSum(const double *data, double *sum, int row, int col) {
    for (int j = 0; j < col; ++j) {
        *(sum + j) = 0;
        for (int i = 0; i < row; ++i) {
            *(sum + j) += *(data + i * col + j);
        }
    }
}
