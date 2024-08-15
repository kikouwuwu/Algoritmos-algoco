def Traspuesta(matriz):  #debemos trasponer la segunda matriz y multiplicar; esta funcion es solo para tranponer.
    trastras = []
    for i in range(len(matriz[0])):                 #recorre la matriz y agrega en orden contrario (columna-fila) los valores a una lista "trastras" [j][i]
        trastras.append([])                                 
        for j in range(len(matriz)):
            trastras[i].append(matriz[j][i])
    return trastras

def multiplicar(matriz1, matriz2):
    
    
    if len(matriz1[0]) == len(matriz2):             #se debe cumplir que el numero de columnas de la matriz 1 debe ser igual al numero de filas de la matriz 2

        matriz_tras = Traspuesta(matriz2)           #se traspone la segunda matriz
        resultado = []
        
        for i in range(len(matriz1)):                       #se crea una matriz inicial de ceros
            resultado.append([0] * len(matriz2[0]))

        
        for i in range(len(matriz1)):                       #se recorren las filas de la matriz 1
            for j in range(len(matriz2[0])):                #se recorren las columnas de la matriz 2
                for k in range(len(matriz1[0])):            #se recorren las columnas de la matriz 1
                    resultado[i][j] += matriz1[i][k] * matriz_tras[j][k]    #se multiplican la matriz 1 con la matriz traspuesta en sus respectivas iteraiones dentro del ciclo
    else: 
        print("macacooo")
        return None

    return resultado


matriz1 = [1,2],[3,4],[5,6]
matriz2 = [[1,2,3],[4,5,6]]

print(multiplicar(matriz1, matriz2))