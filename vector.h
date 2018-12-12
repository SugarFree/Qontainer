#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class vector {
private:
    unsigned int size;
    T* point;
    int* copy() const;
public:
    vector(unsigned int =0, T* =nullptr);
    vector(const vector<T>&);
    vector<T>& operator=(const vector<T>&);
    ~vector();
    void push_back(const T&);
    void pop_back();
    bool empty() const;
    // void clear(); per pulire tutta una config. Basta distruttore???
    unsigned int getSize() const;
    void resize(unsigned int size);
    T& operator[](unsigned int);
    class constiterator {
    friend class vector<T>;
    private:
        const T* pt;

    };
};



std::ostream& vector<T> operator<<(std::ostream& os, const vector<T>& v);

#endif // VECTOR_H
