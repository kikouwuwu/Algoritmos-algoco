#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Función para dividir una matriz en submatrices
void splitMatrix(const vector<vector<int>>& matrix, vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, vector<vector<int>>& D) {
    int n = matrix.size();
    int m = matrix[0].size();
    int half = n / 2;

    A.resize(half, vector<int>(half));
    B.resize(half, vector<int>(half));
    C.resize(half, vector<int>(half));
    D.resize(half, vector<int>(half));

    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A[i][j] = matrix[i][j];
            B[i][j] = matrix[i][j + half];
            C[i][j] = matrix[i + half][j];
            D[i][j] = matrix[i + half][j + half];
        }
    }
}

// Función para sumar dos matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Función para restar dos matrices
vector<vector<int>> subtractMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Implementación del algoritmo de Strassen
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        vector<vector<int>> result(1, vector<int>(1));
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    vector<vector<int>> A11, A12, A21, A22;
    vector<vector<int>> B11, B12, B21, B22;

    splitMatrix(A, A11, A12, A21, A22);
    splitMatrix(B, B11, B12, B21, B22);

    vector<vector<int>> M1 = strassen(addMatrices(A11, A22), addMatrices(B11, B22));
    vector<vector<int>> M2 = strassen(addMatrices(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, subtractMatrices(B12, B22));
    vector<vector<int>> M4 = strassen(A22, subtractMatrices(B21, B11));
    vector<vector<int>> M5 = strassen(addMatrices(A11, A12), B22);
    vector<vector<int>> M6 = strassen(subtractMatrices(A21, A11), addMatrices(B11, B12));
    vector<vector<int>> M7 = strassen(subtractMatrices(A12, A22), addMatrices(B21, B22));

    vector<vector<int>> C11 = addMatrices(subtractMatrices(addMatrices(M1, M4), M5), M7);
    vector<vector<int>> C12 = addMatrices(M3, M5);
    vector<vector<int>> C21 = addMatrices(M2, M4);
    vector<vector<int>> C22 = addMatrices(subtractMatrices(addMatrices(M1, M3), M2), M6);

    vector<vector<int>> result(n, vector<int>(n));
    int half = n / 2;

    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + half] = C12[i][j];
            result[i + half][j] = C21[i][j];
            result[i + half][j + half] = C22[i][j];
        }
    }

    return result;
}

// Función para verificar si un número es potencia de 2
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// Función para verificar que las matrices sean potencias de 2
bool checkMatrixSize(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    return isPowerOfTwo(n) && isPowerOfTwo(matrix[0].size());
}

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
            inRow = true; // Se está procesando una nueva fila
        } else if (ch == ']') {
            if (inRow && !row.empty()) {
                matrix.push_back(row);
                row.clear();
                inRow = false; // Termina la fila actual
            }
        } else if (isdigit(ch) || ch == '-') {
            ss.putback(ch);
            ss >> num;
            row.push_back(num);
        }
    }

    // Asegura que la última fila sea agregada
    if (inRow && !row.empty()) {
        matrix.push_back(row);
    }

    return matrix;
}

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
    ifstream inputFile("/workspaces/Algoritmos-algoco/identidad_128x128.txt");
    stringstream fileStream;
    vector<vector<int>> A, B;

    if (inputFile.is_open()) {
        fileStream << inputFile.rdbuf();
        string content = fileStream.str();

        // Encuentra el doble salto de línea que separa las matrices
        size_t pos = content.find("\n\n");
        if (pos != string::npos) {
            A = parseMatrix(content.substr(0, pos));
            B = parseMatrix(content.substr(pos + 2));
        }

        inputFile.close();

        // Verificar que las matrices sean de tamaño potencia de 2
        if (checkMatrixSize(A) && checkMatrixSize(B) && A.size() == B.size()) {
            // Medir el tiempo de ejecución
            auto start = high_resolution_clock::now();

            // Multiplicar las matrices usando el algoritmo de Strassen
            vector<vector<int>> C = strassen(A, B);

            // Imprimir el resultado
            /*
            cout << "Resultado de la multiplicación:" << endl;
            printMatrix(C);
            */
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start).count();
            double milliseconds = duration / 1000.0;

            if (milliseconds < 1.0) {
                cout << "Tiempo de ejecución: " << fixed << setprecision(6) << milliseconds << " ms" << endl;
            } else {
                cout << "Tiempo de ejecución: " << fixed << setprecision(3) << milliseconds << " ms" << endl;
            }
        } else {
            cout << "Las matrices deben ser cuadradas y de tamaño potencia de 2." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
