import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Comparator;

public class FrecuenciaPalabras {

    public static void main(String[] args) {
        String arch = "texto.txt";
        Map<String, Integer> contador_palabra = new HashMap<>();
        //leer el archivo de palabras y agregarlas al hashmap
        try (BufferedReader br = new BufferedReader(new FileReader(arch))) {
            String linea;
            while ((linea = br.readLine()) != null) {
                String[] palabras = linea.split("\\W+");
                for (String palabra : palabras) {
                    if (palabra.isEmpty()){
                        continue; 
                    }
                    palabra = palabra.toLowerCase(); 
                    //el valor por defecto es cero y se le suma uno ,si ya existe, solo le suma uno a su contador
                    contador_palabra.put(palabra, contador_palabra.getOrDefault(palabra, 0) + 1);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        //se utiliza una cola de prioridad para insertar los palabras de forma ordenadas descendentemente con respecto a su frecuencia y luego se hace pop de los primeros 10 elementos
        PriorityQueue<Map.Entry<String, Integer>> cola = new PriorityQueue<>(
            new Comparator<Map.Entry<String, Integer>>() {
                @Override
                public int compare(Map.Entry<String, Integer> e1, Map.Entry<String, Integer> e2) {
                    return e2.getValue().compareTo(e1.getValue());
                }
            }
        );

        cola.addAll(contador_palabra.entrySet());

        System.out.println("Las 10 palabras más frecuentes son:");
        for (int i = 0; i < 10 && !cola.isEmpty(); i++) {
            Map.Entry<String, Integer> entry = cola.poll();
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}
/* https://www.geeksforgeeks.org/using-priorityqueue-to-have-sorted-collection-of-data-in-java/ https://www.freecodecamp.org/news/priority-queue-implementation-in-java/
 * 
*/
