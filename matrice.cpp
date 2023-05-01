#ifndef __MATRICE__
#define __MATRICE__
#include <memory.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Matrice
{
private:
    bool* ptr;
public:
    int w, h;
    Matrice() {}
    Matrice(Matrice& m) {
        ptr = new bool[m.w * m.h];
        memcpy(this->ptr, m.ptr, m.w * m.h);
    }
    void alloc(int x, int y)
    {
        ptr = new bool[x * y];
        w = x;
        h = y;
    }
    Matrice(int x, int y)
    {
        alloc(x,y);
    };
    ~Matrice()
    {
        delete[] ptr;
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
    void fill(char val)
    {
        memset(ptr, val, this->w * this->h);
    }
};

#endif // GUARD