#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{

    DynamicVector<int> obj;
    for (int i = 0; i < 100; ++i)
        {
            obj.push_back(i);
        }

    for (int i = 0; i < obj.getSize(); ++i)
    {
        std::cout << obj.getElement(i) << std::endl;
    }

    return 0;
}
