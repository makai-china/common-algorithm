#include <iostream>
#include <cstdlib>

void bubsort(int a[], int n)
{
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(a[j+1] < a[j])
                std::swap(a[j+1], a[j]);
        }
    }
}

int main()
{
    int a[10] = {7, 4, 2, 11, 3, 76, 34, 23, 15, 44};
    bubsort(a, 10);
    for(int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
