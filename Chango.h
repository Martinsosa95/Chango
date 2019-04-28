#ifndef CHANGO_H
#define CHANGO_H

#include "Producto.h"

using namespace std;

class Chango{

private:
	int cant_productos;
	Producto *productos;
	int producto_seleccionado;
public:
	//Descripcion:Constructor con parametros
	//Pre:nueva_cant_productos debe ser un entero mayor o igual a cero y menor o igual al tamanio de la gondola
	//Post:crea un objeto chango,del tamanio pasado por parametro
	Chango(int nueva_cant_productos);

	//Pre:El objeto chango debe existir
	//Post:Devuelve la cantidad de productos en el chango
	int obtener_cant_productos();

	//Pre:El objeto chango debe existir
	//Post:Devuelve el puntero a los productos del chango
	Producto* obtener_productos();
    int obtener_producto_seleccionado();
    void asignar_seleccion_producto(int seleccion);
	//Pre:El objeto chango debe existir y el parametro debe ser un entero mayor o igual a 0 y menor o igual al tamanio de la gondola
	//Post:Se cambio la cantidad de productos del chango
	void asignar_cant_productos(int nueva_cant_productos);

	//Pre:El objeto chango debe existir
	//Post:Se cambio el puntero de productos del chango        //NO SABEMOS EN QUE CASO SE USARIA//
	void asignar_productos(Producto* nuevos_productos);

	//Pre:El chango y el producto a agregar deben existir
	//Post:El producto fue agregado al chango
	void cargar_producto(Producto producto_a_cargar);

	//Pre:El chango debe existir
	//Post:Devuelve la suma de los precios finales de los productos del chango
	int monto_a_pagar();

	//Pre:El chango debe existir
	//Post:Devuelve el ahorro total de la compra
	int ahorro_total();

	//Pre:El parametro debe ser la cantidad de productos que hay en la gondola,que sera el tope del vector de productos del chango
	//Posr:deuelve true si el chango esta lleno o false en caso contrario
	bool esta_lleno(int cant_prod_gondola);

	//Descripcion:Destructor del chango
	//Pre:El chango debe existir
	//Post:El chango fue destruido,es decir la memoria utilizada fue liberada
	~Chango();

};

#endif // CHANGO_H
