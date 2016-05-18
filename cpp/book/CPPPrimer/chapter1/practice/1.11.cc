#include <iostream>

int main()
{
    int sum = 0, val1, val1Buf, val2;
    
    std::cout << "Input two number: ";
    std::cin >> val1 >> val2;
    val1Buf = val1;
    
    while (val1 <= val2) {
        sum += val1;
        ++val1;
    }
    std::cout << "Sum of " << val1Buf <<" to " << val2
              << " inclusive is " << sum << std::endl;
    return 0;
}