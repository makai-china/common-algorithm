#include <iostream>

void heapup(int a[], int ind)
{
    int j = (ind - 1) / 2;
    while(j >= 0) {
        if (a[j] > a[ind]) {
            std::swap(a[j], a[ind]);
            ind = j;
            j = (ind - 1) / 2;
        } else {
            return; // already done.
        }
    }
}

void heapdown(int a[], int ind, int n)
{
    int j = 2 * ind + 1;
    while(j < n) {
        if(j + 1 < n && a[j+1] < a[j])
            j++;
        if(a[j] < a[ind]) {
            std::swap(a[ind], a[j]);
            ind = j;
            j = 2 * ind + 1;
        } else {
            return; // already done.
        }
    }
}

void heapadd(int a[], int ind, int aNum)
{
    a[ind] = aNum;
    heapup(a, ind);
}

void heapdel(int a[], int n)
{
    std::swap(a[n-1], a[0]);
    heapdown(a, 0, n-1);
}

void makeheap(int a[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--) {
        heapdown(a, i, n);
    }
}

void heapsort(int a[], int n)
{
    makeheap(a, 10);
    for(int i = 0; i < n; i++) {
        heapdel(a, i);
    }
}

int main()
{
    int a[10] = {1, 5, 6, 12, 34, 23, 4, 55, 76, 8};
    heapsort(a, 10);
    for(int i = 0; i < 10; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}
