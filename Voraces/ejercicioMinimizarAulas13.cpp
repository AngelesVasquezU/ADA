/*
Deseamos optimizar el uso de las aulas de un centro educativo. Dados un
conjunto de aulas y un conjunto de clases con un horario preestablecido (la clase
i empieza a la hora si
 y termina a la hora fi), diseñe un algoritmo greedy que
minimice el número de aulas necesario para impartir toda la docencia del centro.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Class {
    int inicio, fin, id;
    Class(double ini, double f, int id_) {
        id = id_, inicio = ini, fin = f;
    }
};

bool comparar(Class &a, Class &b) {
    return a.inicio < b.inicio;
}

void minimizarAulas(std::vector<Class>& clases) {
    std::sort(clases.begin(), clases.end(), comparar);
    std::priority_queue<int, std::vector<int>, std::greater<int>> aulas;
    int nroAulas = 0;
    for (int i = 0; i < clases.size(); i++) {
        if (!aulas.empty() && aulas.top() <= clases[i].fin) {
            //usar aula
            std::cout << "Clase " << clases[i].id<< " (" << clases[i].inicio << "-" << clases[i].fin << ")"<<"\n";
            int hora = aulas.top();
            aulas.pop();
            aulas.push(clases[i].fin);
        }
        else {
            std::cout << "Clase " << clases[i].id << " (" << clases[i].inicio << "-" << clases[i].fin << ")" << "\n";
            nroAulas++;
            aulas.push(clases[i].fin);
        }
    }
    std::cout << "Número mínimo de aulas necesarias: " << nroAulas << "\n";
}

int main()
{
    std::vector<Class> clases = { {9, 10, 1}, {9, 12, 2},
        {10, 11, 3},
        {11, 12, 4},
        {13, 14, 5},
        {12, 15, 6}
    };
    
    minimizarAulas(clases);

    return 0;
}

