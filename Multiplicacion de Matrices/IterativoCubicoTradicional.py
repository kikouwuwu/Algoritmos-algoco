def MultiMat(matriz1, matriz2):

    if len(matriz1[0]) == len(matriz2): #el numero de columnas de 1 debe ser igual al numero de filas de 2 "fc x fc"
    
        resultado = []

        for i in range(len(matriz1)):                       
            resultado.append([])                    #se crea una matriz vacia
            for j in range(len(matriz1)):           #se rellena la matriz de ceros
                resultado[i].append(0)

        for i in range(len(matriz1)):                                       #Se recorren las filas de la matriz 1
            for j in range(len(matriz2[0])):                                #Se recorren las columnas de la matriz 2
                for k in range(len(matriz1[0])):                            #Se recorren las columnas de la matriz 1
                    resultado[i][j] += matriz1[i][k] * matriz2[k][j]            #se multiplican las matrices en sus respectivas posiciones.
        return resultado
    else:
        print("asi no era mijito")
        exit()
   

matriz1 = [[1,2,3],[4,5,6]]
matriz2 = [[1,2],[3,4],[5,6]]

print(MultiMat(matriz1, matriz2))