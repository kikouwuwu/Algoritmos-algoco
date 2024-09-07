import numpy as np

def save_matrices_to_file(filename, matrix1, matrix2):
    """guarda dos matrices en un archivo de texto en formato de arreglos, con una linea en blanco entre ellas"""
    with open(filename, 'w') as file:
        file.write(f"{matrix1.tolist()}\n\n")  # guarda la primera matriz
        file.write(f"{matrix2.tolist()}\n")    # guarda la segunda matriz

def generate_random_matrix(rows, cols, min_val=1, max_val=10):
    """genera una matriz con valores aleatorios enteros"""
    return np.random.randint(min_val, max_val+1, size=(rows, cols))

def generate_identity_matrix(size):
    """genera una matriz identidad de tamaño `size`"""
    return np.eye(size, dtype=int)

def generate_test_matrices():
    # caso 1: multiplicación de matrices 1024x1024
    matrix1 = generate_random_matrix(1024, 1024)
    matrix2 = generate_random_matrix(1024, 1024)
    save_matrices_to_file('1024x1024.txt', matrix1, matrix2)

    # caso 2: multiplicación de matrices 512x512
    matrix1 = generate_random_matrix(512, 512)
    matrix2 = generate_random_matrix(512, 512)
    save_matrices_to_file('512x512.txt', matrix1, matrix2)

    # caso 3: multiplicación de matrices 256x256
    matrix1 = generate_random_matrix(256, 256)
    matrix2 = generate_random_matrix(256, 256)
    save_matrices_to_file('256x256.txt', matrix1, matrix2)

    # caso 4: multiplicación de matrices 2048x2048
    matrix1 = generate_random_matrix(2048, 2048)
    matrix2 = generate_random_matrix(2048, 2048)
    save_matrices_to_file('2048x2048.txt', matrix1, matrix2)

    # caso 5: multiplicación de matrices no compatibles (4x3 y 5x2)
    matrix1 = generate_random_matrix(4, 3)
    matrix2 = generate_random_matrix(5, 2)
    save_matrices_to_file('no_compatible.txt', matrix1, matrix2)

    # caso 6: multiplicación de matrices identidad 128x128
    matrix1 = generate_identity_matrix(128)
    matrix2 = generate_identity_matrix(128)
    save_matrices_to_file('identidad_128x128.txt', matrix1, matrix2)

    # caso 7: multiplicación de matrices 64x64
    matrix1 = generate_random_matrix(64, 64)
    matrix2 = generate_random_matrix(64, 64)
    save_matrices_to_file('64x64.txt', matrix1, matrix2)

    # caso 8: multiplicación de matrices 32x32
    matrix1 = generate_random_matrix(32, 32)
    matrix2 = generate_random_matrix(32, 32)
    save_matrices_to_file('32x32.txt', matrix1, matrix2)

    # caso 9: multiplicación de matrices 16x16
    matrix1 = generate_random_matrix(16, 16)
    matrix2 = generate_random_matrix(16, 16)
    save_matrices_to_file('16x16.txt', matrix1, matrix2)

    # caso 10: multiplicación de matrices 4x4
    matrix1 = generate_random_matrix(4, 4)
    matrix2 = generate_random_matrix(4, 4)
    save_matrices_to_file('4x4.txt', matrix1, matrix2)

    # caso 11: multiplicación de matrices 2x2
    matrix1 = generate_random_matrix(2, 2)
    matrix2 = generate_random_matrix(2, 2)
    save_matrices_to_file('2x2.txt', matrix1, matrix2)

    # caso 12: multiplicación de matrices 1x1
    matrix1 = generate_random_matrix(1, 1)
    matrix2 = generate_random_matrix(1, 1)
    save_matrices_to_file('1x1.txt', matrix1, matrix2)

if __name__ == '__main__':
    generate_test_matrices()
