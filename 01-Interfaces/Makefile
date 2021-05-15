flags= -std=c99 -Wno-missing-prototypes
rm = rm -rf
CC = gcc

.PHONY: clean run

TablasDeConversion: TablasDeConversion.o Conversion.o
	$(CC) TablasDeConversion.o Conversion.o -o TablasDeConversion $(flags)

ConversionTest: ConversionTest.o Conversion.o
	$(CC) ConversionTest.o Conversion.o -o ConversionTest $(flags)

ConversionTest.o: Conversion.h
	$(CC) -c ConversionTest.c -o ConversionTest.o $(flags)

TablasDeConversion.o: Conversion.h
	$(CC) -c TablasDeConversion.c -o TablasDeConversion.o $(flags)

Conversion.o: Conversion.h
	$(CC) -c Conversion.c -o Conversion.o $(flags)

clean: 
	$(rm) *.o
	$(rm) $(TARGET)
