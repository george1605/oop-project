#ifndef __MATRICE__
#define __MATRICE__
#include <memory.h>
#include <string.h>

class Matrice
{
private:
    bool* ptr;
public:
    int w, h;
    Matrice() {}
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
        delete ptr;
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