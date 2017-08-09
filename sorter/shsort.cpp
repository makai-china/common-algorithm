#include <iostream>
#include <cstdlib>

void shsort(int a[], int n)
{
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for( int i = gap; i < n; i += gap) {
            int tmp = a[i];
            int j = i;
            while(j > 0 && tmp < a[j-gap]) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = tmp;
        }
    }
}

int main()
{
    int a[10] = {1, 5, 3, 7, 13, 11, 76, 45, 33, 28};
    shsort(a, 10);
    for(int i = 0; i < 10; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}
