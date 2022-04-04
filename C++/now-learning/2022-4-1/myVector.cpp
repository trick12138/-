#include <iostream>
#include <stdlib.h>
#include <initializer_list>

using namespace std;

template<class _Ty>
class myVector
{
public:
    myVector()
    {
        memory = nullptr;
        size = 0;
    }
    myVector(int size) :_size(size)
    {
        memory = new _Ty[size];
    }
    myVector(initializer_list<_Ty> data) :myVector(data.size())
    {
        int pos = 0;
        for (auto v : data)
        {
            memory[pos++] = v;
        }
    }
    void erase(int pos)
    {
        if (pos < 0 || pos > _size - 1)
            return;
        _Ty *posData = new _Ty[_size - 1];
        memcpy(posData,memory,sizeof(_Ty) * pos);
        memcpy(posData + pos,memory + pos + 1,sizeof(_Ty) * (_size - pos - 1));
        delete[] memory;
        memory = posData;
        --_size;
    }
    _Ty& operator[](int pos)
    {
        return memory[pos];
    }
    int size()
    {
        return _size;
    }
private:
    _Ty *memory;
    int _size;
};