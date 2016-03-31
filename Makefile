all: ejecuta run

ejecuta: compilar
	g++ -o main main.cpp *.o -lGL -lGLU -lglut -lm

compilar: Cuadrilatero.cpp Linea.cpp Punto.cpp Circulo.cpp Triangulo.cpp Render.cpp 
	g++ -c Cuadrilatero.cpp Linea.cpp Punto.cpp Circulo.cpp Triangulo.cpp Render.cpp

clean:
	rm main *.o

run:
	./main
