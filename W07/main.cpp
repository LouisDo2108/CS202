#include "fraction.h"

bool check(const int &index, const int &size)
{
    if (index >= 0 && index < size)
        return true;
    cout << "Index out of range" << endl;
    return false;
}

template <class T>
class MyVector
{
private:
    T *arr;
    int size;
    int capacity;

public:
    // empty array
    MyVector();
    // n zeros
    MyVector(int n);
    MyVector(T *a, int n);
    MyVector(const MyVector &v);
    ~MyVector();
    int getSize();
    T getItem(int index);
    void setItem(T value, int index);
    void add(T value);
    void addRange(T *a, int n);
    void clear();
    bool contains(T value);
    void toArray(T *inputArr, const int &n);
    bool equals(const MyVector &v);
    int indexOf(T value);
    int lastIndexOf(T value);
    void insert(T value, int index);
    void remove(T value);
    void removeAt(int index);
    void reverse();
    string toString();
    void sortAsc();
    void sortDesc();

    void print();
};

template <class T>
MyVector<T>::MyVector() : arr(nullptr), size(0), capacity(1){};

template <class T>
MyVector<T>::MyVector(int n) : arr(new T[n * 2]{T(0)}), size(n), capacity(n * 2){};

template <class T>
MyVector<T>::MyVector(T *a, int n) : arr(new T[n * 2]{T(0)}), size(n), capacity(n * 2)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i] = a[i];
    }
};

template <class T>
MyVector<T>::MyVector(const MyVector &v)
{
    if (this == &v)
        return;

    arr = new T[v.capacity]{T(0)};
    size = v.size;
    capacity = v.capacity;

    for (int i = 0; i < size; ++i)
    {
        arr[i] = v.arr[i];
    }
};

template <class T>
MyVector<T>::~MyVector()
{
    if (arr)
        delete[] arr;
};

template <class T>
int MyVector<T>::getSize()
{
    return size;
};

template <class T>
T MyVector<T>::getItem(int index)
{
    if (index < size && index >= 0)
        return arr[index];
    cout << "Index out of range, return trash value!" << endl;
    return arr[capacity - 1];
};

template <class T>
void MyVector<T>::setItem(T value, int index)
{
    if (check(index, size))
    {
        arr[index] = value;
    }
}

template <class T>
void MyVector<T>::add(T value)
{
    if (size >= (capacity - 1))
    {
        capacity *= 2;
        T *temp = new T[capacity];
        for (int i = 0; i < size; ++i)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    arr[size] = value;
    ++size;
}

template <class T>
void MyVector<T>::print()
{
    if (size <= 0)
    {
        cout << "My vector is empty!" << endl;
        return;
    }

    for (int i = 0; i < size; ++i)
        cout << "arr[" << i << "]: " << arr[i] << endl;
}

template <class T>
void MyVector<T>::addRange(T *a, int n)
{
    if ((size + n) >= (capacity - 1))
    {
        capacity = (capacity + n) * 2;
        T *temp = new T[capacity]{T(0)};
        for (int i = 0; i < size; ++i)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    for (int i = 0; i < n; ++i)
    {
        arr[size + i] = a[i];
    }
    size += n;
}

template <class T>
void MyVector<T>::clear()
{
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 10;
}

template <class T>
bool MyVector<T>::contains(T value)
{
    if (size <= 0)
        return false;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == value)
        {
            return true;
        }
    }
    return false;
}

template <class T>
void MyVector<T>::toArray(T *inputArr, const int &n)
{
    if (!inputArr)
    {
        cout << "The give array is null" << endl;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (i >= size)
            inputArr[i] = T(0);
        else
            inputArr[i] = this->arr[i];
    }
}

template <class T>
bool MyVector<T>::equals(const MyVector &v)
{
    if (this == &v)
        return true;
    if (size == v.size)
    {
        for (int i = 0; i < size; ++i)
        {
            if (v.arr[i] != arr[i])
                return false;
        }
    }
    return true;
}

template <class T>
int MyVector<T>::indexOf(T value)
{
    if (size <= 0)
        return -1;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == value)
            return i;
    }

    cout << "Couldn't fidn the index of the give value" << endl;
    return -1;
}

