/*
 * compra.h
 *
 *  Created on: 24 mar. 2019
 *      Author: sosa
 */

#ifndef COMPRA_H_
#define COMPRA_H_
#include<iostream>
#include<fstream>

struct Chango{
    std::string nombre;
    int codigo;
    float precio;
    bool oferta;
};

const int MAXIMO_PRODUCTOS = 50;
const float DESCUENTO = 0.1;

void mostrar_producto(Chango producto);

void iniciar_chango(Chango compra[], int productos);

int primer_vacio(Chango compra[]);

void cargar_producto(Chango compra[]);

int buscar_producto_nombre(Chango compra[]);

int buscar_producto_codigo(Chango compra[]);

int oferta(Chango compra[]);

void ahorro(Chango compra[]);

void mod_precio(Chango compra[]);

void quitar_producto(Chango compra[]);

void menu_gondola(Chango gondola[], Chango compra[]);

void copiar_vector(Chango gondola[], Chango compra[]);

int cantidad_productos(std::fstream &archivo);

std::string chango_a_string(Chango producto);

Chango f_buscar_nombre(std::fstream &archivo, std::string buscado);

Chango f_buscar_codigo(std::fstream &archivo, std::string buscado);

int f_oferta(std::fstream &archivo);

void f_ahorro(std::fstream &archivo);

void copiar_archivo(std::fstream &archivo);

void f_mod_precio(std::fstream &archivo);

void f_quitar_producto(std::fstream &archivo);

void menu_archivo(std::fstream &archivo);

bool changocmp(Chango producto_a, Chango producto_b);

#endif /* COMPRA_H_ */
