#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();
    vector<vector<int>> C(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
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

        // Medir el tiempo de ejecución
        auto start = high_resolution_clock::now();

        // Multiplicar las matrices
        vector<vector<int>> C = multiplyMatrices(A, B);

        // Imprimir el resultado
        /*
        cout << "Resultado de la multiplicación:" << endl;
        printMatrix(C);
        */

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        double milliseconds = duration / 1000.0;

        cout << "Tiempo de ejecución: " << fixed << setprecision(6) << milliseconds << " ms" << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
