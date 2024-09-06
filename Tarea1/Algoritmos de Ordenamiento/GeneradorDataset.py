import random

def generate_dataset(filename, size, lower_bound, upper_bound):
    with open(filename, 'w') as f:
        for _ in range(size):
            num = random.randint(lower_bound, upper_bound)
            f.write(f"{num}\n")

# Parámetros
lower_bound = 1
upper_bound = 1000

size = int(input("Ingrese dimensión de las matrices: "))

for i in range(10):
    filename = f"dataset{i}.txt"
    generate_dataset(filename, size, lower_bound, upper_bound)