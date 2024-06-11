#include <iostream>


template <typename T>
T add(T x, T y) {
    return x + y;
}

int main() {
    int x = add<int>(1, 2);
    int y = add<double>(57.123, 1231.33);

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    
    return 0;
}