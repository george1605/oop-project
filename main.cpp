#include "graf.cpp"
#include <cstdlib>
using namespace std;

void clear()
{
    
    #ifdef _WIN32
        system("cls");
    #elif defined(__linux__) || defined(__unix__)
        printf("\x1B[2J\x1B[1;1H"); // cool printf templating
    #endif
}

void show_queue(queue<int> que)
{
    cout << "Coada: ";
    while(!que.empty())
    {
            cout << que.front() << " ";
            que.pop();
    }
}

std::string meniu = "\n\t\tSelecteaza o optiune"
"\n\t\t0. Verifica daca nodul este izolat"
"\n\t\t1. Parcurgere DFS din nod dat"
"\n\t\t2. Parcurgere BFS din nod dat"
"\n\t\t3. Afiseaza numarul componentelor conexe"
"\n\t\t4. Afiseaza daca doua noduri sunt adiacente"
"\n\t\t5. Verifica daca un graf este partial."
"\n\t\t6. Iesire\n";

int main()
{
    int alegere, nod, nod2;
    char c;
    Graf g, g2;    
    cout << meniu;
    cin >> alegere;
    if(alegere == 6) return 0;
    queue<int> q;
    vector<int> vec;
    clear(); 
    cout << "Introdu muchiile grafului\n";
    cin >> g;
while(alegere != 6) {
    switch(alegere)
    {
    case 0:
        cout << "Introdu numarul nodului:";
        cin >> nod;
        cout << (g.izolat(nod)? "Nodul este izolat.": "Nodul nu este izolat.");
        cout << "\n";
    break;
    case 1:
        cout << "Introdu numarul nodului:";
        cin >> nod;
        vec.resize(g.noduri() + 1);
        g.dfs(1, vec, 1);
        cout << "Vector: ";
        for(int i : vec)
            cout << i << " ";
    break;
    case 2:
        cout << "Introdu numarul nodului:";
        cin >> nod;
        vec.resize(g.noduri() + 1);
        g.bfs(nod, q, vec);
        cout << '\n';
        show_queue(q);
    break;
    case 3:
        cout << "Componente conexe: " << g.conexe();
    break;
    case 4:
        cout << "Introdu nodurile: ";
        cin >> nod >> nod2;
        cout << (g.get(nod, nod2) ? "Sunt adiacente.": "Nu sunt adiacente.") << '\n';
    break;
    case 5:
        cin >> g2;
        cout << ((g < g2)? "Este graf partial.": "Nu este graf partial.");
        cout << '\n';
    break;
    default:
        cout << "Nu e o optiune. Mai introduceti o data\n";
    break;
    }

        cout << "\n\tContinua (D/N)";
        cin >> c;
        if(c == 'D')
            clear();
        else // poate fi orice litera
            break;
        cout << meniu;
        cin >> alegere;
    }
    return 0;
}