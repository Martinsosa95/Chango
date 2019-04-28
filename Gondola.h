#ifndef GONDOLA_H
#define GONDOLA_H


#include "Producto.h"

using namespace std;

class Gondola{

	private:
		int cant_productos;
		Producto* productos;
		int producto_seleccionado;
	public:
		//Descripcion: constructor por parametros
		//Pre: ---
		//Pos: se creo la gondola con los valores indicados en los parametros.
		Gondola(int nueva_cant_productos);

        void asignar_seleccion(int seleccion);
        Producto obtener_producto();
		//Pre:Se debe poder leer el archivo ingresado con el formato debido,es decir debera tener un producto por linea.
		//Pos:Devuelve la cantidad total de productos leidos del archivo.
		void asignar_cant_productos(int cantidad);
		//Pre:Se debe poder crear un producto para poder ingresarlos los nuevos productos en gondola y el valor del parametro debe mayor o igual a 0.
		//Pos:Se asigna una nueva direccion de memoria apuntanto hacia nuevos_productos.
		void asignar_productos(Producto* nuevos_productos);
		//Pre:Tiene que estar creado el objeto gondola.
		//Pos:Devuelve la cantidad de productos que tiene la gondola.
		int obtener_cant_productos();
		//Pre:Tiene que estar creado el objeto gondola.
		//Pos:Devuelve el puntero a los productos de la gondola.
		Producto* obtener_productos();
		//Pre:Tiene que estar creado el objeto gondola.
		//Pos:Va a devolver la informacion completa del producto si es que se encuentra en la gondola.
		Producto buscar_nombre(string nombre);
		//Pre:Tiene que estar creado el objeto gondola.
		//Pos:Va a devolver la informacion completa del producto si es que se encuentra en la gondola.
		Producto buscar_codigo(int codigo);
		//Pre:Tiene que estar creado el objeto gondola.
		//Pos:Va a "eliminar" los productos del producto deseado.
		void quitar_producto(Producto producto);
		//Descripcion:Destructor de la gndola
		//Pre:La gondola debe existir
		//Post:La gondola fue destruida,es decir la memoria utilizada fue liberada
		~Gondola();
};


#endif // GONDOLA_H
