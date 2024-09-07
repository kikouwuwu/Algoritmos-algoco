#include <bits/stdc++.h> // Incluye todas las bibliotecas estándar de C++
using namespace std;
using namespace chrono;

int Pivot(int* array, int menor, int mayor) {
    int mid = menor + (mayor - menor) / 2;
    int pivot = max(min(array[menor], array[mid]), min(max(array[menor], array[mid]), array[mayor]));

    if (pivot == array[mid]) {
        swap(array[mid], array[mayor]);
    } else if (pivot == array[menor]) {
        swap(array[menor], array[mayor]);
    }

    int pivote = array[mayor];
    int izquierdo = menor;

    for (int i = menor; i < mayor; i++) {
        if (array[i] < pivote) {
            swap(array[i], array[izquierdo]);
            izquierdo++;
        }
    }

    swap(array[izquierdo], array[mayor]);
    return izquierdo;
}

void QuickSort(int* array, int menor, int mayor) {
    if (menor < mayor) {
        int pivotear = Pivot(array, menor, mayor);
        QuickSort(array, menor, pivotear - 1);
        QuickSort(array, pivotear + 1, mayor);
    }
}

int main() {
    // Leer el archivo de entrada
    ifstream archivo("/workspaces/Algoritmos-algoco/semi_ordenada.txt"); // Cambiar aquí las listas a probar
    if (!archivo) {
        cerr << "No se puede abrir el archivo" << endl;
        return 1;
    }

    // Leer los números del archivo
    vector<int> datos;
    int valor;
    while (archivo >> valor) {
        datos.push_back(valor);
    }
    archivo.close();

    // Convertir el vector a un arreglo
    int n = datos.size();
    int* array = new int[n];
    copy(datos.begin(), datos.end(), array);

    // Medir el tiempo de ordenación
    auto start = high_resolution_clock::now(); // Inicio del temporizador
    QuickSort(array, 0, n - 1);                // Ordenar el arreglo
    auto end = high_resolution_clock::now();   // Fin del temporizador
    auto elapsed = duration_cast<duration<double, micro>>(end - start); // Tiempo en microsegundos

    // Mostrar tiempo en milisegundos (valor decimal)
    double milliseconds_elapsed = elapsed.count() / 1000.0;
    cout << "Tiempo de ordenación: " << milliseconds_elapsed << " ms" << endl;

    // Imprimir el arreglo ordenado (opcional)
    /*
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    */
    
    delete[] array; // Liberar memoria

    return 0;
}
