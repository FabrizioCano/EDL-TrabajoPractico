/*librerias*/
import java.io.*;
import java.util.*;
/* */
public class MultiplicacionMatrices {

    // escribe una matriz en un archivo CSV
    public static void escribirMatrizArchivo(double[][] matriz, String archivo) throws IOException {
        BufferedWriter escritor = new BufferedWriter(new FileWriter(archivo));//para escribir en el archivo
        for (double[] fila : matriz) {//recorre por fila toda la matriz
            for (int i = 0; i < fila.length; i++) { //recorre todos los valores de la linea
                escritor.write(Double.toString(fila[i]));
                if (i < fila.length - 1) {
                    escritor.write(",");//separador
                }
            }
            escritor.newLine();//se añade otra linea
        }
        escritor.close();//cierra el buffer
    }

    //imprime la matriz dada
    public static void imprimirMatriz(double[][] matriz) {
        for (double[] fila : matriz) {
            for (double elemento : fila) {
                System.out.printf("%10.3f", elemento);
            }
            System.out.println();
        }
    }

    // generador de una matriz aleatoria dado un tamaño dado
    public static double[][] generarMatriz(int filas, int columnas) {
        double[][] matriz = new double[filas][columnas];
        Random random = new Random();
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                /* matriz[i][j] = random.nextDouble() * (500000-10000)+10000; */
                matriz[i][j] = random.nextDouble() * (50-15)+10;
            }
        }
        return matriz;
    }

    // función para multiplicar dos matrices
    public static double[][] multiplicarMatrices(double[][] matriz1, double[][] matriz2) {
        int filas1 = matriz1.length;
        int col1 = matriz1[0].length;
        int filas2 = matriz2.length;
        int col2 = matriz2[0].length;
        //no se cumple con la condición para multiplicar
        if (col1 != filas2) {
            throw new IllegalArgumentException("Las matrices no se pueden multiplicar.");
        }

        double[][] resultado = new double[filas1][col2];//para guardar la matriz resultado
        for (int i = 0; i < filas1; i++) {
            for (int j = 0; j < col2; j++) {
                resultado[i][j] = 0;
                for (int k = 0; k < col1; k++) {
                    resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                }
            }
        }
        return resultado;
    }

    /*Función mainnn */
    public static void main(String[] args) {
        /* long ti=System.nanoTime(); */
        
        
        try {
            double[][] matriz1;
            double[][] matriz2;
            /* int filas1=250,filas2=250,cols1=250,cols2=250; */
            int filas1=0,filas2=0,cols1=0,cols2=0;
            Scanner scanner = new Scanner(System.in);//leer de la consola
            while(true){
                System.out.print("Ingrese el número de filas para la primera matriz: ");
                filas1 = scanner.nextInt();
                System.out.print("Ingrese el número de columnas para la primera matriz: ");
                cols1 = scanner.nextInt();
                System.out.print("Ingrese el número de filas para la segunda matriz: ");
                filas2 = scanner.nextInt();
                System.out.print("Ingrese el número de columnas para la segunda matriz: ");
                cols2 = scanner.nextInt();
                    // no se puede hacer la multiplicacion
                try {
                    if (cols1 != filas2) {
                        System.out.println("El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz");
                        throw new IllegalArgumentException("\nNo se pueden multiplicar las matrices. Vuelva a ingresar las dimensiones");
                    }
                    else {
                        break;
                    }
                } catch (IllegalArgumentException e){
                    System.out.println(e.getMessage());
                }
            } 
            
            matriz1 = generarMatriz(filas1, cols1);
            matriz2 = generarMatriz(filas2, cols2);
            
           
            System.out.println("Primera matriz:");
            imprimirMatriz(matriz1);
            System.out.println("Segunda matriz:");
            imprimirMatriz(matriz2);

            double[][] resultado = multiplicarMatrices(matriz1, matriz2);

            
             // Guardar el resultado en un archivo
             String archivoResultado = "resultado_java.csv";
             escribirMatrizArchivo(resultado, archivoResultado);
 
             System.out.println("El resultado se ha guardado en " + archivoResultado);
             
 
        } catch (IOException e) {
            System.err.println("Error al leer o escribir archivos: " + e.getMessage());
        }
        
    }
    
}
