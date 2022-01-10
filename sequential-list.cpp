#include "sequential-list.h"
#include <iostream>

SequentialList::SequentialList(unsigned int cap)
{
    capacity_ = cap;
    size_ = 0;

    data_ = new DataType[cap];

}

SequentialList::~SequentialList()
{
    delete [] data_;
    //return NULL;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    if (size() == 0)
        return true;
    return false;
}

bool SequentialList::full() const
{
    if (capacity() == size())
        return true;
    return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if (index >= size_)
        return data_[size_ - 1];
    return data_[index];

}

unsigned int SequentialList::search(DataType val) const
{
    for (int i = 0; i < size_; i++){
        if (data_[i] == val)
            return i;
    }
    return size_;

}

void SequentialList::print() const
{
    for (int i = 0; i < size_; i++){
        std::cout << data_[i] << "  ";
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (full() || index > size_)
        return false;
    for (int j = size_; j > index; j--) {
        data_[j] = data_[j - 1];
    }
    data_[index] = val;
    size_++;
    return true;
}

bool SequentialList::insert_front(DataType val)
{
    if (full())
        return false;
    if (size_ != 0) {
        for (int j = size_; j > 0; j--) {
            data_[j] = data_[j - 1];
        }
    }
    data_[0] = val;
    size_++;
    return true;
}

bool SequentialList::insert_back(DataType val)
{
    if (full())
        return false;
    data_[size_] = val;
    size_++;
    return true;
}

bool SequentialList::remove(unsigned int index)
{
    if (index > size_ || size_==0)
        return false;
    for (int j = index; j < size_; j++) {
        data_[j] = data_[j + 1];
    }
    size_--;
    return true;
}

bool SequentialList::remove_front()
{
    if (size_== 0)
        return false;
    for (int i = 0, j = size_; i < j; i++){
        data_[i] = data_[i+1];
    }
    size_--;
    return true;
}

bool SequentialList::remove_back()
{
    if (size_== 0)
        return false;
    size_--;
    return true;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (size_== 0)
        return false;
    data_[index] = val;
    return true;
}

