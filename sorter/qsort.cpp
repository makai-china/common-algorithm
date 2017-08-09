#include <iostream>

void display(int a[], int n)
{
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

void qsort(int a[], int l, int h)
{
    if (l >= h) return;
    int low, high;
    low = l;
    high = h;

    int key = a[low];
    while(low < high) {
        while (low < high && a[high] > key)
            --high;
        if(low < high)
            a[low++] = a[high];

        while (low < high && a[low] < key)
            ++low;
        if(low < high)
            a[high--] = a[low];
    }
    a[low] = key;
    std::cout << "key=" << key << " low=" << low << std::endl;
    qsort(a, l, low-1);
    qsort(a, low+1, h);
}

int main()
{
    int a[10] = {4,2,4,6,8,2,8,9,23,10};
    display(a, 10);
    qsort(a, 0, 9);
    display(a, 10);
    return 0;
}
