#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LONG 100


typedef struct Palabras {
    /* arreglo que contendra la palabra */
    char palabra[MAX_LONG];
    int cantidad; /*contador de veces que aparece en el texto*/
} Palabras;

typedef struct NodoPalabra {
    Palabras diccionario;
    struct NodoPalabra *siguiente;
}NodoPalabra;

NodoPalabra *head;

void crear_Nodo_Palabra(Palabras palabra_a_agregar){
    
	NodoPalabra *nuevo = malloc(sizeof(NodoPalabra));
    nuevo->diccionario = palabra_a_agregar;
    /* apuntamos el nodo siguiente al nuevo nodo, a la cabeza actual de la lista */
	nuevo->siguiente = head;
    /* la nueva cabeza de la lista es el nuevo nodo creado */
    head=nuevo;
}

//fuente://parzibyte.me/blog/2018/11/13/contar-frecuencia-de-palabras-en-c/
void insertar_palabra(char *palabra_actual){
    /* para comprobar si la palabra se encuentra en la lista enlazada */
    int existe;
    NodoPalabra *aux=head;

    while(aux!=NULL){
        /* si no existe la palabra se agrega al diccionario, si existe, se aumenta el contador de cantidad
         */
        existe=strcmp(aux->diccionario.palabra,palabra_actual);
        if(existe==0){
            /*se aumenta la cantidad de la palabra*/
            break;
            
        }

        aux=aux->siguiente;
    }
    if(existe==0){
        aux->diccionario.cantidad++;
    }
    else{
    /*Si se llega a este punto, significa que la palabra que se recibe como parametro es nueva*/
        Palabras palabra_auxiliar;
        strcpy(palabra_auxiliar.palabra,palabra_actual);
        palabra_auxiliar.cantidad=1;
        crear_Nodo_Palabra(palabra_auxiliar);
    } 
    
}
void ordenar_lista() {
    /*ordenar la lista enlazada*/
    NodoPalabra *i,*j;
    Palabras aux_p;
    NodoPalabra *temp = malloc(sizeof(NodoPalabra));
    for(i=head;i!=NULL;i=i->siguiente){
        for(j=i->siguiente;j!=NULL;j=j->siguiente){
            if(i->diccionario.cantidad<j->diccionario.cantidad){
                temp->diccionario=i->diccionario;
                i->diccionario=j->diccionario;
                j->diccionario=temp->diccionario;
            }
        }
    }
}
void imprimir_lista(){
    NodoPalabra *imprimir;
    int k=0;
    for(imprimir=head;imprimir!=NULL;imprimir=imprimir->siguiente){
        printf("%s: %d\n",imprimir->diccionario.palabra, imprimir->diccionario.cantidad);
        k++;
        if(k==10){
            break;
        }
    }
}
int main() {

    head=NULL;
    char palabra_leida[MAX_LONG];
    FILE *archivo=fopen("texto.txt","r");

    if(archivo==NULL){
        printf("El archivo no se pudo leer");
        exit(1);
    }

    /* leemos el archivo de texto y cada palabra */

/* mientras exista palabra que leer */
    while(!feof(archivo)){
        fscanf(archivo,"%s",palabra_leida);

        insertar_palabra(palabra_leida);
    }

    fclose(archivo);

   

    ordenar_lista();
    imprimir_lista();
    free(head);
    return 0;
}
//https://parzibyte.me/blog/2018/11/13/contar-frecuencia-de-palabras-en-c/
//https://platzi.com/tutoriales/1740-lenguaje-c-2019/6402-pasos-para-crear-un-nodo-en-c-listas-enlazadas/