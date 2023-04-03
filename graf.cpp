#include "graf.hpp"

Graf::Graf(){}
Graf::Graf(const Graf& t) 
{
    this->m = t.m;
    this->nod = t.nod;
}
Graf::~Graf()
{
    
}

inline int Graf::noduri() { // fara overhead
    return nod;
}

bool Graf::adiacent(int n1, int n2) {
    return m.get(n1, n2);
}

void Graf::dfs(int start, std::vector<int>& ref, int mark = 1) 
{
    ref[start] = mark;
    for(int i = 1;i <= nod;i++)
        if(m.get(start, i) && !ref[i])
            dfs(i, ref, mark);
}

bool operator <(Graf& g1, Graf& g2)
{
    for(int i = 0;i <= g1.noduri();i++)
        for(int j = 0;j <= g1.noduri();j++)
            if(g1.m.get(i, j) != (g2.m.get(i, j)) && !g2.m.get(i, j))
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

std::istream& operator >>(std::istream& is, Graf& g) 
{
    int m;
    is >> g.nod >> m;
    g.m.alloc(g.nod+1, m+1);
    int x, y;
    for(int i = 1;i <= m;i++)
    {
        is >> x >> y;
        g.m.set(x, y, 1);
        g.m.set(y, x, 1);
    }
    return is;
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
    std::vector<int> vec(nod + 1);
    int k = 0;
    for (int l = 1;l <= nod;l++)
    {
        if (vec[l] == 0) 
            k++, this->dfs(l,vec, k);
    }
    return k;
}

bool Graf::izolat(int nod) {
    for(int i = 1;i <= nod;i++)
        if(m.get(nod, i))
            return false;
    return true;
}

inline bool Graf::get(int x, int y)
{
    return m.get(x, y);
}