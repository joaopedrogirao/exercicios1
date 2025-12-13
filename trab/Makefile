all: codificador decodificador

# Gera o Codificador
codificador: encoder.o imagelib.o
	gcc encoder.o imagelib.o -o codificador

# Gera o Decodificador
decodificador: decoder.o imagelib.o
	gcc decoder.o imagelib.o -o decodificador

# Compilação dos objetos
encoder.o: encoder.c imagelib.h
	gcc -c encoder.c

decoder.o: decoder.c imagelib.h
	gcc -c decoder.c

imagelib.o: imagelib.c imagelib.h
	gcc -c imagelib.c

clean:
	rm -f *.o codificador decodificador bitstream.bin imagem_reconstruida.pgm