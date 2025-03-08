#include "Carrito.h"
#include <iostream>
using namespace std;
class Menu{
    public:
        double Total;
        int Tamano;
        Carrito carrito;
        Menu(Carrito x):carrito(x){}

        void setTotal(double total){
            Total = total;
        }

        void setTamano(int tamano){
            Tamano = tamano;
        }

        void aplicaDescuento(int rnum){
            if (Tamano > 10){
               cout << "Usted obtuvo un descuento del %" << rnum  << " por BUEN FIN!" << endl;
               Total = Total - ((rnum*Total)/100);
            }
        }

        void despliegaTotal(){
            cout << "TOTAL: " << Total << endl;
        }

 
        void menuPrincipal(){
            cout<<"\n----Menú Principal----"<<endl;
    cout<<"1) Seleccionar productos\n2) Ver carrito de compras\n3) Terminar compra\n4) Salir "<<endl;
        }
        void terminarCompra(){
            cout << "\n***TERMINAR COMPRA***" << endl;
            cout << "El total de su compra es: $" << Total << endl;
            cout << "Gracias por comprar en MiTiendita.com!" << endl;
        }

        void terminarAplicacion(){
            cout << "Sesión finalizada" << endl;
        }
};