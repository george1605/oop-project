#include "graf.hpp"
#include <fstream>

Graf::Graf(){}
Graf::Graf(const Graf& t) 
{
    this->m = Matrice(t.m); // copy 
    this->nod = t.nod; 
}

Graf::~Graf()
{
    if(viz)
        delete[] viz;
}

inline bool Graf::get(int x, int y)
{
    return m.get(x, y);
}

inline void Graf::set(int x, int y, bool val)
{
    m.set(x, y, val);
}

inline int Graf::noduri() { // fara overhead
    return nod;
}

inline bool Graf::adiacent(int n1, int n2) {
    return m.get(n1, n2);
}

void Graf::dfs(int start, int mark = 1) 
{
    viz[start] = mark;
    for(int i = 1;i <= nod;i++)
        if(m.get(start, i) && !viz[i])
            dfs(i, mark);
}

bool operator <(Graf& g1, Graf& g2)
{
    if(g1.noduri() != g2.noduri())
        return false;
    for(int i = 0;i <= g1.noduri();i++)
        for(int j = 0;j <= g1.noduri();j++)
            if(g1.get(i, j) != 0 && g2.get(i, j) == 0)
                return false;
    return true;
}

void Graf::bfs(int start)
{
    q.push(start);
    viz[start] = 1;
    while(!q.empty())
    {
        int z = q.front();
        q.pop();
        for(int i = 1;i <= nod;i++)
            if (m.get(i,z) && !viz[i])
            {
                q.push(z);
                viz[z] = 1;
            }
    }
}

std::istream& operator >>(std::istream& is, Graf& g) 
{
    int m;
    is >> g.nod >> m;
    g.m.alloc(g.nod+1, g.nod+1);
    int x, y;
    for(int i = 1;i <= m;i++)
    {
        is >> x >> y;
        g.set(x, y, 1);
        g.set(y, x, 1);
    }
    return is;
}

void Graf::citire(char* file)
{
    ifstream fin(file);
    fin >> *this;
    fin.close(); // it's important to close the file
}

std::ostream& operator <<(std::ostream& os, Graf& g)
{
    for(int i = 1;i <= g.noduri();i++)
    {
        for(int j = 1;j <= g.noduri();j++)
            os << g.get(i, j) << " ";
        os << '\n';
    }
    return os;
}

int Graf::conexe() {
    int k = 0;
    for (int l = 1;l <= nod;l++)
    {
        if (viz[l] == 0) { 
            k++;
            this->dfs(l, k);
        }
    }
    for(int i = 1;i <= k;i++)
    {
        cout << "Componenta " << i << ": ";
        for(int j = 1;j <= nod;j++)
            if(viz[j] == i)
                cout << j << " ";
        cout << "\n";
    }
    return k;
}

bool Graf::izolat(int nod) {
    for(int i = 1;i <= nod;i++)
        if(m.get(nod, i))
            return false;
    return true;
}
