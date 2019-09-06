#include "../include/dynamic_array.hpp"

using namespace std;

//Given just for reference. Only the class name and function names should match.
class dynamic_array_implementation : public dynamic_array
{
private:
    int size;
    int capacity;
    int *arr;
    double increase_factor;
    double decrease_factor;

public:
    dynamic_array_implementation();
    int get_size();
    int get_capacity();
    void set_increase_factor_table_size(double);
    void set_load_factor_reduction(double);
    void append(int);
    void pop();
    int get(int);
    ~dynamic_array_implementation();
};

//Constructor : To initialize all variables.
dynamic_array_implementation::dynamic_array_implementation()
{
    size = 0;
    capacity = 0;
    increase_factor = 2;
    decrease_factor = 0.25;
}


int dynamic_array_implementation::get_size()
{
    return size;
}
int dynamic_array_implementation::get_capacity()
{
    return capacity;
}

void dynamic_array_implementation::set_increase_factor_table_size(double increase_factor)
{
    capacity*=increase_factor;
    int *temp=(int*)malloc(sizeof(int)*capacity);
    //arr=(int*)realloc(arr,sizeof(int)*capacity);
    std::copy(arr,arr+size,temp);
    delete [] arr;
    arr=temp;
    return;
}
void dynamic_array_implementation::set_load_factor_reduction(double decrease_factor)
{
    capacity*=decrease_factor*increase_factor;
    int *temp=(int*)malloc(sizeof(int)*capacity);
    //arr=(int*)realloc(arr,sizeof(int)*capacity);
    std::copy(arr,arr+size,temp);
    delete [] arr;
    arr=temp;
    return;
}

void dynamic_array_implementation::append(int element)
{
    size+=1;
    if (capacity==0)
    {
        arr=(int*)malloc(1*sizeof(int));
        capacity++;
    }
    if (capacity < size)
    {
        set_increase_factor_table_size(increase_factor);
    }
    arr[get_size()-1]=element;
    return;
}

void dynamic_array_implementation::pop()
{
    size-=1;
    if ((capacity*decrease_factor)>=size)
    {
        set_load_factor_reduction(decrease_factor);
    }
    return;
}
int dynamic_array_implementation::get(int index)
{
    return (index<size)?arr[index]:-1;
}

dynamic_array_implementation::~dynamic_array_implementation()
{
    if (capacity > 0)
    {
        delete[] arr;
    }
}