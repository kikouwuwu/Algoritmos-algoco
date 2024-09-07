#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

vector<int> Merge(const vector<int>& array1, const vector<int>& array2) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < array1.size() && j < array2.size()) {
        if (array1[i] <= array2[j]) result.push_back(array1[i++]);
        else result.push_back(array2[j++]);
    }
    result.insert(result.end(), array1.begin() + i, array1.end());
    result.insert(result.end(), array2.begin() + j, array2.end());
    return result;
}

vector<int> MergeSort(const vector<int>& array) {
    if (array.size() <= 1) return array;
    int mid = array.size() / 2;
    vector<int> left(array.begin(), array.begin() + mid);
    vector<int> right(array.begin() + mid, array.end());
    return Merge(MergeSort(left), MergeSort(right));
}

int main() {
    ifstream file("/workspaces/Algoritmos-algoco/semi_ordenada.txt"); // Asegúrate de que el archivo esté en el directorio correcto
    vector<int> array((istream_iterator<int>(file)), istream_iterator<int>());
    file.close();

    auto start = high_resolution_clock::now();
    array = MergeSort(array);
    auto end = high_resolution_clock::now();

    // Imprimir la lista ordenada
    /*
    for (int x : array) cout << x << " ";
    cout << endl;
    */
    // Convertir a milisegundos con precisión decimal
    double milliseconds_elapsed = duration_cast<microseconds>(end - start).count() / 1000.0;
    cout << "Tiempo transcurrido: " << fixed << setprecision(2) << milliseconds_elapsed << " ms" << endl;

    return 0;
}