#include "src/dynamic_array_implementation.cpp"
#include <iostream>

using namespace std;

//You can test/use your code here.
int main()
{
    dynamic_array_implementation array;

    //Output should be 1
    
    array.append(1);
    cout<<array.get(0)<<"\n";
    cout<<array.get_capacity()<<"\n";
    array.append(2);
    cout<<array.get_capacity()<<"\n";
    array.append(3);
    cout<<array.get_capacity()<<"\n";
    array.append(4);
    cout<<array.get_capacity()<<"\n";
    array.append(5);
    array.append(6);
    array.append(7);
    array.append(8);
    cout<<array.get_capacity()<<"\n";
    array.append(9);
    cout<<array.get_capacity()<<"\n";
    array.append(10);
    array.append(11);
    array.append(12);
    array.append(13);
    array.append(14);
    array.pop();
    array.pop();
    array.pop();
    array.pop();
    array.pop();
    array.pop();
    array.pop();
    array.pop();
    array.pop();
    array.pop();
    cout<<array.get_capacity()<<"\n";
    cout<<array.get(3);

    

    return 0;
    
}