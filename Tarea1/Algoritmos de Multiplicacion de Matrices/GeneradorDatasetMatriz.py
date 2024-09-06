import random

def generate_random_matrix(rows, cols, min_val, max_val):
    """Genera una matriz con filas y columnas dadas con valores aleatorios entre min_val y max_val."""
    return [[random.randint(min_val, max_val) for _ in range(cols)] for _ in range(rows)]

def generate_matrix_dataset(filename, size, min_val, max_val):
    """Genera un archivo con dos matrices aleatorias con dimensiones compatibles para multiplicación."""
    
    matrix_A = generate_random_matrix(size, size, min_val, max_val)
    matrix_B = generate_random_matrix(size, size, min_val, max_val)
    
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
min_val = 1
max_val = 1000

size = int(input("Ingrese dimensión de las matrices: "))

for i in range(2):
    filename = f"dataset{i}.txt"
    generate_matrix_dataset(filename, size, min_val, max_val)
