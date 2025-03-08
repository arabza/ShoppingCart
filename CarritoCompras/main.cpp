#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include <random>

using namespace std;

int main(){
  cout<<"shoppingMe.com"<<endl;
  cout<<"Aracelli Melissa Boza Zabarburú - A01662934"<<endl;
    //Arreglo de productos
    producto arr[26];
    arr[0].setNombre("Limones"); arr[0].setPrecio(1.47);arr[0].setCantidad(0);
    arr[1].setNombre("Aguacate"); arr[1].setPrecio(21.81);arr[1].setCantidad(0);
    arr[2].setNombre("Zanahoria");arr[2].setPrecio(0.70);arr[2].setCantidad(0);
    arr[3].setNombre("Jitomate"); arr[3].setPrecio(5.54);arr[3].setCantidad(0);
    arr[4].setNombre("Calabaza"); arr[4].setPrecio(11.34);arr[4].setCantidad(0);
    arr[5].setNombre("Tomate");arr[5].setPrecio(2.40);arr[5].setCantidad(0);
    arr[6].setNombre("Nopal");arr[6].setPrecio(1.84);arr[6].setCantidad(0);
    arr[7].setNombre("Col"); arr[7].setPrecio(18.90);arr[0].setCantidad(0);
    arr[8].setNombre("Elote"); arr[8].setPrecio(8);arr[8].setCantidad(0);
    arr[9].setNombre("Chícharo");arr[9].setPrecio(68.50);arr[9].setCantidad(0);
    arr[10].setNombre("Berenjena"); arr[10].setPrecio(33);arr[10].setCantidad(0);
    arr[11].setNombre("Chayote"); arr[11].setPrecio(7.47);arr[11].setCantidad(0);
    arr[12].setNombre("Crema");arr[12].setPrecio(32);arr[12].setCantidad(0);
    arr[13].setNombre("Queso"); arr[13].setPrecio(190);arr[13].setCantidad(0);
    arr[14].setNombre("Jamon"); arr[17].setPrecio(340);arr[14].setCantidad(0);
    arr[15].setNombre("Salchicha");arr[15].setPrecio(82);arr[15].setCantidad(0);
    arr[16].setNombre("Chicharrón"); arr[16].setPrecio(169);arr[16].setCantidad(0);
    arr[17].setNombre("Carne res"); arr[17].setPrecio(329);arr[17].setCantidad(0);
    arr[18].setNombre("Pollo");arr[18].setPrecio(182);arr[18].setCantidad(0);
    arr[19].setNombre("Crema");arr[12].setPrecio(32);arr[12].setCantidad(0);
    arr[20].setNombre("Huevo"); arr[13].setPrecio(3.37);arr[13].setCantidad(0);
    arr[21].setNombre("Yogurt"); arr[17].setPrecio(36);arr[14].setCantidad(0);
    arr[22].setNombre("Paquete oreo");arr[15].setPrecio(18.50);arr[15].setCantidad(0);
    arr[23].setNombre("SabritaLimón"); arr[16].setPrecio(48.50);arr[16].setCantidad(0);
    arr[24].setNombre("Coca-light"); arr[17].setPrecio(21);arr[17].setCantidad(0);
    arr[25].setNombre("Chocolate");arr[18].setPrecio(92);arr[18].setCantidad(0);
  
    Carrito carrito(arr);
    int eleccion, indice, unidades, condicion = 1;
    float total = 0;
    vector<int> opciones;
    random_device random;
    uniform_int_distribution<int> dist(5, 20);

    Menu menu(carrito);
    while (condicion){
        menu.menuPrincipal();
        cout << "\nSelecciona opcion: ";
        cin >> eleccion;
        switch(eleccion){
            case 1:
                cout<<"\n*** SELECCIONAR PRODUCTO *** "<<endl;
  cout<<"Producto       Descripción                          P. Unitario \n-------------------------------------------------------------------- "<<endl;
  cout<<"1)Limones       Por unidad                             $1.47\n2)Aguacates     Por unidad                             $21.81\n3)Zanahoria     Por unidad                             $0.70\n4)Jitomate      Por unidad                             $5.54\n5)Calabaza      Por unidad                             $11.34\n6)Tomate        Por unidad                             $2.40\n7)Nopal         Por unidad                             $1.84\n8)Col           Kilo                                   $18.90\n9)Elote         Por unidad                             $8\n10)Chícharo     Kilo                                   $68.50\n11)Berenjena    Kilo                                   $33\n12)Chayote      Por unidad                             $7.47\n13)Crema        450ml                                  $32\n14)Queso        150gramos                              $190\n15)Jamon        Kilo                                   $340\n16)Salchicha    400gramos                              $82\n17)Chicharrón   Kilo                                   $169\n18)Carne res    Kilo                                   $329\n19)Pollo        Kilo                                   $182\n20)Huevo        Por unidad                             $3.37\n21)Yogurt       150gramos                              $36\n22)Paquete oreo Por unidad                             $18.50\n23)SabritaLimón 160gramos                              $48.50\n24)Coca-light   1litro                                 $21\n25)Chocolate    100gramos                              $92\n"<<endl;
          
                cout << "Que producto deseas comprar? (-1 para cancelar)\nSelecciona opcion: ";
                cin >> indice;
                if (indice == -1){
                    condicion = 1;
                } else {
                    cout << "Cantidad (-1 para cancelar): ";
                    cin >> unidades;
                    if (unidades == -1){
                        condicion = 1;
                    } else {
                        arr[indice-1].setCantidad(unidades);
                        cout << arr[indice-1].getCantidad() << " unidad(es) de " << \
                        arr[indice-1].getNombre() << " a " << arr[indice-1].getPrecio() << " c/u, importe = $" << \
                        arr[indice-1].calculaImporte() << endl;
                        opciones.push_back(indice-1);
                        carrito.setOpcion(opciones);
                        carrito.setSize(opciones.size());
                        total += arr[indice-1].calculaImporte();
                    }
                }
                break;
            case 2:
                carrito.menuCarrito();
                menu.setTotal(total);
                menu.despliegaTotal();
                
                break;
            case 3:
                menu.setTamano(opciones.size());
                menu.setTotal(total);
                menu.aplicaDescuento(dist(random));
                menu.terminarCompra();
                for (int i = 0; i < opciones.size(); i++){
                    for (int j = 0; j < 25; j++){
                        if (opciones[i] == j){
                            arr[j].setCantidad(0);
                        }
                    }
                }
                total = 0;
                opciones.clear();
                carrito.setSize(opciones.size());
                break;
            case 4:
                menu.terminarAplicacion();
                condicion = 0;
                break;
        }

    }
    
    return 0;
} 