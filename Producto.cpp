#include "Producto.h"
/*
Producto::Producto(){
	nombre = " ";
	codigo = 0;
	precio = 0;
	en_oferta = 0;
}*/

Producto::Producto(string nuevo_nombre,int nuevo_codigo,int nuevo_precio,bool nuevo_en_oferta){
	nombre = nuevo_nombre;
	codigo = nuevo_codigo;
	precio = nuevo_precio;
	en_oferta = nuevo_en_oferta;
}

Producto & Producto::operator=(Producto &p){
    this->nombre = p.obtener_nombre();
    this->codigo = p.obtener_codigo();
    this->precio = p.obtener_precio();
    this->en_oferta = p.obtener_oferta();
    return *this;
}

string Producto::obtener_nombre(){
	return nombre;
}

int Producto::obtener_codigo(){
	return codigo;
}

int Producto::obtener_precio(){
	return precio;
}

bool Producto::obtener_oferta(){
	return en_oferta;
}

void Producto::asignar_nombre(string nuevo_nombre){
	nombre = nuevo_nombre;
}

void Producto::asignar_codigo(int nuevo_codigo){
	codigo = nuevo_codigo;
}

void Producto::asignar_precio(int nuevo_precio){
	precio = nuevo_precio;
}

void Producto::asignar_oferta(bool nuevo_en_oferta){
	en_oferta = nuevo_en_oferta;
}

int Producto::calcular_precio_final(){
	if (en_oferta){
		return 90/100 * precio;
	}
	else{
		return precio;
	}
}
