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

void Graf::dfs(int start, std::vector<int>& ref, int mark = 1) 
{
    ref[start] = mark;
    for(int i = 1;i <= nod;i++)
        if(m.get(start, i) && !ref[i])
            dfs(i, ref, mark);
}

/*
 * Mark reprezinta numarul de marcare. Utilizat pentru componente conexe.
*/
void Graf::dfs(int start, int vec[], int mark = 1)
{
    vec[start] = mark;
    for(int i = 1;i <= nod;i++)
        if(m.get(start, i) && !vec[i])
            dfs(i, vec, mark);
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

void Graf::bfs(int start, std::queue<int>& queue, std::vector<int> viz)
{
    queue.push(start);
    viz[start] = 1;
    while(!queue.empty())
    {
        queue.pop();
        int z = queue.front();
        for(int i = 1;i <= m.w;i++)
            if (m.get(i,z) && !viz[i])
            {
                queue.push(z);
                viz[z] = 1;
            }
    }
}

void Graf::bfs(int start, int queue[], int viz[])
{
    int st = 1, dr = 0;
    int k;
    queue[dr++] = start;
    viz[start] = 1;
    while(st <= dr)
    {
        k = queue[st];
        for(int i = 1;i <= n;i++)
            if(m.get(i, k) && !v[i])
                viz[i] = 1, c[++dr] = i;
        ++st;
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
    std::vector<int> vec(nod + 1, 0);
    int k = 0;
    for (int l = 1;l <= nod;l++)
    {
        if (vec[l] == 0) 
            k++, this->dfs(l,vec, k);
    }
    for(int i = 1;i <= k;i++)
    {
        cout << "Componenta " << i << ": ";
        for(int j = 0;j <= nod;j++)
            if(vec[j] == i)
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