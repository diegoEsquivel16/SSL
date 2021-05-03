TP N°1

Este trabajo está basado en los ejercicios 1-4 y 1-15 de [KR1988] y aplica los
conceptos presentados en [Interfaces-Make]:
1-4. Escriba un programa para imprimir la tabla correspondiente de
Celsius a Fahrenheit
1-15. Reescriba el programa de conversión de temperatura de la sección
1.2 para que use una función de conversión.
Desarrollar un programa que imprima dos tablas de conversión, una de
Fahrenheit a Celsius y otra de Celsius a Fahrenheit.
6.1. Objetivos
• Aplicar el uso de interfaces y módulos.
• Construir un programa formado por más de una unidad de traducción.
• Comprender el proceso de traducción o Build cuando intervienen varios
archivos fuente.
• Aplicar el uso de Makefile.
15
Temas
6.2. Temas
• Makefile.
• Archivos header (.h).
• Tipo de dato double.
• Funciones.
• Pruebas unitarias.
• assert.
La comparación de los tipos flotantes puede ser no
trivial debido a su representación y precisión.
• Interfaces e Implementación.
6.3. Tareas
1. Escribir el Makefile.
2. Escribir Conversion.h
3. Escribir ConversionTest.c
4. Escribir Conversion.c
5. Escribir TablasDeConversion.c.
6.4. Restricciones
• Las dos funciones públicas deben llamarse Celsius y Farenheit.
• Utilizar assert.
• Utilizar const y no define.
• Utilizar for con declaración (C99).
6.5. Productos
DD-Interfaces
|-- readme.md
|-- Makefile
|-- Conversion.h
16
Productos
|-- ConversionTest.c
|-- Conversion.c
`-- TablasDeConversion.c.
Crédito extra
Desarrolle TablasDeConversion.c para que use
funciones del estilo PrintTablas, PrintTablaCelsius,
PrintTablaFahrenheit, PrintFilas, PrintFila.
Los límites inferior y superior, y el incremento deben ser
parámetros.
Crédito extra
Desarrollar la función PrintFilas para que sea genérica,
es decir, pueda invocarse desde PrintTablaFahrenheit
y desde PrintTablaCelsius. PrintFilas debe invocar a
PrintFila.
Considere el uso de punteros a función