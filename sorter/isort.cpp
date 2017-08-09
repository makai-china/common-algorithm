#include <iostream>
#include <cstdlib>

void isort(int a[], int n)
{
    for(int i = 1; i < n ; i ++) {
        int j = i;
        int tmp = a[j];
        while (j > 0 && tmp < a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = tmp;
    }
}
int main()
{
    int a[10] = {12, 5, 3, 0, 7, 9, 34, 23, 11, 13};
    isort(a, 10);
    for(int i = 0; i < 10; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}
