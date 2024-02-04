#include <iostream>
using namespace std;

//IMPLEMENTACION DE ESTRUCTURA DE DATOS
struct ListaSimple{ //!Lista de Platos
    string nombre;
    string calorias;
    double precio;

    ListaSimple* sig;
} plato;

struct Cola{ //! Cola de pedidos durante el dia;

} pedido;

struct Pila{ //! Pila de platos hechos durante la semana.
    
} historial;

ListaSimple* CrearLista(){

}
Cola* CrearCola(){

}
Pila* CrearPila(){
    
}


int main(){
    string dia[] = { "LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO" };
    int i = 1, j; 
    char opc;
    while(true){
        cout<<"*************** Semana "<<i<<" ***************: \n";
        int k = 0;
        for (j = 0; j<7; j++){
            cout<<" --------- Dia "<<dia[k]<<"---------  :\n ";

            k++;
        }
        

        i++;
        cout<<"Siguiente semana (S/N)? \n";
        cin>>opc;
        if (opc == 'N' || opc == 'n'){
            break;
        }
    }
    return 0;
}
