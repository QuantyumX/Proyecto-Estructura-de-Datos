#include <iostream>
using namespace std;

//DECLARACION  DE ESTRUCTURA DE DATOS
//* LISTAS
struct ListaSimple1{ //!Lista de Platos
    string nombre;
    int calorias;
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

//* COLAS
struct SubCola{//! Cola de pedidos de cada cliente;
    string pedido;
    int raciones;
    double compra;

    SubCola* sig;
};
struct Cola{ //! Cola de clientes durante el dia.
    string nombreCliente;
    int edad;
    SubCola* Pedido;

    Cola* sig;
};

//* PILAS
struct SubPila{//! Pila de pedidos de cada cliente;
    string pedido;
    int raciones;
    double compra;

    SubPila* sig;
};
struct Pila{ //! Pila de clientes durante el dia y semana.
    string nombreCliente;
    int edad;
    SubPila* Pedido;

    Pila* sig;
};


//PROTOTIPOS FUNCIONES DE ESTRUCTURAS
//* ListaSimple1: Plato
void InsertarPlato(ListaSimple1*&, string, int, int, double, double);
void MostrarListaPlatos(ListaSimple1*);
void EliminarPlatoEspecifico(ListaSimple1*&, string);
//* ListaSimple2: InfoDia
void InsertarInfoDia(ListaSimple2*&, string, double, double);
void MostrarInfoDia(ListaSimple2*);
void eliminarInfoInicio(ListaSimple2* &);
void VaciarInfoSemana(ListaSimple2*&);
//* SubCola: Pedido
void imprimirColaPedidos(SubCola*);
//* Cola: Cliente;
void encolarCliente(Pila*&, SubPila*&, ListaSimple1*, Cola*&, Cola*&, string, int);
void desencolarCliente(Cola*&, Cola*&);
void vaciarColaClientes(Cola*&, Cola*&);
void imprimirColaClientes(Cola*);
//* SubPila: Pedido
void pushPedido(SubPila*&, string, int, double);
void popPedido(SubPila*&);
void vaciarSubPila(SubPila*&);
void MostrarPedidos(SubPila*);
//* Pila: Cliente
void pushCliente(Pila*&, SubPila*&, string, int, string, int, double);
void popCliente(Pila*&);
void vaciarPila(Pila*&);
void MostrarHistorial(Pila*);

//PROTOTIPOS DEL PROGRAMA
void MostrarPlato(ListaSimple1*);
void MostrarPlatosSegunEdad(ListaSimple1*, int);


int main(){
    ListaSimple1* Plato = NULL;
    ListaSimple2* InfoDia = NULL;
    SubPila* Pedido = NULL;
    Pila* Cliente = NULL;
    SubCola* frenteP = NULL;
    SubCola* finP = NULL;
    Cola* frenteC = NULL;
    Cola* finC = NULL;
    //INSERTAMOS LOS PLATOS DETERMINADOS.
    InsertarPlato(Plato, "Arroz oon pollo", 630, 20, 12.90, 8);
    InsertarPlato(Plato, "Tallarines verdes con pollo", 750, 15, 12.50, 7.30);
    InsertarPlato(Plato, "Causa peruana", 320, 15, 14.00, 4.60);
    InsertarPlato(Plato, "Cuy al horno", 800, 10, 25.00, 18.00);
    InsertarPlato(Plato, "Aji de gallina", 590, 15, 11.50, 5.60);
    InsertarPlato(Plato, "Lomo saltado", 710, 20, 14.00, 7.50);
    InsertarPlato(Plato, "Ceviche mixto", 400, 20, 20.00, 7.50);
    InsertarPlato(Plato, "Jalea de mariscos", 760, 15, 15.00, 8.60);
    InsertarPlato(Plato, "Tacu Tacu con bistec", 700, 15, 16.00, 8.60);
    InsertarPlato(Plato, "Anticuchos", 190, 25, 10.00, 4.60);
    InsertarPlato(Plato, "Torta de selva negra", 410, 15, 6.00, 4.00);
    InsertarPlato(Plato, "Arroz con leche", 230, 30, 3.50, 1.50);

    string dia[] = { "LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO" };
    string nombreC, pedido;
    int i = 1, j, edad, raciones;
    char opc;
    bool marca = true;
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
                    cout << "Ingresa tu NOMBRE:  "; 
                    cin.ignore();
					getline(cin, nombreC);
					cout << "Ahora ingresa tu EDAD:  "; 
                    cin>>edad;
					cout << endl;
					cout << endl;
                    MostrarPlatosSegunEdad(Plato, edad);
                    encolarCliente(Cliente, Pedido, Plato, frenteC, finC, nombreC, edad);
                        

  
      
                    cout<<" *Siguiente cliente? (S/N)? \n";
                    cin>>opc;
                    if (opc == 'N' || opc == 'n'){
                        break;
                    }   
            }
            imprimirColaClientes(frenteC);
        }

        i++;
        //! IMPLEMENTACION DE SWITCH PARA EL FINAL DE CADA SEMANA, (MostrarHistorial, mostrarInfoDia, mostrarListaSimple, ajustarInventario); 
                        cout<<" COMPROBACION DE REGISTRO \n";
             MostrarHistorial(Cliente);
        //!.............
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
void InsertarPlato(ListaSimple1*& Plato, string nomPlato, int cal, int stock, double precio, double inversion){
    ListaSimple1* p;
    p = new ListaSimple1;
    p->nombre = nomPlato;
    p->calorias = cal;
    p->stock = stock;
    p->precio = precio;
    p->sig = NULL;
    
    if (Plato == NULL){
        Plato = p;
    } else {
        ListaSimple1* lista;
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
    
        cout<<"*"<<lista->nombre<<"* "<<endl;
		cout<<"Calorias: "<<lista->calorias <<endl;
		cout<<"Stock: "<<lista->stock<<endl;
		cout<<"Precio: s/. "<<lista->precio<<endl;
		cout << "----------------------\n";
        lista = lista->sig;
        
    }
   
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
//! OPERACIONES SubCola de pedidos de cada cliente.

//* Reporta los pedidos de cada cliente.
void imprimirColaPedidos(SubCola* frenteP){
    cout << "Pedidos: \n";
    while (frenteP != NULL) {
        cout << "- "<< frenteP->pedido << ": " << frenteP->raciones << " raciones. \n";
        frenteP = frenteP->sig;
    }
    cout << endl;
}

//! OPERACIONES Cola de clientes.
//* Encolar nuevo cliente.
void encolarCliente(Pila*& Cliente,SubPila*& Pedido, ListaSimple1* Plato, Cola*& frenteC, Cola*& finC, string nombreC, int edad) {
    Cola* nuevoNodo = new Cola;
    nuevoNodo->nombreCliente = nombreC;
    nuevoNodo->edad = edad;
    nuevoNodo->Pedido = NULL;
    nuevoNodo->sig = NULL;

    if (frenteC == NULL) {
        frenteC = finC = nuevoNodo;
    } else {
        finC->sig = nuevoNodo;
        finC = nuevoNodo;
    }

    char rpt = 's';
    do {
        ListaSimple1* listaActual = Plato;
        string pedido;
        int raciones;

        cout << "Ingrese su plato a pedir: ";
        cin.ignore();
        getline(cin, pedido);
        cout << "Cantidad de raciones: ";
        cin >> raciones;

        while (listaActual != NULL) {
            if (listaActual->nombre.compare(pedido) && listaActual->stock >= raciones) {
                SubCola* nuevoPedido = new SubCola;
                nuevoPedido->pedido = pedido;
                nuevoPedido->raciones = raciones;
                double compra = raciones* listaActual->precio;
                nuevoPedido->compra = compra;
                nuevoPedido->sig = NULL;

                if (nuevoNodo->Pedido == NULL) {
                    nuevoNodo->Pedido = nuevoPedido;
                } else {
                    SubCola* temp = nuevoNodo->Pedido;
                    while (temp->sig != NULL) {
                        temp = temp->sig;
                    }
                    temp->sig = nuevoPedido;
                }

                listaActual->stock -= raciones;

                cout << " << Agregado con exito >> \n";
                pushCliente(Cliente, Pedido, nombreC, edad, pedido, raciones, compra);
                break;
            } else {
                listaActual = listaActual->sig;
            }
        }

        if (listaActual == NULL) {
            cout << " No hay suficiente stock de tu pedido, intente con otro o disminuya las raciones. \n";
        }

        cout << " *Otro plato (S/N)?: ";
        cin >> rpt;
    } while (rpt == 's' || rpt == 'S');
}


//* Desencolar cliente
void desencolarCliente(Cola*& frenteC, Cola*& finC){
    if (frenteC != NULL) {
        Cola* nodoAEliminar = frenteC;
        frenteC = frenteC->sig;
        delete nodoAEliminar;

        if (frenteC == NULL) {
            finC = NULL;
        }
    } else {
        cout << "La cola está vacía." <<endl;
    }
}
//* Vaciar cola de clientes.
void vaciarColaClientes(Cola*& frenteC, Cola*& finC){
    while (frenteC != NULL) {
        desencolarCliente(frenteC, finC);
    }
}

//* Imprimir  los clientes.
void imprimirColaClientes(Cola* frenteC) {
    cout << "  Pedidos del dia: \n";
    while (frenteC != NULL) {
        cout << "-----------------------\n";
        cout << frenteC->nombreCliente << "  " << frenteC->edad << " años. \n";
        imprimirColaPedidos(frenteC->Pedido);  // Ahora pasa la subcola del cliente

        frenteC = frenteC->sig;
    }
    cout << endl;
}

//!OPERACIONES Pila de pedidos de cada cliente.
//* Insertar cliente al historial.
void pushPedido(SubPila*& Pedido, string pedido, int raciones, double compra) {
    SubPila* nuevoPedido = new SubPila;
    nuevoPedido->pedido = pedido;
    nuevoPedido->raciones = raciones;
    nuevoPedido->compra = compra;
    nuevoPedido->sig = NULL;

    if (Pedido == NULL) {
        Pedido = nuevoPedido; 
    } else {
        SubPila* temp = Pedido;
        while (temp->sig != NULL) {
            temp = temp->sig;
        }
        temp->sig = nuevoPedido;
    }
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
    cout<<" Pedidos: \n";
    while (actual != NULL) {
        cout << "- " << actual->pedido<< ": " << actual->raciones << " raciones "<<endl;
        actual = actual->sig;
    }
}

//! OPERACIONES Pila de cliente y sus pedidos (historial de la semana).
//* Insertar un nuevo pedido al historial.
void pushCliente(Pila*& Cliente, SubPila*& Pedido, string nombreC, int edad, string pedido, int raciones, double compra){
    Pila* nuevoCliente = new Pila;
    nuevoCliente->nombreCliente = nombreC;
    nuevoCliente->edad = edad;
    nuevoCliente->Pedido = NULL;
    nuevoCliente->sig = Cliente;
    pushPedido(nuevoCliente->Pedido, pedido, raciones, compra);
    
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
        MostrarPedidos(actual->Pedido);
        actual = actual->sig;
    }
}

