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
    vector(unsigned int =0, T* =nullptr);
    vector(const vector<T>&);
    vector<T>& operator=(const vector<T>&);
    ~vector();
    void push_back(const T&);
    void pop_back();
    bool empty() const;
    void clear();
    unsigned int getCapacity() const;
    unsigned int getSize() const;
    void resize(unsigned int);
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

#endif // VECTOR_H
