require 'csv'

#funcion para multiplicar las matrices
def multiplicar_matrices(a,b)
    fila=a.length #N1
    col=b.length #M1
    colnew=b[0].length #M2
    c=Array.new(fila) {Array.new(colnew) {0.0}}
    for j in 0...fila
        for k in 0...colnew
            for l in 0...col
                c[k][j]+=a[k][l]*b[l][j]
            end
        end
    end
    return c
end

#programa principal
i=0
suma=0.0
while(i!=1)
    begin
        puts "Ingrese la cantidad de filas y columnas de la matriz 1:\n "
        N1=gets.chomp.to_i
        N2=gets.chomp.to_i
        puts "Ingrese la cantidad de filas y columnas de la matriz 2:\n "
        M1=gets.chomp.to_i
        M2=gets.chomp.to_i

        
        raise "Las matrices no pueden ser multiplicadas. Vuelva a ingresar las dimensiones\n" unless M1==N2
        i=1 # si se pueden multiplicar esto indicaria que el ciclo se termina 
    rescue => e
        puts e.message
    end
end

=begin M1=250
M2=250
N1=250
N2=250 
=end
a=Array.new(N1) {Array.new(N2) {rand (5..15)}}
b=Array.new(M1) {Array.new(M2) {rand (5..15)}}
CSV.open("matriz_rubyA.csv","w") do |linea|
    a.each do |palabra|
         linea << palabra
     end
 end
CSV.open("matriz_rubyB.csv","w") do |linea|
    b.each do |palabra|
         linea << palabra
     end
 end 


c=multiplicar_matrices(a,b)

#cargar el resultado de la multiplicacion al archivo de salida
CSV.open("matriz_ruby.csv","w") do |linea|
   c.each do |palabra|
        linea << palabra
    end
end
puts ("El resultado se ha guardado en matriz_ruby.csv")
        

    


    
