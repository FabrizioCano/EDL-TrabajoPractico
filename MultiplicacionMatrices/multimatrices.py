import csv #archivo csv
import random 
#generacion aleatoria
#funcion para escribir en el archivo
def escribir_matriz_archivo(matriz, archivo):
    with open(archivo, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(matriz)
#funcion para imprimir la matriz
def imprimir_matriz(matriz):
    for fila in matriz:
        print(' '.join(f'{num:5}' for num in fila))
#funcion para generar valores aleatorios en las matrices
def generar_matriz(filas, columnas):
    return [[random.randint(5, 15) for _ in range(columnas)] for _ in range(filas)]
    """ return [[random.randint(10000, 500000) for _ in range(columnas)] for _ in range(filas)] """
#funcion para multiplicar
def multiplicar_matrices(matriz1, matriz2):
    filas1, cols1 = len(matriz1), len(matriz1[0])
    cols2 = len(matriz2[0])


    resultado = [[0 for _ in range(cols2)] for _ in range(filas1)]
    for i in range(filas1):
        for j in range(cols2):
            for k in range(cols1):
                resultado[i][j] += matriz1[i][k] * matriz2[k][j]
    return resultado

#funcion main

    
while (True):
    print("Ingrese lo siguiente:")
    filas1 = int(input("El número de filas para la primera matriz: "))
    cols1 = int(input("El número de columnas para la primera matriz: "))
    filas2 = int(input("El número de filas para la segunda matriz: "))
    cols2 = int(input("El número de columnas para la segunda matriz: "))

    if cols1 != filas2:
        print("No se puede generar las matrices: el número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz.")
    else:
        break 

""" filas1=250
filas2=250
cols1=250
cols2=250 """
matriz1 = generar_matriz(filas1, cols1)
matriz2 = generar_matriz(filas2, cols2)

""" matriz11=[
    [12, 11],
    [11, 14]
]
matriz22=[
    [11, 10],
    [13, 10]
] """
print("Primera matriz:")
imprimir_matriz(matriz1)
print("Segunda matriz:")
imprimir_matriz(matriz2)

resultado = multiplicar_matrices(matriz1, matriz2)

""" print("Resultado de la multiplicación:")
imprimir_matriz(resultado) """

# guarda el resultado en el archivo
archivo_resultado = "resultado_python.csv"
escribir_matriz_archivo(resultado, archivo_resultado)

print("El resultado se ha guardado en " + archivo_resultado)

