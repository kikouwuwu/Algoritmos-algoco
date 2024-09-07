#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// función para combinar dos subarreglos ordenados en uno solo
vector<int> Merge(const vector<int>& array1, const vector<int>& array2) {
    vector<int> result; // el resultado final
    int i = 0, j = 0;
    // se combinan los dos arreglos mientras haya elementos en ambos
    while (i < array1.size() && j < array2.size()) {
        if (array1[i] <= array2[j]) result.push_back(array1[i++]); // añade el menor valor de array1
        else result.push_back(array2[j++]); // añade el menor valor de array2
    }
    // añade los elementos restantes de array1 y array2
    result.insert(result.end(), array1.begin() + i, array1.end());
    result.insert(result.end(), array2.begin() + j, array2.end());
    return result;
}

// función de ordenación usando merge sort
vector<int> MergeSort(const vector<int>& array) {
    if (array.size() <= 1) return array; // caso base: si el array tiene 1 o menos elementos
    int mid = array.size() / 2; // divide el array por la mitad
    vector<int> left(array.begin(), array.begin() + mid); // crea el subarray izquierdo
    vector<int> right(array.begin() + mid, array.end()); // crea el subarray derecho
    // se ordenan ambos subarrays recursivamente y luego se combinan
    return Merge(MergeSort(left), MergeSort(right));
}

int main() {
    ifstream file("/workspaces/Algoritmos-algoco/semi_ordenada.txt"); // abre el archivo de datos
    vector<int> array((istream_iterator<int>(file)), istream_iterator<int>()); // carga los números del archivo en un vector
    file.close(); // cierra el archivo

    auto start = high_resolution_clock::now(); // empieza a medir el tiempo de ejecución
    array = MergeSort(array); // aplica el algoritmo merge sort
    auto end = high_resolution_clock::now(); // termina de medir el tiempo

    // imprimir la lista ordenada          
    /*
    for (int x : array) cout << x << " "; // <----- quitar los comentarios para imprimir la lista
    cout << endl;
    */

    // calcula el tiempo de ejecución en milisegundos
    double milliseconds_elapsed = duration_cast<microseconds>(end - start).count() / 1000.0;
    cout << "Tiempo transcurrido: " << fixed << setprecision(2) << milliseconds_elapsed << " ms" << endl;

    return 0;
}