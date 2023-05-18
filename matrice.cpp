#ifndef __MATRICE__
#define __MATRICE__
#include <memory.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Matrice
{
private:
    bool* ptr = NULL;
public:
    int w, h;
    Matrice() {}
    Matrice(const Matrice& m) {
        ptr = new bool[m.w * m.h + 1];
        memcpy(this->ptr, m.ptr, m.w * m.h);
    }
    void alloc(int x, int y)
    {
        ptr = new bool[x * y + 1];
        w = x;
        h = y;
        memset(ptr, 0, x * y);
    }
    void dealloc() {
        if(ptr)
            delete[] ptr; 
    }
    Matrice(int x, int y)
    {
        alloc(x,y);
    };
    ~Matrice()
    {
        dealloc();
    }
    void set(int x, int y, bool n)
    {
        ptr[y * w + x] = n;
    }
    bool get(int x, int y)
    {
        return ptr[y * w + x];
    }
    bool operator [](int s) {
        return ptr[s];
    }
    void fill(bool value)
    {
        memset(ptr, value, this->w * this->h);
    }
};

#endif // GUARD
