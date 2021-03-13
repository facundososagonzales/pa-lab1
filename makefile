OTH=main.o
CLASS=class/Puerto.o 
DATATYPE=dataTypes/DtBarco.o dataTypes/DtFecha.o
EXEC=exe
OBJ=$(OTH) $(CLASS) $(DATATYPE)

main: $(OBJ) 
	g++ $(OBJ) -o $(EXEC)
	find . -name '*.o' -delete
	./$(EXEC)
	clear

class/Puerto.o: class/Puerto.cpp
dataTypes/DtBarco.o: dataTypes/DtBarco.cpp
dataTypes/DtFecha.o: dataTypes/DtFecha.cpp
main.o: main.cpp

clean:
	rm -rf $(EXEC)
	clear