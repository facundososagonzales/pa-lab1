OTH=main.o
CLASS=class/Puerto.o class/Arribo.o class/Barco.o class/BarcoPesquero.o class//BarcoPasajeros.o
DATATYPE=dataTypes/DtBarco.o dataTypes/DtFecha.o dataTypes/DtBarcoPesquero.o dataTypes/DtBarcoPasajero.o
EXEC=exe
OBJ=$(OTH) $(CLASS) $(DATATYPE)

main: $(OBJ) 
	g++ $(OBJ) -o $(EXEC)
	find . -name '*.o' -delete
	clear
	./$(EXEC)

class/Puerto.o: class/Puerto.cpp
class/Arribo.o: class/Arribo.cpp
class/Barco.o: class/Barco.cpp
class/BarcoPesquero.o: class/BarcoPesquero.cpp
class//BarcoPasajeros.o: class//BarcoPasajeros.cpp
dataTypes/DtBarco.o: dataTypes/DtBarco.cpp
dataTypes/DtBarcoPesquero.o: dataTypes/DtBarcoPesquero.cpp
dataTypes/DtBarcoPasajero.o: dataTypes/DtBarcoPasajero.cpp
dataTypes/DtFecha.o: dataTypes/DtFecha.cpp
main.o: main.cpp

clean:
	rm -rf $(EXEC)
	find . -name '*.o' -delete
	clear