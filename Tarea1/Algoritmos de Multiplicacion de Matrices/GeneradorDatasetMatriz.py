import random

def generate_random_matrix(rows, cols, min_val, max_val):
    """Genera una matriz con filas y columnas dadas con valores aleatorios entre min_val y max_val."""
    return [[random.randint(min_val, max_val) for _ in range(cols)] for _ in range(rows)]

def generate_matrix_dataset(filename, min_size, max_size, min_val, max_val):
    """Genera un archivo con dos matrices aleatorias con dimensiones compatibles para multiplicación."""
    # Tamaño de la primera matriz
    rows_A = random.randint(min_size, max_size)
    cols_A = random.randint(min_size, max_size)
    
    # Tamaño de la segunda matriz debe ser compatible para la multiplicación
    rows_B = cols_A  # Para que A*B sea posible, filas de B deben ser iguales a columnas de A
    cols_B = random.randint(min_size, max_size)
    
    matrix_A = generate_random_matrix(rows_A, cols_A, min_val, max_val)
    matrix_B = generate_random_matrix(rows_B, cols_B, min_val, max_val)
    
    with open(filename, 'w') as f:
        # Escribir la matriz A
        f.write(f"{rows_A} {cols_A}\n")
        for row in matrix_A:
            f.write(" ".join(map(str, row)) + "\n")
        
        # Escribir la matriz B
        f.write(f"{rows_B} {cols_B}\n")
        for row in matrix_B:
            f.write(" ".join(map(str, row)) + "\n")

# Parámetros de ejemplo
min_size = 2  # Tamaño mínimo para filas y columnas
max_size = 5  # Tamaño máximo para filas y columnas
min_val = 1
max_val = 100

generate_matrix_dataset("dataset.txt", min_size, max_size, min_val, max_val)
