// #include <cstring>
// #include <algorithm>

// template <typename T>
// void swap(T &t1, T &t2)
// {
//     T temp = std::move(t1);
//     t1 = std::move(t2);
//     td = std::move(temp);
// }

#include <algorithm> // std::copy
#include <cstddef>   // std::size_t
#include <iostream>
#include <utility> // std::move
#include <string>

template <class T>
class ptr{
    private:
    T *ptr;

    public:
    explicit ptr(T *p_in = 0): ptr(p_in) {}

    ~ptr() {delete ptr;}

    operator=(ptr ptr_rhs){
        swap(ptr_rhs);
        return *this;
    } 

    //Move constructor
    ptr(ptr&& ptr_rhs){
        swap(ptr_rhs.ptr);
    }
    

    swap(ptr& ptr_in){
        std::swap(ptr_in, ptr);
    }


};

template <class T>
class clone_ptr
{
  private:
    T *ptr;

  public:
    // construction
    explicit clone_ptr(T *p = 0) : ptr(p) {}

    // destruction
    ~clone_ptr() { delete ptr; }

    // // copy semantics
    clone_ptr(const clone_ptr &p)
        : ptr(p.ptr ? p.ptr->clone() : 0) {}

    clone_ptr &operator=(const clone_ptr &p)
    {
        std::cout << "copy equals" << std::endl;
        if (this != &p)
        {
            delete ptr;
            ptr = p.ptr ? p.ptr->clone() : 0;
        }
        return *this;
    }

    swap(ptr ptrin )

    // move semantics
    clone_ptr(clone_ptr &&p)
        : ptr(p.ptr) { p.ptr = 0; }

    clone_ptr &operator=(clone_ptr &&p)
    {
        std::cout << "move equals" << std::endl;
        std::swap(ptr, p.ptr);
        return *this;
    }

    // Other operations
    T &operator*() const { return *ptr; }
    // ...
};

int main()
{
    int n = 2;
    int* a = &n;
    clone_ptr<int> a_ptr(a);
    clone_ptr<int> b_ptr = std::move(a_ptr);

    return 0;
}

// class dumb_array
// {
//   private:
//     std::size_t mSize;
//     int *mArray;

//   public:
//     // (default) constructor
//     dumb_array(std::size_t size = 0)
//         : mSize(size),
//           mArray(mSize ? new int[mSize]() : nullptr)
//     {
//     }

//     dumb_array &operator=(dumb_array other) // (1)
//     {
//         swap(*this, other); // (2)

//         return *this;
//     }

//     // copy-constructor
//     dumb_array(const dumb_array &other)
//         : mSize(other.mSize),
//           mArray(mSize ? new int[mSize] : nullptr),
//     {
//         // note that this is non-throwing, because of the data
//         // types being used; more attention to detail with regards
//         // to exceptions must be given in a more general case, however
//         std::copy(other.mArray, other.mArray + mSize, mArray);
//     }

//     // destructor
//     ~dumb_array()
//     {
//         delete[] mArray;
//     }

//     friend void swap(dumb_array &first, dumb_array &second) // nothrow
//     {
//         // enable ADL (not necessary in our case, but good practice)
//         using std::swap;

//         // by swapping the members of two objects,
//         // the two objects are effectively swapped
//         swap(first.mSize, second.mSize);
//         swap(first.mArray, second.mArray);
//     }
// };