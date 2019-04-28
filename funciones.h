#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include "Producto.h"
#include "Gondola.h"
#include "Chango.h"

//Pre:Se debe haber podido abrir el archivo.
//Pos:Se devolvera la cantidad total de productos que se encuentren en el archivo leido.
int calcular_cant_productos(ifstream &archivo);
//Pre:Se debe haber podido calcular la cantidad de productos.
//Pos:Se va a devolver una gondola creada con memoria dinamica.
Gondola crear_gondola(int cant_productos);
//Pre:Debe estar creada una gondola.
//Pos:Se ca a devolver el producto que se queria buscar.
void cargar_gondola(ifstream &archivo, Gondola gondola);

Producto tipo_busqueda(Gondola gondola);
//Pre:Se debe encontrar el producto al cual se desea modificar su precio.
//Pos:Se va a mostrar por pantalla el producto con el precio modificado.
void modificar_precio(Producto producto_a_modificar);
//Pre:Debe estar creada una gondola.
//Pos:Se va a devolver la cantidad de productos que estan en oferta.
int cantidad_en_oferta(Gondola gondola);

#endif // FUNCIONES_H
