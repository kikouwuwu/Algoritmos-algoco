#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

// Función para realizar el ordenamiento burbuja
void bubble_sort(vector<int>& array) {
    int n = array.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        // si no hubo intercambio en la pasada, la lista está ordenada
        if (!swapped) break;
    }
}

int main() {
    ifstream file("/workspaces/Algoritmos-algoco/semi_ordenada.txt");
    vector<int> numbers;
    int number;

    // lee los números desde el archivo
    if (file.is_open()) {
        while (file >> number) {
            numbers.push_back(number);
        }
        file.close();
    } else {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    // medir el tiempo de ejecución
    auto start = high_resolution_clock::now();

    // ordenar los números
    bubble_sort(numbers);

    auto end = high_resolution_clock::now();
    duration<double, milli> elapsed = end - start;

    // mostrar los números ordenados
    /*
    for (int num : numbers) {           // <----- quitar los comentario para imprimir la lista ordenada
        cout << num << " ";
    }
    cout << endl;
    */
   
    // mostrar el tiempo total de ejecución en milisegundos
    cout << "Tiempo de ejecución: " << elapsed.count() << " ms." << endl;

    return 0;
}