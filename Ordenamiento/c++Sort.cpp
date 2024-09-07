#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main() {
    // leer los números desde el archivo de entrada
    ifstream inputFile("/workspaces/Algoritmos-algoco/semi_ordenada.txt");  // <----- cambiar aqui la direccion del archivo
    vector<int> numbers((istream_iterator<int>(inputFile)), istream_iterator<int>());
    inputFile.close();

    // medir el tiempo de ordenación
    auto start = high_resolution_clock::now();

    // ordenar la lista
    sort(numbers.begin(), numbers.end());

    auto end = high_resolution_clock::now();
    auto elapsed = end - start;

    // convertir a milisegundos con precisión decimal
    double milliseconds_elapsed = duration_cast<microseconds>(elapsed).count() / 1000.0;
    cout << "Tiempo transcurrido: " << fixed << setprecision(2) << milliseconds_elapsed << " ms" << endl;

    // imprimir la lista ordenada 
    /*
    for (int num : numbers) {           // <---- quitar el comentario para ver la lista
        cout << num << " ";
    }
    cout << endl;
    */

    return 0;
}