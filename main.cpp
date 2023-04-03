#include "graf.cpp"
using namespace std;

void clear()
{
    
    #ifdef _WIN32
        system("cls");
    #elif defined(__linux__)
        printf("\x1B[2J\x1B[1;1H");
    #endif
}

void show_queue(queue<int> que)
{
    for(int i = 0;i < que.size();i++)
    {
            cout << que.front() << " ";
            que.pop();
    }
}

std::string meniu = "Selecteaza o optiune\n"
"1. Parcurgere DFS din nod dat\n"
"2. Parcurgere BFS din nod dat\n"
"3. Afiseaza numarul componentelor conexe\n"
"4. Afiseaza daca doua noduri sunt adiacente\n"
"5. Verifica daca un graf este partial.\n"
"6. Iesire\n";

int main()
{
    int alegere, nod, nod2;
    Graf g, g2;    
    cout << meniu;
    cin >> alegere;
    if(alegere == 6) return 0;
    queue<int> q; vector<int> vec;
    clear(); 
    cout << "Introdu muchiile grafului\n";
    cin >> g;
sw:
    switch(alegere)
    {
    case 1:
        cout << "Introdu numarul nodului:";
        cin >> nod;
        vec.resize(g.noduri() + 1);
        g.dfs(1, vec, 1);
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
    case 6: return 0;
    default:
        cout << "Nu e o optiune. Mai introduceti o data\n";
    break;
    }

    clear();
    cout << meniu;
    goto sw;
    return 0;
}