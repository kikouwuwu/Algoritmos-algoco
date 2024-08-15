def bubble_sort(array):
    for i in range(len(array)):
        for j in range(len(array)- i - 1): 
            if array[j] > array[j+1]: #seleccciona el valor actual y el siguiente para comparar.
                array[j], array[j+1] = array[j+1], array[j] #reordena los valores comparando pares y cambiandolos de posicion.
    return array
down = list(map(int, input("numeritos: ").split()))
print(bubble_sort(down))