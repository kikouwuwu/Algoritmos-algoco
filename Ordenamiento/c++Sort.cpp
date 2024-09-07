#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main() {
    // Leer los números desordenados desde el archivo de entrada
    ifstream inputFile("/workspaces/Algoritmos-algoco/semi_ordenada.txt");
    vector<int> numbers((istream_iterator<int>(inputFile)), istream_iterator<int>());
    inputFile.close();

    // Medir el tiempo de ordenación
    auto start = high_resolution_clock::now();

    // Ordenar la lista
    sort(numbers.begin(), numbers.end());

    auto end = high_resolution_clock::now();
    auto elapsed = end - start;

    // Convertir a milisegundos con precisión decimal
    double milliseconds_elapsed = duration_cast<microseconds>(elapsed).count() / 1000.0;
    cout << "Tiempo transcurrido: " << fixed << setprecision(2) << milliseconds_elapsed << " ms" << endl;

    // Imprimir la lista ordenada
    /*
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    */

    return 0;
}