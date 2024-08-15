#include <iostream>
#include <algorithm>
using namespace std;



int Pivot(int* array, int menor, int mayor){

    int mid = menor + (mayor - menor) / 2;
    int pivot = max(min(array[menor], array[mid]), min(max(array[menor], array[mid]), array[mayor]));
    
    if (pivot == array[mid]) {
        swap(array[mid], array[mayor]);
    } else if (pivot == array[menor]) {
        swap(array[menor], array[mayor]);
    }
    
    int pivote = array[mayor];
    int izquierdo = menor;
    
    for (int i = menor; i < mayor; i++){
        if (array[i] < pivote){
            swap(array[i], array[izquierdo]);
            izquierdo ++;
        }
    }
    
    swap(array[izquierdo], array[mayor]);
    return izquierdo;
    }



void QuickSort(int* array, int menor, int mayor){ 
    /* Pa que chucha era el void?????????????????????????????????? */
    if (menor < mayor){
        int pivotear = Pivot(array, menor, mayor);
        
        QuickSort(array, menor, pivotear-1);
        QuickSort(array, pivotear + 1, mayor);
    }
}



int main() {
    int array[] = {123, 321, 23, 12, 32, 21};
    int n = sizeof(array)/sizeof(array[0]); /* Acordarse de esta mierdita */
    int menor = 0;
    int mayor = n-1;
    
    QuickSort(array, menor, mayor);
    
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
