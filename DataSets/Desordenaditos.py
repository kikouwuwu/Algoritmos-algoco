import random

def guardar_en_txt_por_partes(nombre, generador, partes=10):
    """
    Guarda una lista generada en partes en un archivo de texto.
    - nombre: Nombre del archivo.
    - generador: Generador que produce las partes de la lista.
    - partes: Número de partes en las que se divide la generación.
    """
    with open(nombre, 'w') as archivo:
        for _ in range(partes):
            parte = next(generador)
            archivo.write(' '.join(map(str, parte)) + ' ')

def generador_lista(tamano_lista, partes):
    """
    Genera una lista en partes.
    - tamano_lista: Tamaño total de la lista.
    - partes: Número de partes.
    """
    tamano_parte = tamano_lista // partes
    for _ in range(partes):
        yield random.sample(range(1, tamano_lista + 1), tamano_parte)

# Tamaño de las listas
tamano_lista = 1000 # Cambiado a 1,000,000

# Generar y guardar listas por partes

# Lista desordenada
guardar_en_txt_por_partes('desordenada.txt', generador_lista(tamano_lista, partes=10))

# Lista mixta (ordenada parcialmente)
mitimiti = sorted(random.sample(range(1, tamano_lista // 2 + 1), tamano_lista // 2)) + random.sample(range(1, tamano_lista // 2 + 1), tamano_lista // 2)
guardar_en_txt_por_partes('semi_ordenada.txt', generador_lista(len(mitimiti), partes=10))

# Lista completamente ordenada
ordenada = sorted(range(1, tamano_lista + 1))
guardar_en_txt_por_partes('ordenada.txt', generador_lista(len(ordenada), partes=10))

# Lista en orden inverso
reversa = ordenada[::-1]
guardar_en_txt_por_partes('inversa.txt', generador_lista(len(reversa), partes=10))

# Lista con elementos repetidos
repetidos = random.choices(range(1, tamano_lista // 1000 + 1), k=tamano_lista)
guardar_en_txt_por_partes('repetida.txt', generador_lista(len(repetidos), partes=10))

print("Listas generadas y guardadas.")
