#include "funciones.h"



int main(int argc, char *argv[]){


    ifstream archivo = abrir_archivo("productos.txt");
    int cant_productos = calcular_cant_productos(archivo);
    Gondola gondola = crear_gondola (cant_productos);
    cargar_gondola(archivo,gondola);



    char comando;
    char continuar_operando = 's';

    while(continuar_operando == 's'){


        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;

        cout<<"MENU DE COMANDOS"<< endl;

        cout<<"a. buscar producto indicando su nombre"<< endl;
        cout<<"b. buscar producto por codigo de barra"<< endl;
        cout<<"c. modificar el precio de algun producto"<< endl;
        cout<<"d. quitar un producto de la gondola"<< endl;
        cout<<"e. consultar la cantidad de productos en oferta que se encuentran en la gondola"<< endl;
        cout<<"f. realizar una compra"<< endl;

        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;
        cout<<"ingrese un comando"<< endl;
        cin>> comando;

        while(comando != 'a' && comando != 'b' && comando != 'c' && comando != 'd' && comando != 'e' && comando != 'f' && comando != 'g'){

            cout<<"comando invalido"<<endl;
            cout<<"ingrese un comando"<< endl;
            cin>> comando;

        }

        switch(comando){

            case 'a':
            {
                string nombre_a_buscar;
                Producto producto_nombre;

                cout<<"ingrese el nombre del producto que desea buscar"<<endl;
                cin>>nombre_a_buscar;

                producto_nombre.asignar_nombre(gondola.buscar_nombre(nombre_a_buscar).obtener_nombre());
            }
                break;

            case 'b':
            {
                int codigo_a_buscar;
                Producto producto_codigo;

                cout<<"ingrese el codigo del producto que desea buscar"<<endl;
                cin>>codigo_a_buscar;

                producto_codigo.asignar_codigo(gondola.buscar_codigo(codigo_a_buscar).obtener_codigo());
            }
                break;

            case'c':
            {
                Producto producto_a_modificar = tipo_busqueda(gondola);
                modificar_precio(producto_a_modificar);
            }
                break;

            case 'd':
            {
                Producto producto_a_quitar = tipo_busqueda(gondola);
                gondola.quitar_producto(producto_a_quitar);
            }
                break;


            case 'e':
                cantidad_en_oferta(gondola);

                break;

            case'f':
            {
                Chango chango(cant_productos);  // creo el chango //
                bool agregar_prod = 1;
                while(agregar_prod && !chango.esta_lleno(cant_productos)){
                    cout<<"Busque el producto de la gondola que desea agregar"<<endl;
                    chango.cargar_producto(tipo_busqueda(gondola));
                    cout<<"Si desea agregar otro producto ingrese 1"<<endl;
                    cin>>agregar_prod;
                }

                cout<<"El monto a pagar es :"<< chango.monto_a_pagar() << " $"<<endl;
                cout<<"Usted ahorro :"<< chango.ahorro_total() << " $"<<endl;

                //~chango; // LLAMAR AL DESTRUCTOR DEL CHANGO,SE LLAMA SOLO?//
            }
                break;


        }

    cout<<"si desea realizar otra operacion ingrese s"<< endl;
    cin>> continuar_operando;

    }

    //~gondola; // LLAMAR AL DESTURCTOR DE LA GONDOLA, SE LLAMA SOLO?//

    return 0;

}
