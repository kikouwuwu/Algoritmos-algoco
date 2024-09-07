#include <bits/stdc++.h> // incluye todas las librerías estándar
using namespace std;
using namespace std::chrono; // para medir el tiempo de ejecución

// convierte una cadena que representa una matriz en un vector de vectores de enteros
vector<vector<int>> parseMatrix(const string& matrixStr) {
    vector<vector<int>> matrix;
    vector<int> row;
    stringstream ss(matrixStr);
    char ch;
    int num;
    bool inRow = false; // controla si estamos dentro de una fila
    
    while (ss >> ch) {
        if (ch == '[') {
            // inicia una nueva fila
            if (inRow && !row.empty()) {
                matrix.push_back(row);
                row.clear();
            }
            inRow = true;
        } else if (ch == ']') {
            // termina la fila actual
            if (inRow && !row.empty()) {
                matrix.push_back(row);
                row.clear();
                inRow = false;
            }
        } else if (isdigit(ch) || ch == '-') {
            // lee un número y lo añade a la fila actual
            ss.putback(ch);
            ss >> num;
            row.push_back(num);
        }
    }

    if (inRow && !row.empty()) {
        matrix.push_back(row); // asegura agregar la última fila
    }

    return matrix;
}

// realiza la multiplicación de matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();
    vector<vector<int>> C(n, vector<int>(m, 0)); // matriz resultado

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                // realiza la multiplicación y suma para cada elemento
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {
    ifstream inputFile("/workspaces/Algoritmos-algoco/identidad_128x128.txt");  // <----- cambiar aqui la direccion del archivo
    stringstream fileStream;
    vector<vector<int>> A, B;

    if (inputFile.is_open()) {
        fileStream << inputFile.rdbuf(); // lee todo el archivo
        string content = fileStream.str();

        // encuentra el doble salto de linea que separa las dos matrices
        size_t pos = content.find("\n\n");
        if (pos != string::npos) {
            A = parseMatrix(content.substr(0, pos)); // extrae la primera matriz
            B = parseMatrix(content.substr(pos + 2)); // extrae la segunda matriz
        }

        inputFile.close();

        // mide el tiempo de ejecucion de la multiplicacion de matrices
        auto start = high_resolution_clock::now();

        vector<vector<int>> C = multiplyMatrices(A, B); // realiza la multiplicación

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        double milliseconds = duration / 1000.0;

        cout << "Tiempo de ejecucion: " << fixed << setprecision(6) << milliseconds << " ms" << endl;

        // Imprimir resultado
        /*
        cout << "Resultado de la multiplicacion:" << endl;              // <----- quitar comentarios para imprimir
        printMatrix(C);
        */
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}