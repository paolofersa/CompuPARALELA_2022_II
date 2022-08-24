#include <iostream>
#include <random>
#include <ctime>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void firstLoop(int arraySize, vector<int> &x, vector<int> &y, vector<vector<int>>& A) {
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
}

void secondLoop(int arraySize, vector<int>& x, vector<int>& y, vector<vector<int>>& A) {
    for (int j = 0; j < arraySize; j++)
    {
        for (int i = 0; i < arraySize; i++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    int sizeOfArrays;
    bool exitCondition = false;
    //MAIN LOOP FOR THE PROGRAM
    while (!exitCondition)
    {
        //MENU
        cout << "\t\tMESURE TIME OF CACHE\n";
        cout << "\t\t--------------------\n";
        cout << "Indicate the size of the array:\t";
        cin >> sizeOfArrays;

        //CREATING VECTORS
        vector<int> y(sizeOfArrays, 0);
        vector<int> x(sizeOfArrays, 0);
        vector<vector<int>> A(sizeOfArrays,(vector<int> (sizeOfArrays, 0)));

        //EVALUATE THE LOOPS
        unsigned tInicio, tFin, tInicio2, tFin2;
        tInicio = clock();              //start clock
        firstLoop(sizeOfArrays, x, y, A);
        tFin = clock();                 //end clock
        double tiempoOrdenamiento = (double(tFin - tInicio) / CLOCKS_PER_SEC);
        cout << "\nThe 1st algorithm took :\t" << tiempoOrdenamiento << " s to execute, with\t" << sizeOfArrays << " size." << endl;

        tInicio2 = clock();              //start clock
        secondLoop(sizeOfArrays, x, y, A);
        tFin2 = clock();                 //end clock
        double tiempoOrdenamiento2 = (double(tFin2 - tInicio2) / CLOCKS_PER_SEC);
        cout << "\nThe 2nd algorithm took :\t" << tiempoOrdenamiento2 << " s to execute, with\t" << sizeOfArrays << " size." << endl;        
        
        //REPEAT THE EXPERIMENT
        string optionForExperiment;
        cout << "Do you want to repeat the experiment?(Y/n)\n";
        cin >> optionForExperiment;
        exitCondition = (optionForExperiment == "Y" || optionForExperiment == "y") ? false : true;
    }
    return 0;
}