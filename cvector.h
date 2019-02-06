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

template<class T>
class cvector;

template<class T>
std::ostream& operator<<(std::ostream&, const cvector<T>&);

template<class T>
class cvector {
friend std::ostream& operator<< <T>(std::ostream&, const cvector<T>&);
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
    //void reserve(unsigned int);
    void resize(unsigned int);
    void push_back(const T&);
    T* pop_back();
    void swap(const T*, const T*);
    void erase(unsigned int);
    T* search(const T*) const;
    const T& operator[](unsigned int) const;
    bool operator==(const T&) const;
    bool operator!=(const T&) const;
    cvector<T> operator+(const cvector<T>&) const;
    class iterator {
    friend class cvector<T>;
    private:
        const T* pt;
        bool eov;
        iterator(T* =nullptr, bool =false);
    public:
        iterator();
        /*iterator operator++(int); //postfisso
        iterator operator--(int); //postfisso
        iterator& operator++(); //prefisso
        iterator& operator--(); //prefisso*/
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
    };
    iterator begin() const;
    iterator end() const;
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
    delete[] point;
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
T* cvector<T>::pop_back() {
    delete point[size--];
    size--;
}

template<class T>
void cvector<T>::swap(const T* p, const T* q) {
    T* temp=p;
    p=q;
    q=temp;
}

template<class T>
void cvector<T>::erase(unsigned int pos) {
    if(pos==size-1)
        pop_back();
    else {
        swap(point[pos],point[size-1]);
        pop_back();
    }
}

template<class T>
T* cvector<T>::search(const T* v) const {
    if(point) {
        for(unsigned int j=0; j<size; j++) {
            if(point[j]==v)
                return point[j];
        }
    }
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

template<class T>
cvector<T> cvector<T>::operator+(const cvector<T>& v) const {
    cvector w;
    unsigned int x=size+v.size;
    if(x) {
        w.point=new T[x];
        w.size=x;
        w.capacity=capacity+v.capacity;
        for(unsigned int j=0; j<size; ++j)
            w.point[j]=point[j];
        for(unsigned int j=0; j<v.size; ++j)
            w.point[size+j]=v.point[j];
    }
    return w;
}

template<class T>
cvector<T>::iterator::iterator(): pt(nullptr), eov(false) {}

template<class T>
bool cvector<T>::iterator::operator==(const iterator& it) const {
    return pt==it.pt;
}

template<class T>
bool cvector<T>::iterator::operator!=(const iterator& it) const {
    return pt!=it.pt;
}

template<class T>
typename cvector<T>::iterator cvector<T>::begin() const {
    return point[0];
}

template<class T>
typename cvector<T>::iterator cvector<T>::end() const {
    return point[size-1];
}

template<class T>
std::ostream& operator<<(std::ostream& os, const cvector<T>& v) {
    for(int j=0; j<v.getSize(); ++j)
        os << v[j] << ' ';
    return os;
}

#endif // cvector_H
