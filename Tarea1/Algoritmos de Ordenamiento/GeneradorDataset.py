import random

def generate_dataset(filename, size, lower_bound, upper_bound):
    with open(filename, 'w') as f:
        for _ in range(size):
            num = random.randint(lower_bound, upper_bound)
            f.write(f"{num}\n")

# Parámetros
filename = "dataset.txt"
size = random.randint(1, 500)
lower_bound = 1
upper_bound = 1000

generate_dataset(filename, size, lower_bound, upper_bound)