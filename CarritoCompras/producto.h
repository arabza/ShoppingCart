#include <iostream>
#include <string>
using namespace std;

class producto{
    private:
        string Nombre, Descripcion;
        double Precio;
        int Cantidad;

    public:
        
        void setNombre(string nombre){
            Nombre = nombre;
        }
        void setDescripcion(string descripcion){
            Descripcion = descripcion;
        }
        void setPrecio(double precio){
            Precio = precio;
        } 
        void setCantidad(int cantidad){
            Cantidad = cantidad;
        }
        string getNombre(){
            return Nombre;
        }
        string getDescripcion(){
            return Descripcion;
        }
        double getPrecio(){
            return Precio;
        }
        int getCantidad(){
            return Cantidad;
        }
        float calculaImporte(){
            return Cantidad * Precio;
        }
};