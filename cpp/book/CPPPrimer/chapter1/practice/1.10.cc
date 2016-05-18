#include <iostream>

int main()
{
    int val = 10;
    std::cout << "The num from 10 to 0 is: ";
    while (val >= 0) {
        std::cout << val << " ";
        --val;
    }
    std::cout << std::endl;
    
    return 0;
}