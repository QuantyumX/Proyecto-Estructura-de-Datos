#include <iostream>
using namespace std;

//DECLARACION  DE ESTRUCTURA DE DATOS
struct ListaSimple1{ //!Lista de Platos
    string nombre;
    string calorias;
    int stock;
    double precio;
    double inversion;
    ListaSimple1* sig;
};

struct ListaSimple2{ //! Lista de datos del DIA para la inversion.
    string nombreDia;
    double ingresos;
    double ganancias;

    ListaSimple2* sig;
};

struct SubPila{//! Pila de pedidos de cada cliente;
    string pedido;
    int raciones;
    double compra;

    SubPila* sig;
};

struct Pila{ //! Pila de clientes durante el dia y semana.
    string nombreCliente;
    string edad;
    SubPila* Pedido;

    Pila* sig;
};


//PROTOTIPOS FUNCIONES DE ESTRUCTURAS
//* ListaSimple1: Plato
void InsertarPlato(ListaSimple1*&, string, string, int, double, double);
void MostrarListaPlatos(ListaSimple1*);
void EliminarPlatoEspecifico(ListaSimple1*&, string);
//* ListaSimple2: InfoDia
void InsertarInfoDia(ListaSimple2*&, string, double, double);
void MostrarInfoDia(ListaSimple2*);
void eliminarInfoInicio(ListaSimple2* &);
void VaciarInfoSemana(ListaSimple2*&);
//* SubPila: Pedido
void pushPedido(SubPila*&, string, int, double);
void popPedido(SubPila*&);
void vaciarSubPila(SubPila*&);
void MostrarPedidos(SubPila*);
//* Pila: Cliente
void pushCliente(Pila*&, SubPila*&, string, string, string, int, double);
void popCliente(Pila*&);
void vaciarPila(Pila*&);
void MostrarHistorial(Pila*);




