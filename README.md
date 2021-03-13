# Puzlee hijoputa que se escribe puzzle xD <3

# Implementacion
*Una imagen consta de una matriz de dígitos1 (unsigned char) que representan los índices de una paleta de 10 colores definida en el módulo UtilidadesSYS que se proporciona. Cada imagen tiene una resolución que establece el número de filas y de columnas de la matriz, ambas entre 0 y DIM_MAX. Define la constante DIM_MAX a 64, y la estructura tMatrizChar para representar las imágenes. La imagen no es necesariamente cuadrada. Define el tipo tCoor para estructurar la información de la posición de los elementos de la matriz. Debes definir cada tipo en su módulo: Matriz y Coordenada.En el módulo JuegoPM se define el tipo tJuegoPM para estructurar los elementos del juego: las imágenes, el número máximo de acciones y el modo.*

# Módulos

## Coordenada
- **bool operator == (tCoor c1, tCoor c2)**: compara si dos coordenadas son iguales.
- **bool operator != (tCoor c1, tCoor c2)**: compara si dos coordenadas son distintas.
- **tCoor operator + (tCoor c1, tCoor c2)**: devuelve la coordenada resultante de sumar las dos coordenadas dadas por parámetros.

## Matriz
- **bool cargar(tMatrizChar & mat, istream & ent)**: carga en la matriz los datos dados mediante el flujo de entrada. Devuelve falso si se produce un error en la lectura de los datos.
- **bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2)**: compara si las dos matrices son iguales.
- **bool swap(tMatrizChar & mat, tCoor pos1, tCoor pos2)**: intercambia las coordenadas pos1 y pos2 de la matriz. Devuelve falso si las posiciones no pertenecen al rango de la matriz.
- **bool swapF(tMatrizChar & mat, int f1, int f2)**: intercambia las filas f1 y f2 de la matriz. Devuelve falso si las filas no pertenecen al rango de la matriz.
- **bool swapC(tMatrizChar & mat, int c1, int c2)**: intercambia las columnas c1 y c2. Devuelve falso si las columnas no pertenecen al rango de la matriz.
- **bool swapD(tMatrizChar & mat, int d)**: intercambia las diagonales d y -d. Devuelve falso si las diagonales no pertenecen al rango de la matriz, o si la matriz no es cuadrada.
- **bool voltearF(tMatrizChar & mat, int f)**: dar la vuelta a la fila f con respecto al eje vertical central de la imagen. Devuelve falso si la fila no pertenece al rango de la matriz.
- **bool voltearC(tMatrizChar & mat, int c)**: dar la vuelta a la columna c con respecto al eje horizontal central de la imagen. Devuelve falso si la columna no pertenece al rango de la matriz.
- **bool voltearD(tMatrizChar & mat, int d)**: dar la vuelta a la diagonal d con respecto al centro de eje perpendicular de dicha diagonal. Devuelve falso si la diagonal no pertenece al rango de la matriz o si la matriz no es cuadrada.
- **void voltearV(tMatrizChar & mat)**: dar la vuelta a la imagen completa con respecto a su eje vertical central.
- **void voltearH(tMatrizChar & mat)**: dar la vuelta a la imagen completa con respecto a su eje horizontal central.
- **void rotarD(tMatrizChar & mat)**: rotar una imagen 90 grados en el sentido de las agujas del reloj.
- **bool swapAdy(tMatrizChar & mat, tCoor pos1, tCoor pos2)**: intercambiar las celdas vecinas o adyacentes de las posiciones pos1 y pos2.
- **bool VoltearID(tMatrizChar & mat)**: Voltear la imagen completa respecto a la diagonal principal. Devuelve falso si la matriz no es cuadrada.

## JuegoPM
- **void mainJuegoPM()**: función principal del juego.
- **int menu()**: menú para seleccionar el tipo de juego (1 o 2) o salir (0).
- **bool iniciar(tJuegoPM & jpm, string modo)**: inicia los parámetros del juego que correspondan y llama a la función cargar definida a continuación.
- **bool cargar(tJuegoPM & jpm)**: abre el fichero que corresponda y llama a la función cargar del módulo Matriz.
- **void mostrar(tJuegoPM const& jpm)**: muestra el estado del reto utilizando las facilidades del módulo utilidadesSYS. Debe mostrar primero la imagen que se está modificando y a continuación la imagen objetivo. Debe mostrar también el número de intentos que quedan.
- **bool jugar(tJuegoPM & jpm)**: permite realizar las acciones necesarias para jugar y controla si se ha llegado al límite de acciones permitidas;
- **void accion(tJuegoPM & jpm)**: según el comando de acción tecleado por el usuario, llama a la acción correspondiente definida en el módulo Matriz.

## UtilidadesSYS
Incluido ya jeje
