#include <iostream>

int bsearch(int a[], int n, int key)
{
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if(a[mid] == key)
            return mid;
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int a[10] = {0, 3, 6, 9, 13, 16, 19, 23, 26, 28};
    int ret = bsearch(a, 10, 9);
    std::cout << "ret = " << ret << std::endl;
    ret = bsearch(a, 10, 22);
    std::cout << "ret = " << ret << std::endl;
    return 0;
}
