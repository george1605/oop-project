#ifndef __GRAF__
#define __GRAF__
#include "Matrice.cpp"
#include <vector>
#include <queue>
#include <iostream>

class Graf {
private:
    Matrice m;
    int* viz = NULL;
    queue<int> q;
public:
    Graf();
    Graf(const Graf&);
    ~Graf();
    int nod;
    inline int noduri();
    void citire(char* file); // de ce nu merge std::string
    inline bool get(int x, int y);
    inline void set(int x, int y, bool val);
    bool adiacent(int n1, int n2);
    void dfs(int start, int mark);
    void bfs(int start);
    
    friend std::istream& operator >>(std::istream& is, Graf& g);
    friend std::ostream& operator <<(std::ostream& os, Graf& g);
    friend bool operator <(Graf& g1, Graf& g2);
    bool izolat(int nod);
    int conexe();
    bool operator <(const Graf& p);
};

#endif
