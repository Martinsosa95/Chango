#include "Chango.h"


Chango::Chango(int nueva_cant_productos){
	cant_productos = 0;
	productos = new Producto [cant_productos];
}

int Chango::obtener_cant_productos(){
	return cant_productos;
}

Producto* Chango::obtener_productos(){
	return productos;
}

int Chango::obtener_producto_seleccionado(){
    return producto_seleccionado;
}
void Chango::asignar_seleccion_producto(int seleccion){
    producto_seleccionado = seleccion;
}

void Chango::asignar_cant_productos(int nueva_cant_productos){
	cant_productos = nueva_cant_productos;
}

void Chango::asignar_productos(Producto* nuevos_productos){
	productos[producto_seleccionado] = *nuevos_productos;
    producto_seleccionado ++;
}

void Chango::cargar_producto(Producto producto_a_cargar){

	productos[cant_productos] = producto_a_cargar;
	cant_productos++;

	cout<<"El producto fue agregado al chango"<<endl;
}

int Chango::monto_a_pagar(){
	int total = 0;
	for (int i = 0; i < cant_productos; ++i){
		total += productos[i].calcular_precio_final();
	}
	cout<<"El monto a pagar es :"<< total<< " $"<<endl;
	return total;
}

int Chango::ahorro_total(){
	int ahorro = 0;
	for (int i = 0; i < cant_productos; ++i){
		if (productos[i].obtener_oferta()){
			ahorro+= productos[i].obtener_precio() - productos[i].calcular_precio_final();
		}
	}
	cout<<"Usted ahorro :"<< ahorro << " $"<<endl;
	return ahorro;
}

bool Chango::esta_lleno(int cant_prod_gondola){

	if(cant_productos == cant_prod_gondola){
		cout<<"El chango esta lleno,no puede ingresar mas productos"<<endl;
		return true;
	}
	return false;
}

Chango::~Chango(){
	delete [] productos;
}
