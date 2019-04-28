#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <cstring>

using namespace std;


class Producto{

private:
	string nombre;
	int codigo;
	int precio;
	bool en_oferta;
public:
	//Descripcion:Constructor por defecto
	//Pre: ---
	//Post:crea un objeto producto,asignando el valor 0 a codigo,precio y en_oferta,y coloca un " " en nombre
	Producto();

	//Descripcion:Constructor con parametros
	//Pre: los parametros codigo y precio introducidos deben ser enteros mayores a 0
	//Post:crea un objeto producto,asignando a cada atributo los parametros pasados
	Producto(string nuevo_nombre,int nuevo_codigo,int nuevo_precio,bool nuevo_en_oferta);

	Producto &operator=(Producto &p);

	//Pre:El objeto producto debe existir
	//Post:Devuelve el nombre del producto
	string obtener_nombre();

	//Pre:El objeto producto debe existir
	//Post:Devuelve el codigo del producto
	int obtener_codigo();

	//Pre:El objeto producto debe existir
	//Post:Devuelve el precio del producto
	int obtener_precio();

	//Pre:El objeto producto debe existir
	//Post:Devuelve si el producto esta en oferta o no
	bool obtener_oferta();

	//Pre:El objeto producto debe existir
	//Post:Se cambio el nombre del objeto por nuevo_nombre
	void asignar_nombre(string nuevo_nombre);

	//Pre:El objeto producto debe existir y el parametro debe ser un entero mayor o igual a cero
	//Post:Se cambio el codigo del objeto por nuevo_codigo
	void asignar_codigo(int nuevo_codigo);

	//Pre:El objeto producto debe existir y el parametro debe ser un entero mayor o igual a cero
	//Post:Se cambio el precio del objeto por nuevo_precio
	void asignar_precio(int nuevo_precio);

	//Pre:El objeto producto debe existir y el parametro debe ser un entero mayor o igual a cero
	//Post:Se cambio el estado de oferta del objeto por nuevo_en_oferta
	void asignar_oferta(bool nuevo_en_oferta);

	//Descripcion:Calcula el precio de venta del producto
	//Pre:El objeto producto debe existir
	//Post:Devuelve el precio de venta del producto,es decir, el 90% de su precio si esta en oferta o el 100% en caso contrario
	int calcular_precio_final();

};


#endif // PRODUCTO_H
