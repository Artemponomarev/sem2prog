#include <iostream>

int* AllocateMemory(int n);
void DisplayArray(int* a, int n);
void RandomArray(int* a, int n);
bool IfEven(int* p );
bool True(int n);

using namespace std;

int main (){
    int n = 12;
    int *a = AllocateMemory(n);
    DisplayArray(a,n);
    cout << endl;
    RandomArray(a,n);
    DisplayArray(a,n);
    
    delete [] a;
    
    
    return 0;
}


bool True(int n)
{
    if (n > 0)
        return true;
    else return false;
}


bool IfEven(int* p ){
    if (*p%2 == 0)
        return true;
    else
        return false;
}


int* AllocateMemory(int n)
{
    int* a = new int[n];
    
    //    for (int* p = a; p < a + n; p++)
    //    {
    //        *p = 0;
    //    }
    
    return a;
}


void DisplayArray(int* a, int n)
{
    for (int* p = a; p < a + n; p++)
    {
        cout << " " << *p;
    }
}


void RandomArray(int* a, int n)
{
    for (int* p = a; p < a + n; p++)
    {
        *p = rand() % 10;
    }
}

