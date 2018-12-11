#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class vector {
private:
    unsigned int size;
    T* punt;
public:
    vector(unsigned int =0, unsigned int =0, T* =nullptr);
    vector(const vector<T>&);
    vector<T>& operator=(const vector<T>&);
    ~vector();
    void push_back(const T&);
    void pop_back();
    void resize(unsigned int size);
    T& operator[](unsigned int);

};

std::ostream& vector<T> operator<<(std::ostream& os, const vector<T>& v);

#endif // VECTOR_H
