#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem;
    if (std::cin >> currItem) {
        int cnt = 1;
        Sales_item newItem;
        while (std::cin >> newItem) {
            if (currItem.isbn() == newItem.isbn()) {
                ++cnt;
            } else {
                std::cout << currItem.isbn() << " sales "
                          << cnt << " copies." << std::endl;
                currItem = newItem;
                cnt = 1;
            }
        }
        std::cout << currItem.isbn() << " sales "
                  << cnt << " copies." << std::endl;
    }
    return 0;
}