template <class T>
int MyVector<T>::lastIndexOf(T value)
{
    int i = indexOf(value);

    if (i < 0)
        return i;

    int li = i;
    for (i; i < size; ++i)
        if (arr[i] == value)
            li = i;

    return li;
};

template <class T>
void MyVector<T>::insert(T value, int index)
{
    if (!check(index, size))
        return;

    for (int i = size; i > index; --i)
    {
        arr[i] = arr[i - 1];
    }

    ++size;
    arr[index] = value;
}

template <class T>
void MyVector<T>::remove(T value)
{
    int si = indexOf(value);
    int count = 0;

    if (si < 0)
        return;

    for (int i = si; i < size; ++i)
    {
        if (arr[i + count] == value)
        {
            ++count;
            --size;
        }
        arr[i] = arr[i + count];
    }
}

template <class T>
void MyVector<T>::removeAt(int index)
{
    if (!check(index, size))
        return;
    for (int i = index; i < size; ++i)
    {
        arr[i] = arr[i + 1];
    }
    --size;
}

template <class T>
void MyVector<T>::reverse()
{
    int n = size / 2;
    for (int i = 0; i < n; ++i)
    {
        swap(arr[i], arr[size - 1 - i]);
    }
}

template <class T>
string MyVector<T>::toString()
{
    string a = "";
    for (int i = 0; i < size; ++i)
    {
        a += (string)arr[i];
        a += ",\n";
    }
    return a;
}

template <class T>
void MyVector<T>::sortAsc()
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            if (arr[i].operator>(arr[j]))
                swap(arr[i], arr[j]);
        }
    }
}

template <class T>
void MyVector<T>::sortDesc()
{
    this->sortAsc();
    this->reverse();
}

int main()
{
    const int size = 10;
    int i = 0;
    MyVector<Fraction> *vec = new MyVector<Fraction>;

    for (i = 0; i < size; ++i)
    {
        vec->add(Fraction(i, i + 1));
    }

    Fraction *extra = new Fraction[5];
    for (i; i < size + 5; ++i)
    {
        extra[i - size] = Fraction(i, i + 1);
    }
    vec->addRange(extra, 5);
    vec->print();

    cout << "Size: " << vec->getSize() << endl;
    Fraction got = vec->getItem(0);
    cout << "getItem at index 0: " << got;
    vec->setItem(Fraction(100, 3), 0);
    got = vec->getItem(0);
    cout << "getItem at index 0: " << got;

    if (vec->contains(Fraction(100, 3)))
        cout << "Yes, MyVector contains 100/3" << endl;
    else
    {
        cout << "No, 100/3 is NOT in MyVector" << endl;
    }

    const int reSize = 10;
    Fraction *returnArr = new Fraction[reSize];

    vec->toArray(returnArr, reSize);
    cout << "toArray: " << endl;
    for (i = 0; i < reSize; ++i)
        cout << "toArray[" << i << "] = " << returnArr[i];
    cout << endl;

    MyVector<Fraction> *another = new MyVector<Fraction>(*vec);
    if (vec->equals(*another))
        cout << "Yes, vec and another is equal" << endl;
    else
    {
        cout << "No, vec and another is NOT equal" << endl;
    }

    cout << "Index of 100/3: " << vec->indexOf(Fraction(100, 3)) << endl;
    cout << "Last index of 12/13: " << vec->lastIndexOf(Fraction(12, 13)) << endl;
    cout << endl;

    cout << "Insert 21/8 at 0, delete arr[1] and 12/13 in MyVector" << endl;
    vec->insert(Fraction(21, 8), 0);
    vec->remove(Fraction(12, 13));
    vec->removeAt(1);
    vec->print();
    cout << endl;

    cout << "Reverse: " << endl;
    vec->reverse();
    vec->print();
    cout << endl;

    cout << "toString: " << endl;
    cout << vec->toString();
    cout << endl;

    cout << "sortAsc: " << endl;
    vec->sortAsc();
    vec->print();
    cout << endl;

    cout << "sortDesc: " << endl;
    vec->sortDesc();
    vec->print();
    cout << endl;

    vec->clear();
    vec->print();
    delete[] returnArr;
    delete another;
    delete vec;
    return 0;
}