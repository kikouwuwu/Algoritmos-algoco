#include <bits/stdc++.h> // incluye todas las bibliotecas estándar de C++
using namespace std;
using namespace chrono;

int Pivot(int* array, int menor, int mayor) {
    // calcular el punto medio y seleccionar el pivote
    int mid = menor + (mayor - menor) / 2;
    int pivot = max(min(array[menor], array[mid]), min(max(array[menor], array[mid]), array[mayor]));

    // colocar el pivote en la posición correcta
    if (pivot == array[mid]) {
        swap(array[mid], array[mayor]);
    } else if (pivot == array[menor]) {
        swap(array[menor], array[mayor]);
    }

    int pivote = array[mayor];
    int izquierdo = menor;

    // particionar el arreglo en base al pivote
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
    // aplicar el algoritmo de quicksort de forma recursiva
    if (menor < mayor) {
        int pivotear = Pivot(array, menor, mayor);
        QuickSort(array, menor, pivotear - 1);
        QuickSort(array, pivotear + 1, mayor);
    }
}

int main() {
    // leer el archivo de entrada
    ifstream archivo("/ruta/al/archivo/semi_ordenada.txt"); // <----- cambiar aquí la dirección del archivo
    if (!archivo) {
        cerr << "No se puede abrir el archivo" << endl;
        return 1;
    }

    // leer los números del archivo
    vector<int> datos;
    int valor;
    while (archivo >> valor) {
        datos.push_back(valor);
    }
    archivo.close();

    // convertir el vector a un arreglo
    int n = datos.size();
    int* array = new int[n];
    copy(datos.begin(), datos.end(), array);

    // medir el tiempo de ordenación
    auto start = high_resolution_clock::now(); // <----- inicio del temporizador
    QuickSort(array, 0, n - 1);                // <----- ordenar el arreglo
    auto end = high_resolution_clock::now();   // <----- fin del temporizador
    auto elapsed = duration_cast<duration<double, micro>>(end - start); // <----- tiempo en microsegundos para obtener valores menores a 1 ms

    // mostrar tiempo en milisegundos (valor decimal)
    double milliseconds_elapsed = elapsed.count() / 1000.0;
    cout << "Tiempo de ordenación: " << milliseconds_elapsed << " ms" << endl;

    // imprimir el arreglo ordenado
    /*
    for (int i = 0; i < n; i++) {           // <----- quitar el comentario para imprimir la lista
        cout << array[i] << " ";
    }
    cout << endl;
    */

    delete[] array; // <----- liberar memoria

    return 0;
}
