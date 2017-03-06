//
//  individual task.cpp
//  individual task
//
//  Created by Артем on 25.02.17.
//  Copyright © 2017 Артем. All rights reserved.
//

#include <iostream>

int* AllocateMemory(int n);
void DisplayArray(int* a, int n);
void EnterArray(int* a, int n);
bool IsEven(int a);
void Swap(int& a, int& b);
void Swap(int *a, int *b);
int  ConvertAndCount(int numderconverte);
void BubbleSort(int *a, int n);
void DeleteElements1(int *a, int *p, int n, int& size);

using namespace std;

int main ()
{
    int n;
    int size = 0;
    while(true)
    {
        cout << "Please enter the size of massive" << endl;
        cin >> n;
        if(n>0)
            break;
        else
            cout << "Input error , please enter other nubmer";
        cin >> n;
    }
    int *a = AllocateMemory(n);
    EnterArray(a, n);
    cout << endl;
    DisplayArray(a,n);
    int* p =AllocateMemory(n);
    DeleteElements1(a, p, n, size);
    BubbleSort(a, n);
    cout << endl;
    DisplayArray(a,size);
    delete [] a;
    delete [] p;
    
    
    return 0;
}

int* AllocateMemory(int n)
{
    int* a = new int[n];
    
    return a;
}

void DisplayArray(int* a, int n)
{
    for (int* p = a; p < a + n; p++)
    {
        cout << " " << *p;
    }
}

void EnterArray(int* a, int n)
{
    for (int* p = a; p < a + n; p++)
    {
        *p = rand() % 10 - 5;
    }
}

void DeleteElement1(int *a, int *p, int n, int& size)
{
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i + 1] < 0) && (a[i] > 0) && (IsEven(a[i])))
        {
            p[size] = a[i + 1];
            size++;
            for(int j = i + 1; j < n - size; j++)
                a[j] = a[j + 1];
        }
    }
}



bool IsEven(int a)
{
    if (a % 2 == 0)
        return true;
    else
        return false;
}

void Swap(int *a, int *b)
{
    int* temp = a;
    a = b;
    b = temp;
}


void BubbleSort(int *a, int n)
{
    for (int *p=a; p < a+n; p++)
    {
        for (int *g = a+n-1; g >p; g--)
        {
            if (ConvertAndCount(*g)> ConvertAndCount(*(g -1)))
            {
                Swap(g, (g - 1));
                
            }
        }
    }
}

int ConvertAndCount(int convertednumber)
{
    int counter=0;
    int  remainder = convertednumber;
    int i = 0;
    int *dopmass = AllocateMemory(256);
    do
    {
       convertednumber /= 16;
        remainder %= 16;
        *(dopmass + i) = remainder;
        i++;
        remainder = convertednumber;
    } while (convertednumber > 16);
    for (int j = i; j > -1; j--)
    {
        if ((dopmass[j]>=10)&&(dopmass[j]<=16))
        counter++;
    }
    delete[] dopmass;
    return  counter;
}


