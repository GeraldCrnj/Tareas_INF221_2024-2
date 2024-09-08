import matplotlib.pyplot as plt

# Datos para el gráfico
datasets = [256, 512, 1024]
cubico_tradicional = [0.279575, 1.711733, 16.25801]
cubico_optimizado = [0.243594, 1.515322, 11.36426]
strassen = [0.228703, 1.209783, 7.991434]


# Crear el gráfico
plt.plot(datasets, cubico_tradicional, label='Cubico Tradicional')
plt.plot(datasets, cubico_optimizado, label='Cubico Optimizado')
plt.plot(datasets, strassen, label='Strassen')


# Etiquetas y título
plt.xlabel('Tamaño del dataset')
plt.ylabel('Tiempo de ejecución (segundos)')
plt.title('Comparación de Algoritmos de Multiplicación de Matrices')
plt.legend()

# Mostrar el gráfico
plt.show()
