#include "Gondola.h"


Gondola::Gondola(int nueva_cant_productos){
	cant_productos = nueva_cant_productos;
	productos = new Producto[nueva_cant_productos];
	producto_seleccionado = 0;
}

void Gondola::asignar_seleccion(int seleccion){
    if(seleccion >= 0)
        producto_seleccionado = seleccion;
}

void Gondola::asignar_cant_productos(int cantidad){
	cant_productos = cantidad;
}

void Gondola::asignar_productos(Producto* nuevos_productos){
	productos[producto_seleccionado].igualar_productos(*nuevos_productos);
}

int Gondola::obtener_producto_seleccionado(){
    return producto_seleccionado;
}

int Gondola::obtener_cant_productos(){
	return cant_productos;
}

Producto* Gondola::obtener_productos(){
	return productos;
}

Producto Gondola::obtener_producto() const{
    return productos[producto_seleccionado];
}

int Gondola::buscar_nombre(string nombre){
	int pos_producto;
	bool esta = false;

	for(int i=0;i<cant_productos;i++){
		if(productos[i].obtener_nombre() == nombre){
			pos_producto = i;
			esta = true;
		}
	}
	if(esta){
		cout<<"el producto esta disponible en la gondola"<<endl;
        cout<<"nombre: "<< productos[pos_producto].obtener_nombre() <<endl;
        cout<<"codigo: "<< productos[pos_producto].obtener_codigo() <<endl;
        cout<<"precio: "<< productos[pos_producto].obtener_precio() << " $"<<endl;
        cout<<"esta en oferta? (1/0): "<< productos[pos_producto].obtener_oferta() <<endl;

        return pos_producto;
    }else{
		cout<< "El producto no se encuentra en la gondola"<< endl;
		return -1; // que devovler cuando no esta?
	}
}

int Gondola::buscar_codigo(int codigo){
	int pos_producto;
	bool esta = false;

	for(int i=0;i<cant_productos;i++){
		if(productos[i].obtener_codigo() == codigo){
			pos_producto = i;
			esta = true;
		}
	}
	if(esta){
		cout<<"el producto esta disponible en la gondola"<<endl;
        cout<<"nombre: "<< productos[pos_producto].obtener_nombre() <<endl;
        cout<<"codigo: "<< productos[pos_producto].obtener_codigo() <<endl;
        cout<<"precio: "<< productos[pos_producto].obtener_precio() << " $"<<endl;
        cout<<"esta en oferta? (1/0): "<< productos[pos_producto].obtener_oferta() <<endl;

        return pos_producto; // preguntar si esta bien devolver algo tipo producto.
	}else{
		cout<< "El producto no se encuentra en la gondola"<< endl;
		return -1;
	}

}

void Gondola::quitar_producto(Producto producto){
	string nombre_eliminado = "-----";
	int codigo_eliminado = 0;
	int precio_eliminado = 0;
	bool oferta_eliminada = 0;

	producto.asignar_nombre(nombre_eliminado);
	producto.asignar_codigo(codigo_eliminado);
	producto.asignar_precio(precio_eliminado);
	producto.asignar_oferta(oferta_eliminada);
    cant_productos--;

    cout<< "El producto fue eliminado de la gondola"<< endl;
}

Gondola::~Gondola(){
    delete [] productos;
	cout<<"Se ha borrado el vector dinamico productos de Gondola"<<endl;
}
