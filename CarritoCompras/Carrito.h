#include <iostream>
#include <string>
#include <vector>
#include "producto.h"
using namespace std;

class Carrito:public producto{
    public:
        producto* producto1;
        vector<int> Opcion;
        int Size;

        Carrito(producto* producto):producto1(producto){
            Size = 0;
        }

        void setOpcion(vector<int> opcion){
            Opcion = opcion;
        }
        
        void setSize(int size){
            Size = size;
        }

        void menuCarrito(){
            if (Size != 0){
                cout << "***CARRITO DE COMPRAS***" << endl;
                cout << "Cantidad         Producto         P. Unitario        Importe" << endl; 
                cout << "----------------------------------------------------------------" << endl;
                for (int i = 0; i < Size; i++){
                    for (int j = 0; j < 25; j++){
                        if (Opcion[i] == j){
                            cout<<producto1[j].getCantidad()<<"                 "<<producto1[j].getNombre() \
                            <<"             "<< producto1[j].getPrecio()<<"             "<<\
                            producto1[j].calculaImporte()<<endl;
                        }
                    }
                }
                cout << "-----------------------------------------------------------------" << endl;

            } else {
                cout << "El carrito de compras esta vacio" << endl;
            }
        }
}; 