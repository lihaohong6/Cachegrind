#include <iostream>

int main() {
    const int N = 1000000;
    int a[N];
    for (size_t i = 0; i < N; i++)
    {
       a[i] = i;
    }
    // prevent compiler optimization
    std::cout << "Number: " << a[rand() % N];
    return 0;
}
