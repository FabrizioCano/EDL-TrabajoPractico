class PalabraFrecuencia
  attr_accessor :palabra, :cont, :next

  def initialize(palabra, count = 1)
    @palabra = palabra
    @cont = count
    @next = nil
  end
end

def insertar_palabra(head, palabra)
  if head.nil?
    return PalabraFrecuencia.new(palabra)
  end

  actual = head
  while actual
    if actual.palabra == palabra
      actual.cont += 1
      return head
    end
    if actual.next.nil?
      break
    end
    actual = actual.next
  end

  actual.next = PalabraFrecuencia.new(palabra)
  head
end

def imprimir_mas_frecuentes(head, n)
  lista_palabra = []
  actual = head
  while actual
    lista_palabra << actual
    actual = actual.next
  end

  # Ordenar la lista por frecuencia de mayor a menor
  lista_palabra.sort_by! { |x| -x.cont }

  # Imprimir las n palabras más frecuentes
  lista_palabra.first(n).each do |palabra_freq|
    puts "#{palabra_freq.palabra}: #{palabra_freq.cont}"
  end
end


archivo = "texto.txt"
cont_pal = {}

begin
  File.foreach(archivo) do |linea|
    palabras = linea.split
    palabras.each do |palabra|
      palabra = palabra.downcase # Convertir a minúsculas
      if cont_pal.key?(palabra)
        cont_pal[palabra] += 1
      else
        cont_pal[palabra] = 1
      end
    end
  end
rescue Errno::ENOENT
  puts "Error: archivo '#{archivo}' no encontrado"
  exit 1
rescue IOError
  puts "Error: no se pudo leer el archivo '#{archivo}'"
  exit 1
end

# Crear la lista enlazada de objetos PalabraFrecuencia
head = nil
cont_pal.each do |palabra, count|
  if head.nil?
    head = PalabraFrecuencia.new(palabra, count)
  else
    actual = head
    while actual.next
      actual = actual.next
    end
    nuevo = PalabraFrecuencia.new(palabra, count)
    actual.next = nuevo
  end
end

# Imprimir las 10 palabras más frecuentes
imprimir_mas_frecuentes(head, 10)


=begin https://medium.com/analytics-vidhya/implement-a-linked-list-in-ruby-2aae925acd9c 
https://dev.to/mwong068/introduction-to-linked-lists-in-ruby-kgi
=end
