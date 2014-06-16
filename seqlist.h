#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>
#include <stdlib.h>

const int MaxListSize = 10;

template <class T>
class SeqList
{
private:
    T data[MaxListSize];
    int size;

public:
    SeqList(){ size = 0; }
    ~SeqList(){}
    int ListSize(){ return size; }
    bool ListEmpty()
    {
        if(0 == size)
            return true;
        else
            return false;
    }
    int Find(const T& item)
    {
        if(0 == size)
            return -1;

        int index = 0;
        while(index < size && item != data[index])
            ++index;
        if(index < size)
            return index;
        else
            return -1;

    }
    T GetData(int pos){ return data[pos]; }
    void Insert(const T& item, int pos)
    {
        if(size == MaxListSize)
        {
            std::cerr<<"the seqlist has already been full...";
            exit(1);
        }

        if(pos < 0 || pos > MaxListSize)
        {
            std::cerr<<"the pos is not right...";
            exit(1);
        }

        for(int i = MaxListSize; i < pos; --i)
            data[i] = data[i-1];

        data[pos] = item;
        ++size;
    }
    T Delete(int pos)
    {
        if(0 == size)
        {
            std::cerr<<"the seqlist has already been full...";
            exit(1);
        }

        if(pos < 0 || pos > size-1 )
        {
            std::cerr<<"the pos is not right...";
            exit(1);
        }

        T deleteVle = data[pos];
        for(int i=pos; i<size-1; ++i)
            data[i] = data[i+1];

        --size;

        return deleteVle;
    }
    void ClearList(){ size = 0; }
};

#endif // SEQLIST_H
