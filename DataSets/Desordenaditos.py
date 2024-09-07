import random

def guardar_en_txt_por_partes(nombre, generador, partes=10):
    """
    guarda una lista generada en partes en un archivo de texto
    - nombre: nombre del archivo
    - generador: generador que produce las partes de la lista
    - partes: numero de partes en las que se divide la generacion
    """
    with open(nombre, 'w') as archivo:
        for _ in range(partes):
            parte = next(generador)
            archivo.write(' '.join(map(str, parte)) + ' ')  # guarda cada parte en el archivo, separada por espacios

def generador_lista(tamano_lista, partes):
    """
    genera una lista en partes
    - tamano_lista: tamano total de la lista
    - partes: numero de partes
    """
    tamano_parte = tamano_lista // partes
    for _ in range(partes):
        yield random.sample(range(1, tamano_lista + 1), tamano_parte)  # genera una parte de la lista

# tamaño de las listas
tamano_lista = 1000 # <------ cambiar aqui el tamano de las listas

# generar y guardar listas por partes

# lista desordenada
guardar_en_txt_por_partes('desordenada.txt', generador_lista(tamano_lista, partes=10)) 

# lista mixta (ordenada parcialmente)
mitimiti = sorted(random.sample(range(1, tamano_lista // 2 + 1), tamano_lista // 2)) + random.sample(range(1, tamano_lista // 2 + 1), tamano_lista // 2)  
guardar_en_txt_por_partes('semi_ordenada.txt', generador_lista(len(mitimiti), partes=10)) 

# lista completamente ordenada
ordenada = sorted(range(1, tamano_lista + 1))  
guardar_en_txt_por_partes('ordenada.txt', generador_lista(len(ordenada), partes=10))  

# lista en orden inverso
reversa = ordenada[::-1]  
guardar_en_txt_por_partes('inversa.txt', generador_lista(len(reversa), partes=10)) 
# lista con elementos repetidos
repetidos = random.choices(range(1, tamano_lista // 1000 + 1), k=tamano_lista)  
guardar_en_txt_por_partes('repetida.txt', generador_lista(len(repetidos), partes=10))  

print("Listas generadas y guardadas.")  
