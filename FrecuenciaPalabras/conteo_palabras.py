class PalFreq:
    def __init__(self, palabra, count=1):
        self.palabra = palabra
        self.cont = count
        self.next = None

def insertar_palabra(head, palabra):
    if head is None:
        return PalFreq(palabra)

    actual = head
    while actual:
        if actual.palabra == palabra:
            actual.cont += 1
            return head
        if actual.next is None:
            break
        actual = actual.next

    actual.next = PalFreq(palabra)
    return head

def imprimir_mas_frecuentes(head, n):
    lista_palabra = []
    actual = head
    while actual:
        lista_palabra.append(actual)
        actual = actual.next

    # Ordenar la lista por frecuencia de mayor a menor
    lista_palabra.sort(key=lambda x: x.cont, reverse=True)

    # Imprimir las n palabras más frecuentes
    for i in range(min(n, len(lista_palabra))):
        print(f"{lista_palabra[i].palabra}: {lista_palabra[i].cont}")


archivo = "texto.txt"
cont_pal = {}

try:
    with open(archivo, 'r') as file:
        for linea in file:
            palabras = linea.split()
            for palabra in palabras:
                palabra = palabra.lower()  # Convertir a minúsculas
                if palabra in cont_pal:
                    cont_pal[palabra] += 1
                else:
                    cont_pal[palabra] = 1
except FileNotFoundError:
    print(f"Error: archivo '{archivo}' no encontrado")
    exit(1)
except IOError:
    print(f"Error: no se pudo leer el archivo '{archivo}'")
    exit(1)

# Crear la lista enlazada de objetos PalFreq
head = None
for palabra, count in cont_pal.items():
    if head is None:
        head = PalFreq(palabra, count)
    else:
        actual = head
        while actual.next:
            actual = actual.next
        actual.next = PalFreq(palabra, count)

# Imprimir las 10 palabras más frecuentes
imprimir_mas_frecuentes(head, 10)
#https://geekflare.com/es/python-dictionary-sorting/
#https://docs.python.org/es/3.8/howto/sorting.html
#https://pythondiario.com/2018/07/linked-list-listas-enlazadas.html