#ifndef cvector_H
#define cvector_H
#include<iostream>
#include "pc_parts.h"
#include "moba.h"
#include "cpu.h"
#include "gpu.h"
#include "psu.h"
#include "ram.h"
#include "psu.h"
#include "storage.h"
#include <QDebug>

template<class T>
class cvector {
private:
    unsigned int capacity;
    unsigned int size;
    T* point;
    T* copy() const;
public:
    cvector(unsigned int =0, unsigned int =0, T* =nullptr);
    cvector(const cvector<T>&);
    cvector<T>& operator=(const cvector<T>&);
    ~cvector();
    bool empty() const;
    void clear();
    unsigned int getCapacity() const;
    unsigned int getSize() const;
    void resize(unsigned int);
    void push_back(const T&);
    void pop_back();
    void swap(T&, T&);
    void erase(const unsigned int &);
    int search(const T&) const;
    const T& operator[](unsigned int) const;
    bool operator==(const T&) const;
    bool operator!=(const T&) const;
};

template<class T>
T* cvector<T>::copy() const {
    T* v;
    if(!size)
        v=nullptr;
    else
        v=new T[capacity];
    for(unsigned int j=0; j<size; j++)
        v[j]=point[j];
    return v;
}

template<class T>
cvector<T>::cvector(unsigned int c, unsigned int s, T* p): capacity(c), size(s), point(p) {}

template<class T>
cvector<T>::cvector(const cvector<T>& v): capacity(v.capacity), size(v.size), point(v.copy()) {}

template<class T>
cvector<T>& cvector<T>::operator=(const cvector<T>& v) {
    if(this!=&v) {
        if(point)
            delete[] point;
        point=v.copy();
        size=v.size;
        capacity=v.capacity;
    }
    return *this;
}

template<class T>
cvector<T>::~cvector<T>() {
    if(point) {
        delete[] point;
    }
}

template<class T>
bool cvector<T>::empty() const {
    return size==0;
}

template<class T>
void cvector<T>::clear() {
    T* newPoint=nullptr;
    delete[] point;
    point=newPoint;
    capacity=0;
    size=0;
}

template<class T>
unsigned int cvector<T>::getCapacity() const {
    return capacity;
}

template<class T>
unsigned int cvector<T>::getSize() const {
    return size;
}

template<class T>
void cvector<T>::resize(unsigned int c) {
    T* newPoint=new T[c];
    for(unsigned int j=0; j<size; j++)
        newPoint[j]=point[j];
    delete[] point;
    point=newPoint;
}

template<class T>
const T& cvector<T>::operator[](unsigned int j) const {
    return point[j];
}

template<class T>
void cvector<T>::push_back(const T& v) {
    if(size>=capacity)
        resize(size+1);
    point[size]=v;
    ++size;
}

template<class T>
void cvector<T>::pop_back() {
    delete point[size-1];
    size--;
}

template<class T>
void cvector<T>::swap(T& p, T& q) {
    T temp(p);
    p=q;
    q=temp;
}

template<class T>
void cvector<T>::erase(const unsigned int &pos) {
    if(pos==size-1)
        pop_back();
    else {
        swap(point[pos],point[size-1]);
        pop_back();
    }
}

template<class T>
int cvector<T>::search(const T& v) const {
    if(point) {
        for(unsigned int j=0; j<size; ++j) {
            if(point[j]==v)
                return j;
        }
    }
    return -1;
}

template<class T>
bool cvector<T>::operator==(const T& v) const {
    if(size!=v.size)
        return false;
    for(unsigned int j=0; j<size; ++j) {
        if(point[j]!=v.point[j])
            return false;
    }
    return true;
}

template<class T>
bool cvector<T>::operator!=(const T& v) const {
    if(size!=v.size)
        return true;
    for(unsigned int j=0; j<size; ++j) {
        if(point[j]!=v.point[j])
            return true;
    }
    return false;
}

#endif // cvector_H
