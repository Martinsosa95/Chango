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

        //Pre:El objeto gondola debe existir y el parametro debe ser un entero mayor o igual a cero
    	//Post:Se modifico el atributo producto_seleccionado del chango
        void asignar_seleccion(int seleccion);

        //Pre:El objeto gondola debe existir y el vector de productos debe estar cargado
        //Post:Devuelve el productos guardado en la posicion producto_seleccionado de la gondola
        Producto obtener_producto() const;

        //Pre:El objeto gondola debe existir
    	//Post:Devuelve el valor del atributo producto_seleccionado
        int obtener_producto_seleccionado();

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
		//Pos:Va a devolver la posicion del producto en el vector gondola si es que se encuentra en la gondola y se muestra por pantalla sus datos.
		int buscar_nombre(string nombre);
		//Pre:Tiene que estar creado el objeto gondola.
		//Pos:Va a devolver la posicion del producto en el vector gondola si es que se encuentra en la gondola y se muestra por pantalla sus datos
		int buscar_codigo(int codigo);
		//Pre:Tiene que estar creado el objeto gondola.
		//Pos:Va a "eliminar" los productos del producto deseado.
		void quitar_producto(Producto producto);
		//Descripcion:Destructor de la gondola
		//Pre:La gondola debe existir.
		//Post:La gondola fue destruida,es decir la memoria utilizada fue liberada.
		~Gondola();
};


#endif // GONDOLA_H