int main(){
    ListaSimple1* Plato = NULL;
    ListaSimple2* InfoDia = NULL;
    SubPila* Pedido = NULL;
    Pila* Cliente = NULL;
    //INSERTAMOS LOS PLATOS DETERMINADOS.
    InsertarPlato(Plato, "Arroz oon pollo", "630", 20, 12.90, 8);
    InsertarPlato(Plato, "Tallarines verdes con pollo", "750", 15, 12.50, 7.30);
    InsertarPlato(Plato, "Causa peruana", "320", 15, 14.00, 4.60);
    InsertarPlato(Plato, "Cuy al horno", "800", 10, 25.00, 18.00);
    InsertarPlato(Plato, "Aji de gallina", "600", 15, 11.50, 5.60);
    InsertarPlato(Plato, "Lomo saltado", "710", 20, 14.00, 7.50);
    InsertarPlato(Plato, "Ceviche mixto", "400", 20, 20.00, 7.50);
    InsertarPlato(Plato, "Jalea de mariscos", "760", 15, 15.00, 8.60);
    InsertarPlato(Plato, "Tacu Tacu con bistec", "700", 15, 16.00, 8.60);
    InsertarPlato(Plato, "Anticuchos", "190", 25, 10.00, 4.60);
    InsertarPlato(Plato, "Torta de selva negra", "410", 15, 6.00, 4.00);
    InsertarPlato(Plato, "Arroz con leche", "230", 30, 3.50, 1.50);

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

//! OPERACIONES Lista de platos
//* Insertar Plato y sus datos.
void InsertarPlato(ListaSimple1*& Plato, string nomPlato, string cal, int stock, double inversion, double precio){
    ListaSimple1* p;
    ListaSimple1* lista;
    p = new ListaSimple1;
    p->nombre = nomPlato;
    p->calorias = cal;
    p->stock = stock;
    p->precio = precio;
    p->sig = NULL;
    
    if (Plato == NULL){
        Plato = p;
    } else {
        lista = Plato;
        while (lista->sig != NULL){
            lista = lista->sig;
        }
        lista->sig = p;
    }
}

//* Mostrar Todos LosPLatos.
void MostrarListaPlatos(ListaSimple1* Plato){
    ListaSimple1* lista = Plato;
    while(lista != NULL){
        cout<<lista->nombre << " ";
        lista = lista->sig;
    }
    cout << endl;
}
//* Eliminar Plato Especifico .
void EliminarPlatoEspecifico(ListaSimple1*& Plato, string valor){
    ListaSimple1* lista = Plato;
    ListaSimple1* anterior = NULL;

    while(lista != NULL && lista->nombre != valor){
        anterior = lista;
        lista = lista->sig;
    }
    if (lista != NULL){
        if(anterior != NULL){
            anterior->sig = lista->sig;
         } else {
         Plato = lista->sig;
         }

        delete lista;
    } else {
        cout<<" No se encontro el Plato que se quiere eliminar. \n";
    }
}


//! OPERACIONES Lista de Inversion, gastos, etc. de cada dia de la semana.
//* Insertar Informacion Diario de la semana.
void InsertarInfoDia(ListaSimple2*& InfoDia, string nomDia, double ingresos, double ganancias){
    ListaSimple2* p;
    ListaSimple2* lista;
    p = new ListaSimple2;
    p->nombreDia = nomDia;
    p->ingresos = ingresos;
    p->ganancias = ganancias;
    p->sig = NULL;
    
    if (InfoDia == NULL){
        InfoDia = p;
    } else {
        lista = InfoDia;
        while (lista->sig != NULL){
            lista = lista->sig;
        }
        lista->sig = p;
    }
}
//* Reporta la informacion de cada dia de la semana.
void MostrarInfoDia(ListaSimple2* InfoDia){
    ListaSimple2* lista = InfoDia;
    while(lista != NULL){
        cout<<lista->nombreDia << " ";
        lista = lista->sig;
    }
    cout << endl;
}
//* Elimina la informacion del dia.
void eliminarInicio(ListaSimple2* & InfoDia){
	ListaSimple2* p;
	if(InfoDia!=NULL){
		p=InfoDia;
		InfoDia=InfoDia->sig;
		delete(p);
	}	
}
//* Elimina toda la informacion de todos los dias de la semana.
void VaciarInfoSemana(ListaSimple2*& InfoDia){
    while(InfoDia != NULL){
        eliminarInicio(InfoDia);
    }
}

//!OPERACIONES Pila de pedidos de cada cliente.
//* Insertar cliente al historial.
void pushPedido(SubPila*& Pedido, string pedido, int raciones, double compra){
    SubPila* nuevoPedido = new SubPila;
    nuevoPedido->pedido = pedido;
    nuevoPedido->raciones = raciones;
    nuevoPedido->compra = compra;
    
    nuevoPedido->sig = Pedido;
    Pedido = nuevoPedido;
}
//* Saca el ultimo pedido insertado.
void popPedido(SubPila*& Pedido){
    if (Pedido != NULL){
        SubPila* temp = Pedido;
        Pedido = Pedido->sig;
        delete temp;
    } else {
        cout<<" La pila de Pedidos esta vacia, ya no se puede quitar mas pedidos... \n";
    }
}
//* Saca todos los pedidos del cliente.
void vaciarSubPila(SubPila*& Pedido){
    while(Pedido != NULL){
        popPedido(Pedido);
    }
}
//* Muestra la pila de pedidos del cliente.
void MostrarPedidos(SubPila* Pedido){
    SubPila* actual = Pedido;
    while (actual != NULL) {
        cout << "Cliente: " << actual->pedido<< ", Edad: " << actual->raciones << endl;
        actual = actual->sig;
    }
}

//! OPERACIONES Pila de cliente y sus pedidos (historial de la semana).
//* Insertar un nuevo pedido al historial.
void pushCliente(Pila*& Cliente, SubPila*& Pedido, string nomCliente, string edad, string pedido, int raciones, double compra){
    Pila* nuevoCliente = new Pila;
    nuevoCliente->nombreCliente = nomCliente;
    nuevoCliente->edad = edad;
    for(int i = 0; i < raciones; i++){
        pushPedido(Pedido, pedido, raciones, compra);
    }
    nuevoCliente->sig = Cliente;
    Cliente = nuevoCliente;
}
//* Saca el ultimo cliente insertado.
void popCliente(Pila*& Cliente){
    if (Cliente != NULL){
        Pila* temp = Cliente;
        Cliente = Cliente->sig;
        delete temp;
    } else {
        cout<<" La pila de Clientes esta vacia, ya no se puede quitar mas Clientes.. \n";
    }
}
//* Saca todos los clientes y sus pedidos del historial.
void vaciarPila(Pila*& Cliente){
    while(Cliente != NULL){
        popCliente(Cliente);
    }
}
//* Reporte de todos los clientes de la semana.
void MostrarHistorial(Pila* Cliente){
    Pila* actual = Cliente;
    while (actual != NULL) {
        cout << "Cliente: " << actual->nombreCliente << ", Edad: " << actual->edad << endl;
        actual = actual->sig;
    }
}