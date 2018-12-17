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
    void resize(unsigned int);
    void push_back(const T&);
    void pop_back();
    T* search(const T*);
    T& operator[](unsigned int);
    class constiterator {
    friend class vector<T>;
    private:
        const T* pt;
        bool eov;
        constiterator(T* =nullptr, bool =false);
    public:
        constiterator();
        constiterator& operator++();
        constiterator& operator--();
        const T& operator*() const;
        bool operator==(const constiterator&) const;
        bool operator!=(const constiterator&) const;
    };
    constiterator begin() const;
    constiterator end() const;
};

template<class T>
T* vector<T>::copy() const {
    T* v;
    if(!size)
        v=nullptr;
    else
        v=new T*[size];
    for(int j=0; j<size; j++)
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
    capacity=0;
    size=0;
    point=nullptr;
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
void resize(unsigned int )

template<class T>
void vector<T>::push_back(const T& v) {

}

#endif // VECTOR_H
