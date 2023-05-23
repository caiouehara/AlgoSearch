/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Bag
{ 
public:
    Bag(){
        size = 10;
        full = false;
        std::cout << "Ball created" << std::endl;
    }
    
    void insert(){};
    void remove(){};
    int occurrence(){};
    
    bool full;
    int size;
};

int main()
{
    Bag bag1;
}
