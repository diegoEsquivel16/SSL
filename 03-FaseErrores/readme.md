# TP N°3
## Pasos realizados, sus salidas y analisis de cada paso
#### Primer paso - Preprocesar __hello2.c__ incluyendo bibbioleca estandar
##### Comando ejecutado
- __> gcc hello2.c  -std=c11 -c -o hello2.i__ 
##### Resultado
- Al principio del archivo __hello2.c__ se le define al programa (escribiendo __#include <------.h>__) que utilice la biblioteca estandar de entrada/salida __stdio.h__
- El archivo creado por el preproceso llamado __hello2.i__ contiene los typedef, structs y directivas de la biblioteca estandar. Al final se encuentra el codigo escrito en __hello2.c__ sin los comentarios (que fueron removidos y reemplazados por un espacio)
#### Segundo paso - Preprocesar __hello3.c__ sin incluir biblioteca estandar
##### Comando ejecutado
- __> gcc hello3.c  -std=c11 -c -o hello3.i__ 
##### Resultado
- Se realizo el mismo procedimiento que el paso anterior, pero utilizando el archivo __hello3.c__, generando la salida __hello3.i__
- A diferencia del __hello2.c__ el nuevo archivo no incluye la biblioteca estandar __Stdio.h__, sino solamente un prototipo de la funcion __printf()__ definido por nosotros. El mismo indica que hay una funcion llamada __printf()__ que recibe en su primer argumento un puntero a una constante char (__'const char *s'__) y luego de entre 0 y n argumentos más (identificado por __'...'__). 
- El archivo creado por el preproceso es bastante similar al archivo de entrada, ya que no se copio nada relacionado a la biblioteca estandar, solo la definicion del __printf()__ y el __main()__
#### Tercer paso - Compilar __hello3.i__
##### Comando ejecutado
- __> gcc hello3.i  -std=c11 -S -o hello3.s__ 
##### Resultado
- Hubo un error al tratar de compilar __hello3.i__ : 
    > hello3.c: In function ‘main’:
    > hello3.c:4:1: warning: implicit declaration of function ‘prontf’ [-Wimplicit-function-declaration]
    > prontf("La respuesta es %d\n");
    > ^
    > hello3.c:4:1: error: expected declaration or statement at end of input
- El mismo indica que hay un error de sintaxis (falta un simbolo que cierre el bloque main -> '}')
#### Cuarto paso - Corregir en __hello4.i__ y compilar
##### Comando ejecutado
- __> gcc hello4.c -std=c11 -S -o hello4.s__
##### Resultado
- Al compilar me devuelve la siguiente advertencia:
    > hello4.c: In function ‘main’
    > hello4.c:4:1: warning: implicit declaration of function ‘prontf’ [-Wimplicit-function-declaration]
    > prontf("La respuesta es %d\n");
    > ^
- La misma indica que no se encontró el prototipo de la función __prontf()__, pero que igualmente se pudo realizar la compilación y posterior creación del archivo __hello4.s__
- En el mismo se ve una traducción del codigo C en lenguaje Assembler, se pueden ver las diferentes acciones que se realizan (MOVL, CALL, etc.) para poder mostrar el mensaje por pantalla
#### Quinto paso - Ensamblar __hello4.o__
##### Comando ejecutado
- __> as hello4.s -o hello4.o__
##### Resultado
- Se creo un archivo binario llamado __hello4.o__ el cual contiene una nueva traducción del __hello4.s__ con lenguaje Assembler a código objeto, el cual es entendible por la maquina.
#### Sexto paso - Vincular __hello4.0__ con la biblioteca estandar y genererar ejecutable
##### Comando ejecutado
- __> gcc hello4.o -o hello4 -std=c11__
##### Resultado
-Al querer vincular __hello4.o__ se produce el siguiente error, impidiendo que se cree un archivo ejecutable:
>hello4.o: In function `main':
> hello4.c:(.text+0x1a): undefined reference to `prontf'
> collect2: error: ld returned 1 exit status
- El cual indica que no hay ninguna referencia a una funcion llamada __'prontf()'__, tanto en el codigo escrito como en la biblioteca estandar.
#### Septimo paso - Corregir __prontf()__ en __hello5.c__ y generar ejecutable
##### Comando ejecutado
- __> gcc hello5.c -o hello5 -std=c11__
##### Resultado
-Al crear el ejecutable se mostro el siguiete mensaje de advertencia:
> hello5.c: In function ‘main’:
> hello5.c:4:8: warning: format ‘%d’ expects a matching ‘int’ argument [-Wformat=]
> printf("La respuesta es %d\n");
_ El cual indica que la llamada a __printf()__ esperaba un argumento mas del tipo __'int'__ segun indica el primer argumento al poner el token __"%d"__
#### Octavo paso - Correr archivo ejectutable __hello5__
##### Comando ejecutado
- __> ./hello5__
##### Resultado
- Al ejecutar el archivo creado, el resultado del mismo fue: 
    > La respuesta es 1219149656
-Como no se paso un argumento del tipo __"int"__ al llamar al __printf()__
la misma fue completado con "información basura"
#### Noveno paso - Corregir en __hello6.c__ y generar ejectutable
##### Comando ejecutado
- __> gcc hello6.c -o hello6 -std=c11__
- __> ./hello6__
##### Resultado
- Luego de crear el ejecutable __hello6__ se corrio el mismo y mostro el siguiente mensaje por pantalla: 
    > La respuesta es 42
- Finalmente se mostró el mensaje que se pedia en un principio.
