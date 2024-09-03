import random

def generate_random_matrix(size, min_val, max_val):
    """Genera una matriz cuadrada de tamaño 'size' con valores aleatorios entre min_val y max_val."""
    return [[random.randint(min_val, max_val) for _ in range(size)] for _ in range(size)]

def generate_matrix_dataset(filename, min_size, max_size, min_val, max_val):
    """Genera un archivo con dos matrices cuadradas aleatorias con la misma dimensión."""
    # Tamaño de las matrices
    size = random.randint(min_size, max_size)
    
    matrix_A = generate_random_matrix(size, min_val, max_val)
    matrix_B = generate_random_matrix(size, min_val, max_val)
    
    with open(filename, 'w') as f:
        # Escribir la matriz A
        f.write(f"{size} {size}\n")
        for row in matrix_A:
            f.write(" ".join(map(str, row)) + "\n")
        
        # Escribir la matriz B
        f.write(f"{size} {size}\n")
        for row in matrix_B:
            f.write(" ".join(map(str, row)) + "\n")

# Parámetros de ejemplo
min_size = 2  # Tamaño mínimo para filas y columnas
max_size = 100  # Tamaño máximo para filas y columnas
min_val = 1
max_val = 100

generate_matrix_dataset("dataset.txt", min_size, max_size, min_val, max_val)
