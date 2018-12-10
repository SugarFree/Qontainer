#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class vector {
private:
    unsigned int size;
    unsigned int capacity;
    T* punt;
public:
    vector(unsigned int =0, unsigned int =0, T* =nullptr);
    vector(const vector<T>&);
    ~vector();
    unsigned int get_size() const;
    unsigned int get_capacity() const;
    bool empty();
    void push_back(const T&);

};

#endif // VECTOR_H