void MostrarPlato(ListaSimple1* lista){
        cout<<"                                                 *"<<lista->nombre<<"* "<<endl;
		cout<<"                                                 Calorias: "<<lista->calorias <<endl;
		cout<<"                                                 Stock: ["<<lista->stock<<"]"<<endl;
		cout<<"                                                 Precio: s/. "<<lista->precio<<endl;
		cout << "                                               ----------------------\n";
}
//* Mostrar Todos LosPLatos.
//* Mostrar Platos Según la Edad del Cliente.
void MostrarPlatosSegunEdad(ListaSimple1* Plato, int edad){
	
    ListaSimple1* lista = Plato;
    
        if (1 <= edad && edad <= 8) {
            cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Poco ACTIVO Fisicamente] \n" << endl; 
            while (lista != NULL) {              
                if (lista->calorias >= 190 && lista->calorias <= 400) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            lista = Plato;
            cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Muy ACTIVO Fisicamente] \n" << endl;
            while (lista != NULL) {
                if (lista->calorias >= 320 && lista->calorias <= 590) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            cout << "			--------------------------------------------------------------------" << endl;
        }else if(9 <= edad && edad <= 12){
        	cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Poco ACTIVO Fisicamente] \n" << endl; 
            while (lista != NULL) {              
                if (lista->calorias >= 320 && lista->calorias <= 590) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            lista = Plato;
            cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Muy ACTIVO Fisicamente] \n" << endl;
            while (lista != NULL) {
                if (lista->calorias >= 400 && lista->calorias <= 630) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            cout << "			--------------------------------------------------------------------" << endl;
   
		} else if(13 <= edad && edad <= 19){
        	cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Poco ACTIVO Fisicamente] \n" << endl; 
            while (lista != NULL) {              
                if (lista->calorias >= 400 && lista->calorias <= 630) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            lista = Plato;
            cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Muy ACTIVO Fisicamente] \n" << endl;
            while (lista != NULL) {
                if (lista->calorias >= 590 && lista->calorias <= 710) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            cout << "			--------------------------------------------------------------------" << endl;
   
		} else if(20 <= edad && edad <= 31){
			cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Poco ACTIVO Fisicamente] \n" << endl; 
            while (lista != NULL) {              
                if (lista->calorias >= 410 && lista->calorias <= 700) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            lista = Plato;
            cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Muy ACTIVO Fisicamente] \n" << endl;
            while (lista != NULL) {
                if (lista->calorias >= 710 && lista->calorias <= 800) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            cout << "			--------------------------------------------------------------------" << endl;
		
		}else if(32 <= edad && edad <= 50){
			cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Poco ACTIVO Fisicamente] \n" << endl; 
            while (lista != NULL) {              
                if (lista->calorias >= 400 && lista->calorias <= 630) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            lista = Plato;
            cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Muy ACTIVO Fisicamente] \n" << endl;
            while (lista != NULL) {
                if (lista->calorias >= 630 && lista->calorias <= 760) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            cout << "			--------------------------------------------------------------------" << endl;
	
		}else if( edad>=51 ){
			cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Poco ACTIVO Fisicamente] \n" << endl; 
            while (lista != NULL) {              
                if (lista->calorias >= 320 && lista->calorias <= 590) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            lista = Plato;
            cout << "			--------------------------------------------------------------------" << endl;
            cout <<  endl;
            cout << "						[Muy ACTIVO Fisicamente] \n" << endl;
            while (lista != NULL) {
                if (lista->calorias >= 590 && lista->calorias <= 750) {
                    MostrarPlato(lista);
                }
                lista = lista->sig;
            }
            cout << "			--------------------------------------------------------------------" << endl;
		
		}
		
}

void CambiosDelStock(){

}