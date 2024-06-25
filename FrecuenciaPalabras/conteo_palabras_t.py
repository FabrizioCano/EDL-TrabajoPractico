import operator

PAL=10
archivo = open("texto.txt","r")
#por cada linea del archivo, hacer split para obtener las palabras
palabras=[]
for lineas in archivo:
    palabras.extend(lineas.split()) #añade la palabra leida al arreglo palabras   
#diccionario de palabra/cantidad
diccionario={}
#iterar por cada palabra y agregarlo al diccionario
for palabra in palabras:
    #si la palabra esta en el diccionario, se utiliza su valor para aumentar su cantidad
    pal_aux=palabra.lower()
    if pal_aux in diccionario:
        diccionario[pal_aux]+=1
    else:
        diccionario[pal_aux]=1

#ordenamos el diccionario por frecuencia mediante un objeto operator 
diccionario_palabras=sorted(diccionario.items(),key=operator.itemgetter(1),reverse=True)

print(f'Ranking de las {PAL} palabras mas repetidas')
for n in enumerate(diccionario_palabras[:PAL]):
    print(f'Palabra:{n[1][0]} - Cantidad: {diccionario[n[1][0]]}')
    
archivo.close()
#https://geekflare.com/es/python-dictionary-sorting/
#https://docs.python.org/es/3.8/howto/sorting.html
