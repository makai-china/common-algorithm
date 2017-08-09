#include <iostream>

void merge(int a[], int first, int mid, int last, int tmp[])
{
    int i = first, j = mid+1, k = 0;
    while (i <= mid && j <= last) {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i++ <= mid)
        tmp[k++] = a[i];

    while (j++ <=last)
        tmp[k++] = a[j];

    for(i = 0; i < k; i++)
        a[first+i] = tmp[i];
}

void mergesort(int a[], int l, int h, int tmp[])
{
    if (l < h) {
        int mid = l + ((h - l) >> 1);
        std::cout << "low = " << l << " high = " << h << " mid = " << mid << std::endl;
        mergesort(a, l, mid, tmp);
        mergesort(a, mid+1, h, tmp);
        merge(a, l, mid, h, tmp);
    }
}
int main()
{
    int a[10] = {3,4,2,8,6,9,11,34,3,2};
    int b[10] = {0};
    std::cout << "before:" << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    mergesort(a, 0, 9, b);
    std::cout << "end:" << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}
