#include<iostream>
using namespace std;
void Insertion_Sort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int value = a[i];
        int j = i;
        while (a[j-1] > value && j > 0)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = value;
        
    }
}
int main()
{
    int n = 0;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    cin >> a[i];
    Insertion_Sort(a, n);
    for (int i = 0; i < n; i++)
    cout << a[i] << " ";
    delete[] a;
    return 0;
    
}
