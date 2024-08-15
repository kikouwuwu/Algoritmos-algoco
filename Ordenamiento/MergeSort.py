def Merge_Sort(array):
    if len(array) == 1:
        return array
    mitad = len(array)//2      #separa la lista en 2 para trabajar con ellas.
    array1 = array[:mitad]      #selecciona los elementos desde la mitad en adelante
    array2 = array[mitad:]       #selecciona los elementos desde la mitad hacia atras
    
    array1 = Merge_Sort(array1)     #recursion para repetir el proceso hasta que queden todos los datos brutos.
    array2 = Merge_Sort(array2)
    
    return ordenamiento(array1, array2)


def ordenamiento(array1, array2):
    array_t = []
    while len(array1) and len(array2) != 0:       #condicion para evitar casos de listas vacias.
        if array1[0] > array2[0]:                  
            array_t.append(array2[0])           #compara pares de numeros y los ordena en una lista "temporal"
            array2.remove(array2[0])            
        else:
            array_t.append(array1[0])           
            array1.remove(array1[0])
    while len(array1) != 0:                     
        array_t.append(array1[0])               #agrega el valor correspondiente a la lista temporal y lo elimina de su lista
        array1.remove(array1[0])
    while len(array2) != 0:     
        array_t.append(array2[0])               #agrega el valor correspondiente a la lista temporal y lo elimina de su lista
        array2.remove(array2[0])

    return array_t

down = list(map(int, input("numeritos: ").split()))

print(Merge_Sort(down))

