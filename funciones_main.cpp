#include "funciones.h"



int main(){


    ifstream archivo ;


    archivo.open("productos.txt");

    if(archivo.fail()){
        cout<< "No se pudo abrir el archivo"<< endl;
        return 0; //CORTO EL PROGRAMA YA QUE NO SE PUDO ABRIR EL ARCHIVO//
    }

    int cant_productos = calcular_cant_productos(archivo);
    Gondola gondola(cant_productos);
    archivo.clear();
    archivo.seekg(0);
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

                cout<<"ingrese el nombre del producto que desea buscar"<<endl;
                cin>>nombre_a_buscar;

                gondola.buscar_nombre(nombre_a_buscar);
            }
                break;

            case 'b':
            {
                int codigo_a_buscar;
                Producto producto_codigo;

                cout<<"ingrese el codigo del producto que desea buscar"<<endl;
                cin>>codigo_a_buscar;

                gondola.buscar_codigo(codigo_a_buscar);
            }
                break;

            case'c':
            {
                int pos_producto = tipo_busqueda(gondola);
                modificar_precio(gondola,pos_producto);
            }
                break;

            case 'd':
            {
                tipo_busqueda(gondola);
                Producto producto_a_quitar;
                producto_a_quitar.igualar_productos(gondola.obtener_producto());
                gondola.quitar_producto(producto_a_quitar);
            }
                break;


            case 'e':

                cantidad_en_oferta(gondola);

                break;

            case'f':
            {
                Chango chango(cant_productos);
                cout<<"cant_productos: "<<cant_productos<<endl;  // creo el chango //
                bool agregar_prod = 1;
                while(agregar_prod && !chango.esta_lleno(cant_productos)){
                    Producto aux;
                    cout<<"Busque el producto de la gondola que desea agregar"<<endl;
                    cout<<"el vector del chango esta en :"<<chango.obtener_producto_seleccionado()<<endl;
                    tipo_busqueda(gondola);
                    cout<<"el vector de gondola esta en :"<<gondola.obtener_producto_seleccionado()<<endl;
                    aux.igualar_productos(gondola.obtener_producto());
                    chango.cargar_producto(&aux);
                    cout<<"Si desea agregar otro producto ingrese 1"<<endl;
                    cin>>agregar_prod;
                }

                chango.monto_a_pagar();
                chango.ahorro_total();

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
