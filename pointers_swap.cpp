//
//  Correct way to swap pointers
//

#include <iostream>

using namespace std;

void ptr_swap(int **, int **);

int main()
{
    int *ptr_a = new int(2);
    int *ptr_b = new int(5);

    cout << "a: " << ptr_a << ", b: " << ptr_b << endl;
    cout << "(a = " << *ptr_a << ", b = " << *ptr_b << ")\n";

    ptr_swap(&ptr_a, &ptr_b); cout << "\nswap\n\n";

    cout << "a: " << ptr_a << ", b: " << ptr_b << endl;
    cout << "(a = " << *ptr_a << ", b = " << *ptr_b << ")\n";

    return 0;
}

void ptr_swap(int **a, int **b)
{
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}
