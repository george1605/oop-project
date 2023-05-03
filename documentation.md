# Documentatie pentru API Grafuri Neorientate

- Clase definite
```c++
class Graf;
class Matrice;
```

- Metode a clasei `Matrice`

```c++
void alloc(int x, int y);
```
Aloca dinamic o matrice de X pe Y

```c++
void set(int x, int y, bool n);
```
Seteaza valoarea a elementului (x, y) la valoarea parametrului `n`

```c++
void fill(bool value)
```
