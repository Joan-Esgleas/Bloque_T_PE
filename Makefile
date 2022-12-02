all: Medir_y_buscar_un_arbol.exe

Medir_y_buscar_un_arbol.exe: Medir_y_buscar_un_arbol.cc BinTreeIO.o
	g++ -o Medir_y_buscar_un_arbol.exe Medir_y_buscar_un_arbol.cc BinTreeIO.o

BinTreeIO.o: BinTreeIO.cc
	g++ -c BinTreeIO.cc

clean:
	rm *.o
	rm *.exe

tar: BinTree.hh BinTreeIO.hh BinTreeIO.cc BinTreeIO.o Medir_y_buscar_un_arbol.cc Medir_y_buscar_un_arbol.exe Makefile
	tar -cvf Programa_PE.tar BinTree.hh BinTreeIO.hh BinTreeIO.cc BinTreeIO.o Medir_y_buscar_un_arbol.cc Medir_y_buscar_un_arbol.exe Makefile