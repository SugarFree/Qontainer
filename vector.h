#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>

template<class T>
class vector;

template<class T>
std::ostream& operator<<(std::ostream&, const vector<T>&);

template<class T>
class vector {
friend std::ostream& operator<< <T>(std::ostream&, const vector<T>&);
private:
    unsigned int capacity;
    unsigned int size;
    T* point;
    T* copy() const;
public:
    vector(unsigned int =0, unsigned int =0, const T* =nullptr);
    vector(const vector<T>&);
    vector<T>& operator=(const vector<T>&);
    ~vector();
    bool empty() const;
    void clear();
    unsigned int getCapacity() const;
    unsigned int getSize() const;
    /*void reserve(unsigned int);*/
    void resize(unsigned int);
    void push_back(const T&);
    void pop_back();
    T* search(const T*) const;
    T& operator[](unsigned int) const;
    bool operator==(const T&) const;
    bool operator!=(const T&) const;
    vector<T> operator+(const vector<T>&) const;
    class iterator {
    friend class vector<T>;
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
T* vector<T>::copy() const {
    T* v;
    if(!size)
        v=nullptr;
    else
        v=new T*[capacity];
    for(unsigned int j=0; j<size; j++)
        v[j]=point[j];
    return v;
}

template<class T>
vector<T>::vector(unsigned int c, unsigned int s, const T* p): capacity(c), size(s), point(p) {}

template<class T>
vector<T>::vector(const vector<T>& v): capacity(v.capacity), size(v.size), point(v.copy()) {}

template<class T>
vector<T>& vector<T>::operator=(const vector<T>& v) {
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
vector<T>::~vector<T>() {
    if(point)
        delete[] point;
}

template<class T>
bool vector<T>::empty() const {
    return size==0;
}

template<class T>
void vector<T>::clear() {
    for(unsigned int j=0; j<size; j++)
        delete[] point;
    capacity=0;
    size=0;
}

template<class T>
unsigned int vector<T>::getCapacity() const {
    return capacity;
}

template<class T>
unsigned int vector<T>::getSize() const {
    return size;
}

template<class T>
void vector<T>::resize(unsigned int c) {
    T* newPoint=new T[c];
    for(unsigned int j=0; j<size; j++)
        newPoint[j]=point[j];
    capacity=c;
    for(unsigned int j=0; j<size; j++)
        delete[] point;
    point=newPoint;
}

/*template<class T>
void vector<T>::resize(unsigned int s) {
    if(s>size) {
        reserve(s*2);
        size=s;
    }
    else {
        for(unsigned int j=size; j>s; j--)
            delete[] point;
    }
}*/

template<class T>
void vector<T>::push_back(const T& v) {
    if(size==capacity)
        resize(capacity*2);
    point[size]=v;
    size++;
}

template<class T>
void vector<T>::pop_back() {
    delete point[size--];
    size--;
}

template<class T>
T* vector<T>::search(const T* v) const {
    if(point) {
        for(unsigned int j=0; j<size; j++) {
            if(point[j]==v)
                return point[j];
        }
    }
}

template<class T>
T& vector<T>::operator[](unsigned int j) const {
    return point[j];
}

template<class T>
bool vector<T>::operator==(const T& v) const {
    if(size!=v.size)
        return false;
    for(unsigned int j=0; j<size; ++j) {
        if(point[j]!=v.point[j])
            return false;
    }
    return true;
}

template<class T>
bool vector<T>::operator!=(const T& v) const {
    if(size!=v.size)
        return true;
    for(unsigned int j=0; j<size; ++j) {
        if(point[j]!=v.point[j])
            return true;
    }
    return false;
}

template<class T>
vector<T> vector<T>::operator+(const vector<T>& v) const {
    vector w;
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
vector<T>::iterator::iterator(): pt(nullptr), eov(false) {}

template<class T>
bool vector<T>::iterator::operator==(const iterator& it) const {
    return pt==it.pt;
}

template<class T>
bool vector<T>::iterator::operator!=(const iterator& it) const {
    return pt!=it.pt;
}


template<class T>
typename vector<T>::iterator vector<T>::begin() const {
    return point[0];
}

template<class T>
typename vector<T>::iterator vector<T>::end() const {
    return point[size-1];
}

template<class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
    for(int j=0; j<v.getSize(); ++j)
        os << v[j] << ' ';
    return os;
}

#endif // VECTOR_H