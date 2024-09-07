#include <bits/stdc++.h>  // incluye todas las bibliotecas estándar de C++
using namespace std;
using namespace chrono;

// funcion para analizar una cadena y convertirla en una matriz
vector<vector<int>> parseMatrix(const string& matrixStr) {
    vector<vector<int>> matrix;
    vector<int> row;
    stringstream ss(matrixStr);
    char ch;
    int num;
    bool inRow = false;
    
    while (ss >> ch) {
        if (ch == '[') {
            if (inRow && !row.empty()) {
                matrix.push_back(row);
                row.clear();
            }
            inRow = true; // se está procesando una nueva fila
        } else if (ch == ']') {
            if (inRow && !row.empty()) {
                matrix.push_back(row);
                row.clear();
                inRow = false; // termina la fila actual
            }
        } else if (isdigit(ch) || ch == '-') {
            ss.putback(ch);
            ss >> num;
            row.push_back(num);
        }
    }

    // asegura que la última fila sea agregada
    if (inRow && !row.empty()) {
        matrix.push_back(row);
    }

    return matrix;
}

// funcion para transponer una matriz
vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

// funcion para multiplicar dos matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B_transposed) {
    int n = A.size();
    int m = B_transposed.size();  // después de transponer, B tiene sus columnas como filas
    vector<vector<int>> C(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < A[0].size(); k++) { // recorre las columnas de A y filas de B_transposed
                C[i][j] += A[i][k] * B_transposed[j][k];
            }
        }
    }

    return C;
}

// funcion para imprimir una matriz
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "[";
        for (size_t i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i != row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    ifstream inputFile("/workspaces/Algoritmos-algoco/64x64.txt");  // <----- cambiar aqui la direccion del archivo
    stringstream fileStream;
    vector<vector<int>> A, B;

    if (inputFile.is_open()) {
        fileStream << inputFile.rdbuf();
        string content = fileStream.str();

        // encuentra el doble salto de línea que separa las matrices
        size_t pos = content.find("\n\n");
        if (pos != string::npos) {
            A = parseMatrix(content.substr(0, pos));
            B = parseMatrix(content.substr(pos + 2));
        }

        inputFile.close();

        // transponer la segunda matriz
        vector<vector<int>> B_transposed = transposeMatrix(B);

        // medir el tiempo de ejecución
        auto start = high_resolution_clock::now();

        // multiplicar la primera matriz por la matriz transpuesta (fila x fila)
        vector<vector<int>> C = multiplyMatrices(A, B_transposed);

        // imprimir el resultado 
        /*
        cout << "Resultado de la multiplicación:" << endl;              // <----- quitar comentarios para imprimir
        printMatrix(C);
        */

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        double milliseconds = duration / 1000.0;

        // imprimir el tiempo de ejecución con precisión decimal
        cout << "Tiempo de ejecución: " << fixed << setprecision(6) << milliseconds << " ms" << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}