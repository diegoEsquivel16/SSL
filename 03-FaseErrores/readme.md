# TP N°3
## Pasos realizados, sus salidas y analisis de cada paso
### - 1 Preprocesador
#### Preprocesar __hello2.c__ incluyendo bibbioleca estandar
##### Comando ejecutado
- __> gcc hello2.c  -std=c11 -E -o hello2.i__ 
##### Resultado
- Al principio del archivo __hello2.c__ se le define al programa (escribiendo __#include <------.h>__) que utilice la biblioteca estandar de entrada/salida __stdio.h__
- El archivo creado por el preproceso llamado __hello2.i__ contiene los typedef, structs y directivas de la biblioteca estandar. Al final se encuentra el codigo escrito en __hello2.c__ sin los comentarios (que fueron removidos y reemplazados por un espacio)

#### Preprocesar __hello3.c__ sin incluir biblioteca estandar sino una definición propia

##### Semantica de __int printf(const char * restrict s, ...);__
- Es una funcion que se llama printf que recibe un const char y una lista variable de argumentos mas. Y retorna un entero

##### Comando ejecutado
- __> gcc hello3.c  -std=c11 -E -o hello3.i__ 

##### Resultado
- Se realizo el mismo procedimiento que el paso anterior, pero utilizando el archivo __hello3.c__, generando la salida __hello3.i__
- El archivo creado por el preproceso es bastante similar al archivo de entrada, ya que no se copio nada relacionado a la biblioteca estandar, solo la definicion del __printf()__ y el __main()__ (solo se agregaron comentarios en la cabecera)

### - 2 Compilador

#### Compilar __hello3.i__

##### Comando ejecutado
- __> gcc hello3.i  -std=c11 -S -o hello3.s__ 

##### Resultado

- Hubo un error al tratar de compilar __hello3.i__ : 
    > hello3.c: In function ‘main’:
    > hello3.c:5:2: warning: implicit declaration of function ‘prontf’; did you mean ‘printf’? [-Wimplicit-function-declaration]
    > prontf("La respuesta es %d\n");
    > ^~~~~
    > hello3.c:5:2: error: expected declaration or statement at end of input
- El mismo indica que hay un error de sintaxis (falta un simbolo que cierre el bloque main -> '}')

####  Corregir en __hello4.c__ y compilar

##### Comando ejecutado
- __> gcc hello4.c  -std=c11 -E -o hello4.i__ 
- __> gcc hello4.c -std=c11 -S -o hello4.s__

##### Resultado

- Al compilar me devuelve la siguiente advertencia:
    > hello4.c: In function ‘main’
    > hello4.c:5:2: warning: implicit declaration of function ‘prontf’; did you mean ‘printf’? [-Wimplicit-function-declaration]
    > prontf("La respuesta es %d\n");
    > ^~~~~
    > printf
- La misma indica que no se encontró el prototipo de la función __prontf()__, pero que igualmente se pudo realizar la compilación y posterior creación del archivo __hello4.s__
- En el mismo se ve una traducción del codigo C en lenguaje Assembler, se pueden ver las diferentes acciones que se realizan (MOVL, CALL, etc.) para poder mostrar el mensaje por pantalla

#### Ensamblar __hello4.s__ en __hello4.o__

##### Comando ejecutado

- __> as hello4.s -o hello4.o__

##### Resultado

- Se creo un archivo binario llamado __hello4.o__ el cual contiene una nueva traducción del __hello4.s__ con lenguaje Assembler a código objeto, el cual es entendible por la maquina.

### - 3 Vinculador

#### Vincular __hello4.0__ con la biblioteca estandar y genererar ejecutable

##### Comando ejecutado

- __> gcc hello4.o -o hello4 -std=c11__

##### Resultado

- Al querer vincular __hello4.o__ se produce el siguiente error, impidiendo que se cree un archivo ejecutable:
    > /usr/bin/ld: hello4.o: en la función 'main':
    > hello4.c:(.text+0x20): referencia a 'prontf' sin definir
    > collect2: error: ld returned 1 exit status

- El cual indica que no hay ninguna referencia a una funcion llamada __'prontf()'__, tanto en el codigo escrito como en la biblioteca estandar.

#### Corregir __prontf()__ en __hello5.c__ y generar ejecutable

##### Comando ejecutado

- __> gcc hello5.c -o hello5 -std=c11__

##### Resultado

- Al crear el ejecutable se mostro el siguiete mensaje de advertencia:
    > hello5.c: In function 'main':
    > hello5.c:5:27: warning: format '%d' expects a matching ‘int’ argument [-Wformat=]
    > 5 |  printf("La respuesta es %d\n");
    >  |                          ~^
    >  |                           |
    >  |                           int

- El cual indica que la llamada a __printf()__ esperaba un argumento mas del tipo __'int'__ segun indica el primer argumento al poner el token __"%d"__

#### Correr archivo ejectutable __hello5__

##### Comando ejecutado

- __> ./hello5__

##### Resultado

- Al ejecutar el archivo creado, el resultado del mismo fue: 
    > La respuesta es 1567474008
- Como no se pasó un argumento del tipo __"int"__ al llamar al __printf()__
la misma fue completado con "información basura"

### - 4 Corrección del big

#### Corregir en __hello6.c__ y generar ejectutable

##### Comando ejecutado

- __> gcc hello6.c -o hello6 -std=c11__
- __> ./hello6__

##### Resultado

- Luego de crear el ejecutable __hello6__ se corrio el mismo y mostro el siguiente mensaje por pantalla: 
    > La respuesta es 42
- Finalmente se mostró el mensaje que se pedia en un principio.

### - 5 Remoción del prototipo
##### Comando ejecutado

- __> gcc hello7.c -o hello7 -std=c11__
- __> ./hello7__

##### Resultado

- Luego de crear el ejecutable __hello7__ sin el prototipo de __printf()__ surgió el sigueinte warning:
    > hello7.c: In function ‘main’:
    > hello7.c:3:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    > 3 |  printf("La respuesta es %d\n", i);
    >  |  ^~~~~~
    > hello7.c:3:2: warning: incompatible implicit declaration of built-in function ‘printf’
    > hello7.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
    > +++ |+#include <stdio.h>
    > 1 | int main(void){
- El mismo indica que hay una decalración implícita de la función _'printf'_ y que se debería incluir la biblioteca _'stdio.h'_ o proveer una declaración de la función _'printf'_
- Luego se corrió el mismo y mostro el siguiente mensaje por pantalla: 
    > La respuesta es 42
- El programa anda porque se agrega automaticamente la biblioteca _'stdio.h'_, de esta manera se puede vincular a la función _'printf'_ de manera correcta.

### - 6 Compilación Separada: Contratos y Módulos 
##### Comando ejecutado
- __>gcc hello8.c studio1.c -o hello8__
- __>hello8__

##### Resultado
- Se generó el ejecutabel hello8 sin errores, pero con los siguientes warnings:
    > hello8.c: In function ‘main’:
    > hello8.c:3:2: warning: implicit declaration of function ‘prontf’ [-Wimplicit-function-declaration]
    > 3 |  prontf("La respuesta es %d\n", i);
    >   |  ^~~~~~
    > studio1.c: In function ‘prontf’:
    > studio1.c:2:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    > 2 |  printf("La respuesta es %d\n", i);
    >   |  ^~~~~~
    > studio1.c:2:2: warning: incompatible implicit declaration of built-in function ‘printf’
    > studio1.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
    >   +++ |+#include <stdio.h>
    >     1 | void prontf(const char* s, int i){
- Lo que indican es que hay funciones declaradas de manera implícita tanto en 'hello8.c' como en 'studio1.c'
- Al ejecutar el programa se muestra correctamente el mensaje: 
    > La respuesta es 42
- El programa funciona correctamente porque se compilaron ambos archivos de manera conjunta haciendo posible que se encuentre una implementación de la función 'prontf' además de la inclusión automática de la biblioteca 'stdio.h'
- Si se eliminan argumentos en la invocación a 'prontf' ocurre que se utiliza igualmente la implementación de 'studio1.c' y usando valores que desconocemos o "información basura"
- Si se llaman con argumentos de más se terminan ignorando los mismos y la función responde igualmente de manera correcta (no entiendo porqué)

- Cuando compilamos la version incluyendo el contrato de 'studio.h' lo que logramos es que el compilador se asegura que la función 'prontf' sea invocada con los argumentos declarados en el contrato. En caso de que se llamen con mas o menos argumentos no se genera ningún ejecutable y se muestra por pantalla el siguiente error de compilación:
- Argumentos de más: 
    > hello9.c: In function ‘main’:
    > hello9.c:5:2: error: too many arguments to function ‘prontf’
    >    5 |  prontf("La respuesta es %d\n", i, 12312);
    >      |  ^~~~~~
    > In file included from hello9.c:1:
    > studio.h:4:6: note: declared here
    >     4 | void prontf(const char*, int);
    >       |      ^~~~~~
- Argumentos de menos:
    > hello9.c: In function ‘main’:
    > hello9.c:5:2: error: too few arguments to function ‘prontf’
    >     5 |  prontf("La respuesta es %d\n");
    >       |  ^~~~~~
    > In file included from hello9.c:1:
    > studio.h:4:6: note: declared here
    >     4 | void prontf(const char*, int);
    >       |      ^~~~~~ 

