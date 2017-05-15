//
//  main.cpp
//  individual task 2
//
//  Created by Артем on 03.04.17.
//  Copyright © 2017 Артем. All rights reserved.
//

#include <iostream>
#include <cmath>

double Cosx(double x, double eps);
double ** AllocateMemory(int n);
double CreateElement1(int i, int j, double eps);
double CreateElement2(int i, int j);
double** CreateSecondMatrix(int n, double eps);
double **CreateFirstMatrix(int n);
void DisplayArray(double* a, int n);
double Norm(double** matrix, int n);
void DisplayMatrix(double**matrix, int n);
void DeleteMemory(double** matrix, int n);

using namespace std;

int main() {
    int n;
    double eps;
    while (true)
    {
        cout << "Please enter the size of matrix :  ";
        cin >> n;
        if (n > 0) break;
    }
    
    while (true)
    {
        cout << "Please  enter the accuracy : ";
        cin >> eps;
        if (eps <= 0 && eps >= 1)
        {
            cout << " Input Error, please eneter the other accurancy : "<<endl;
        }
        else
            break;
    }
        double **matrix1 = CreateSecondMatrix(n, eps);
        cout << "Firts Matrix : "<<endl;
        DisplayMatrix(matrix1, n);
        cout << endl;
        
        double **matrix2 = CreateFirstMatrix(n);
        cout << "Secod Matrix : "<<endl;
        DisplayMatrix(matrix2, n);
        
        cout << "Norm of First Matrix : "<< Norm(matrix1, n) << endl;
        
        cout << "Norm of Second Matrix  : " << Norm(matrix2, n) << endl;
        
        DeleteMemory(matrix1, n);
        DeleteMemory(matrix2, n);
return 0;
}


double Cosx(double x, double eps) {
    
   double n = 1;
    double sum = 0;
    bool flag = true;
    int i = 1;
    while (flag)
    {
     if (fabs(x) < 2*M_PI)
     {
      while (fabs(n) > eps)
    {
        sum += n;
        n *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
        i++;
        
    }
         return sum;
     }
else
    x=x/2/M_PI;
    }
    return 0;
}

double** AllocateMemory(int n)
{
    double**matrix = new double*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[n];
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0;
    }
    return matrix;
}

void DeleteMemory(double** matrix, int n)
{
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete matrix;
}
double CreateElement1(int i, int j, double eps)
{
    if (i == j)
        return 1.0;
    else
        return (Cosx((double)(i + j), eps) - Cosx((double)(i - j), eps)) / pow((i + j + 1), 2);
}

double CreateElement2(int i, int j)
{
    if (i == j)
        return 1.0;
    else
        return (cos((double)(i + j)) - cos((double)(i - j))) / pow((i + j + 1), 2);
}

double **CreateFirstMatrix(int n)
{
    double** matrix = AllocateMemory(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = CreateElement2(i, j);
    return matrix;
}
double** CreateSecondMatrix(int n, double eps)
{
    double** matrix = AllocateMemory(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = CreateElement1(i, j, eps);
    return matrix;
}
double Norm(double** matrix, int n) {
    double max = 0.0;
     double sum = 0.0;
    int m = 1;
    for (int i = 0; i < n; i++)
    {
        while(m)
        {
            m = 0;
            for (int j = 0; j < n; j++)
                max += fabs(matrix[i][j]);
        }
        sum = 0.0;
    for (int j = 0; j < n; j++)
        sum += fabs(matrix[i][j]);
    if (max < sum)
        max = sum;
    }
    
    return max;
}

void DisplayArray(double* a, int n)
{
    for (double* p = a; p < a + n; p++)
    {
        cout << " " << *p;
    }
}

void DisplayMatrix(double**matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        DisplayArray(matrix[i], n);
        cout << endl;
    }
}
