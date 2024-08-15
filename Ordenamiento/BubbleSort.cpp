#include <iostream>
using namespace std;

int* BubbleSort(int* array, int n){
    for(int i = 0; i<n; i++){ 
        for(int j = 0; j < n - i - 1; j++){
            if(array[j]>array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
    return array;
}   
int main() {
    int lista[] = {123, 321, 23, 12, 32, 21};
    int* resultado = BubbleSort(lista, 6);
    for(int i = 0; i<6; i++){
        cout << resultado[i] << " ";
    } 
    return 0;
}