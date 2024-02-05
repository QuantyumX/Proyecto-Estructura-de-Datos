#include <iostream>
using namespace std;

//DECLARACION  DE ESTRUCTURA DE DATOS
struct ListaSimple1{ //!Lista de Platos
    string nombre;
    string calorias;
    double precio;

    ListaSimple1* sig;
};

struct ListaSimple2{ //! Lista de datos del DIA para la inversion.
    string nombreDia;
    int ingresos;
    int ganancias;

    ListaSimple2* sig;
};

struct Pila{ //! Pila de pedidos durante el dia y semana.
    string nombreCliente;
    string edad;
    string pedido;
    int compra;

    Pila* sig;
};

//! Aca deberia declararse para el stock de platos, pero la verdad nose como hcerlo, si solo con un array o algun estructura de datos xd si tienen en mente una avisan sino ya yo veo.


//AGREGAR LAS OPERACIONES PARA CADA ESTRUCTURA DE DATOS. (como insertar, eliminar para las dos listas) y (push, pop y vaciar para la pila y RECORRER LA PILA)






int main(){
   ListaSimple1* plato = NULL;
   ListaSimple2* infoDia = NULL;
   Pila* pedido = NULL;

    string dia[] = { "LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO" };
    int i = 1, j; 
    char opc;
    while(true){
        cout<<"                                  *************** Semana "<<i<<" *************** \n";
        int k = 0;
        for (j = 0; j<7; j++){
            cout<<"                                       --------- Dia "<<dia[k]<<"---------  \n ";
            k++;
            while (true){
                    cout<<"\n";
					cout << "               				[!INGRESA   TU   EDAD!]                              "<<endl;
			        cout << endl;	
					cout << "	------------------------------------------------------------------------------------------------------"<<endl;
					cout << "	| Mira las recomendaciones que te damos de los platillos  con sus respectivas calorias segun tu edad. |"<<endl;
					cout << "	-------------------------------------------------------------------------------------------------------"<<endl;
					cout << endl;
					cout << "Primero ingresa tu EDAD:  "; //ESTE COUT ESTARA DENTRO DE LA FUNCION INSERTAR(push) para la pila
					//Se llena el campo de la pila.
					cout << endl;
					cout << "Finalmente ingresa tu NOMBRE:  "; //ESTE COUT ESTARA DENTRO DE LA FUNCION INSERTAR(push) para la pila
                    // se llena el campo de la pila.
					cout << endl;
					cout << endl;
                    cout<<" *Siguiente cliente? (S/N)? \n";
                    cin>>opc;
                    if (opc == 'N' || opc == 'n'){
                        break;
                    }   
            }
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
