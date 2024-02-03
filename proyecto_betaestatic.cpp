	#include <iostream>
	#include <string>
	#include <vector>
	
	using namespace std;
	
	//Declaraciones de funciones, arreglos y registros
	struct pedido{
		string nombreP;
		string nombreCliente;
		float precio;
		int cantPedidos;
		float inversionXPlato; 
		int racionesDisponibles;
		int cantPredeterminada;
		float inversion;
		int diaPedido;
	};
	
	struct datosDia {
	    float ingresosDia = 0.0;
	    float inversionDia = 0.0;
	    float gananciaDia = 0.0;
	    int racionesDisponibles = 0;
	};
	
	string P[12];
	string dSemana[] = { "LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO" };
	int cantPredeterminada[12] = { 20, 15, 15, 10, 15, 20, 20, 15, 15, 25, 15, 30 };
	
	// Funciones prototipo
	string listaMenus(int x);
	void imprimirPlatosRecomendados(const string muyPR1, const string muyPR2, const string muyPR3, const string muyPR4, const string pocoPR1, const string pocoPR2, const string pocoPR3, const string pocoPR4);
	void recomendarPlato(int edadCliente, double preciosPlatos[]);
	void realizarPedidos(int edadCliente, int nC, int j, pedido pedidoC[], datosDia diaDatos[], double preciosPlatos[]);
	void precioPlato(pedido pedidoC[], int nC, int j, double preciosPlatos[]);
	void calcularIngresosYGanancias(datosDia diaDatos[], int totalClientes, float& ingresosSemana, float& gananciaSemana);
	void semanaPasada(datosDia diaDatos[], float ingresosSemana, float gananciaSemana);
	void reporteDia(datosDia diaDatos[], int diaActual, pedido pedidoC[], int totalClientes);
	void ajustarInventario(pedido pedidoC[], int numPlatos);
	void ajustarPrecios(pedido pedidoC[], int nC, double preciosPlatos[]);

	
	//BLOQUE PRINCIPAL Llamado de funciones y reportes.
	int main(void){
	  string nombreCliente, fechaPedido, Pedido;
	    int diaSemana = 0, numSemanas, cantPedido, edadCliente, i, j, nC;
	    int numPlatos = 12;
	    float ingresosTotales = 0.0;
	    float gananciaTotal = 0.0;
	    double preciosPlatos[12] = {
	    12.90,  // Arroz con pollo
	    12.50,  // Tallarines verdes con pollo
	    14.00,  // Causa peruana
	    25.00,  // Cuy al horno
	    11.50,  // Aji de gallina
	    14.00,  // Lomo saltado
	    20.00,  // Ceviche mixto
	    15.00,  // Jalea de mariscos
	    16.00,  // Tacu Tacu con bistec
	    10.00,  // Anticuchos
	    6.00,   // Torta de selva negra
	    3.50    // Arroz con leche
		};
	    
	    cout << "Ingrese el numero de semanas: ";
	    cin >> numSemanas;
	    float ingresosSemana = 0.0;
	    float gananciaSemana = 0.0;
	    //Foro maximo 100 personas,
	    pedido pedidoC[100];
	    datosDia diaDatos[7];
		//Ingreso de datos del cliente.
		for (int semana = 1; semana <= numSemanas; semana++) {
			int totalClientes = 0;
			float ingresosSemana = 0.0;
	    	float gananciaSemana = 0.0;	
	    	
			for (i = 0; i<7; ++i){
				cout << "Numero de clientes en el dia "<<dSemana[i]<<endl;
			    cin >>nC;
			    totalClientes += nC;
				for (j = 0; j<nC; ++j){	
					pedidoC[j].diaPedido = i;	
					cout << "               					 [!INGRESA   TU   EDAD!]                              "<<endl;
			        cout << endl;	
					cout << "	------------------------------------------------------------------------------------------------------"<<endl;
					cout << "	| Mira las recomendaciones que te damos de los platillos  con sus respectivas calorias segun tu edad. |"<<endl;
					cout << "	-------------------------------------------------------------------------------------------------------"<<endl;
					cout << endl;
					cout << "Primero ingresa tu EDAD:  ";
					cin >> edadCliente;
					cout << endl;
					cout << "Finalmente ingresa tu NOMBRE:  ";
					cin >> pedidoC[j].nombreCliente;
					cout << endl;
					cout << endl;
					cout << "			--------------------------------------------------------------------" << endl;
					cout << "				Te recomendamos los siguientes platillos "<< pedidoC[j].nombreCliente <<": "<< endl;
					recomendarPlato(edadCliente, preciosPlatos);
					cout << "Ingrese el nombre del pedido:  ";
					cin.ignore();
					getline(cin, pedidoC[j].nombreP);
					cout << "Ingrese la cantidad de porciones:  ";
					cin >> pedidoC[j].cantPedidos;
					cout << endl;
					cout << endl;
					cout << endl;
					cout << endl;
					//Receptor de los pedidos al chef o empleado.
					precioPlato(pedidoC, nC, j, preciosPlatos);
					realizarPedidos(edadCliente, nC, j, pedidoC, diaDatos, preciosPlatos);
				}
				diaSemana = (diaSemana + 1) % 7;
	            // Imprimir reporte del dia actual
	            reporteDia(diaDatos, i, pedidoC, totalClientes);
	          	ajustarInventario(pedidoC, numPlatos);
			}
	        calcularIngresosYGanancias(diaDatos, totalClientes, ingresosSemana, gananciaSemana);
	        semanaPasada(diaDatos, ingresosSemana, gananciaSemana);
	
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			ajustarPrecios(pedidoC, totalClientes, preciosPlatos);
			//Limpieza de datos de la semana.
			for (int j = 0; j < totalClientes; ++j) {
	            pedidoC[j].nombreP.clear();
	            pedidoC[j].nombreCliente.clear();
	            pedidoC[j].precio = 0.0;
	            pedidoC[j].inversionXPlato = 0.0;
	            pedidoC[j].cantPedidos = 0;
	            pedidoC[j].diaPedido = 0;
	        }
	    }
		
	return 0;
	}
	
	
	
	////////////////-------- SECCION MENU TACTIL ------ ///////////////////////
	
	//BLOQUE Datos de platos del menu
	string listaMenus(int x){
		
	    P[0] = "Arroz oon pollo                 630 cal      ";
	    P[1] = "Tallarines verdes con pollo     750 cal      ";
	    P[2] = "Causa peruana                   320 cal      ";
	    P[3] = "Cuy al horno                    800 cal      ";
	    P[4] = "Aji de gallina                  600 cal      ";
	    P[5] = "Lomo saltado                    710 cal      ";
	    P[6] = "Ceviche mixto                   400 cal      ";
	    P[7] = "Jalea de mariscos               760 cal      ";
	    P[8] = "Tacu Tacu con bistec            700 cal      ";
	    P[9] = "Anticuchos                      190 cal      ";
	    P[10] = "Torta de selva negra            410 cal      ";
	    P[11] = "Arroz con leche                 230 cal      ";
	
	return P[x];
	}
	
	//BLOQUE Impresion de Platos Recomendados
	void imprimirPlatosRecomendados(const string muyPR1, const string muyPR2, const string muyPR3, const string muyPR4, const string pocoPR1, const string pocoPR2, const string pocoPR3, const string pocoPR4, float mP1, float mP2, float mP3, float mP4, float pP1, float pP2, float pP3, float pP4) {
	
		cout << "			--------------------------------------------------------------------" << endl;
	    cout <<  endl;
	    cout << "						[Poco ACTIVO Fisicamente]" << endl;
	    cout <<  endl;
	    cout << "				1. "<< muyPR1 << "s/."<<mP1<< endl;
	    cout << "				2. "<< muyPR2 << "s/."<<mP2<< endl;
	    cout << "				3. "<< muyPR3 << "s/."<<mP3<< endl;
	    cout << "				4. "<< muyPR4 << "s/."<<mP4<< endl;
	    cout <<  endl;
		cout << "			--------------------------------------------------------------------" << endl;
	    cout <<  endl;
	    cout << "						[Muy ACTIVO Fisicamente]" << endl;
	    cout <<  endl;	
	    cout << "				1. "<< pocoPR1 << "s/."<<pP1<< endl;
	    cout << "				2. "<< pocoPR2 << "s/."<<pP2<< endl;
	    cout << "				3. "<< pocoPR3 << "s/."<<pP3<< endl;
	    cout << "				4. "<< pocoPR4 << "s/."<<pP4<< endl;
	    cout <<  endl;	
		cout << "			--------------------------------------------------------------------" << endl;
	    cout <<  endl;
	}
	
	//BLOQUE Recomendaciones de platos. 
	void recomendarPlato(int edadCliente, double preciosPlatos[]) {
	    string muyPR1, muyPR2, muyPR3, muyPR4;
	    string pocoPR1, pocoPR2, pocoPR3, pocoPR4;
	    float mP1 = 0.0, mP2 = 0.0, mP3 = 0.0, mP4 = 0.0;
	    float pP1 = 0.0, pP2 = 0.0, pP3 = 0.0, pP4 = 0.0;
	    
	    if (edadCliente >= 2 && edadCliente <= 8) {
	        // Edad 2-8 (Poco ACTIVO)
	        muyPR1 = listaMenus(9); mP1 = preciosPlatos[9];
	        muyPR2 = listaMenus(11); mP2 = preciosPlatos[11];
	        muyPR3 = listaMenus(2); mP3 = preciosPlatos[2];
	        muyPR4 = listaMenus(6); mP4 = preciosPlatos[6];
	
	        // Edad 2-8 (Muy ACTIVO)
	        pocoPR1 = listaMenus(2); pP1 = preciosPlatos[2];
	        pocoPR2 = listaMenus(6); pP2 = preciosPlatos[6];
	        pocoPR3 = listaMenus(10); pP3 = preciosPlatos[10];
	        pocoPR4 = listaMenus(4); pP4 = preciosPlatos[4];
	    } else if (edadCliente >= 9 && edadCliente <= 12) {
	        // Edad 9-12 (Poco ACTIVO)
	        muyPR1 = listaMenus(2); mP1 = preciosPlatos[2];
	        muyPR2 = listaMenus(6); mP2 = preciosPlatos[6];
	        muyPR3 = listaMenus(10); mP3 = preciosPlatos[10];
	        muyPR4 = listaMenus(4); mP4 = preciosPlatos[4];
	
	        // Edad 9-12 (Muy ACTIVO)
	        pocoPR1 = listaMenus(6); pP1 = preciosPlatos[6];
	        pocoPR2 = listaMenus(10); pP2 = preciosPlatos[10];
	        pocoPR3 = listaMenus(4); pP3 = preciosPlatos[4];
	        pocoPR4 = listaMenus(0); pP4 = preciosPlatos[0];
	    } else if (edadCliente >= 13 && edadCliente <= 19) {
	        // Edad 13-19 (Poco ACTIVO)
	        muyPR1 = listaMenus(6); mP1 = preciosPlatos[6];
	        muyPR2 = listaMenus(10); mP2 = preciosPlatos[10];
	        muyPR3 = listaMenus(4); mP3 = preciosPlatos[4];
	        muyPR4 = listaMenus(0); mP4 = preciosPlatos[0];
	
	        // Edad 13-19 (Muy ACTIVO)
	        pocoPR1 = listaMenus(4); pP1 = preciosPlatos[4];
	        pocoPR2 = listaMenus(0); pP2 = preciosPlatos[0];
	        pocoPR3 = listaMenus(8); pP3 = preciosPlatos[8];
	        pocoPR4 = listaMenus(5); pP4 = preciosPlatos[5];
	    } else if (edadCliente >= 20 && edadCliente <= 31) {
	        // Edad 20-31 (Poco ACTIVO)
	        muyPR1 = listaMenus(10); mP1 = preciosPlatos[10];
	        muyPR2 = listaMenus(4); mP2 = preciosPlatos[4];
	        muyPR3 = listaMenus(0); mP3 = preciosPlatos[0];
	        muyPR4 = listaMenus(8); mP4 = preciosPlatos[8];
	
	        // Edad 20-31 (Muy ACTIVO)
	        pocoPR1 = listaMenus(5); pP1 = preciosPlatos[5];
	        pocoPR2 = listaMenus(1); pP2 = preciosPlatos[1];
	        pocoPR3 = listaMenus(7); pP3 = preciosPlatos[7];
	        pocoPR4 = listaMenus(3); pP4 = preciosPlatos[3];
	    } else if (edadCliente >= 32 && edadCliente <= 50) {
	        // Edad 32-49 (Poco ACTIVO)
	        muyPR1 = listaMenus(6); mP1 = preciosPlatos[6];
	        muyPR2 = listaMenus(10); mP2 = preciosPlatos[10];
	        muyPR3 = listaMenus(4); mP3 = preciosPlatos[4];
	        muyPR4 = listaMenus(0); mP4 = preciosPlatos[0];
	
	        // Edad 32-49 (Muy ACTIVO)
	        pocoPR1 = listaMenus(0); pP1 = preciosPlatos[0];
	        pocoPR2 = listaMenus(5); pP2 = preciosPlatos[5];
	        pocoPR3 = listaMenus(1); pP3 = preciosPlatos[1];
	        pocoPR4 = listaMenus(7); pP4 = preciosPlatos[7];
	    } else if (edadCliente >= 51) {
	        // Edad 51 o mas (Poco ACTIVO)
	        muyPR1 = listaMenus(2); mP1 = preciosPlatos[2];
	        muyPR2 = listaMenus(6); mP2 = preciosPlatos[6];
	        muyPR3 = listaMenus(10); mP3 = preciosPlatos[10];
	        muyPR4 = listaMenus(4); mP4 = preciosPlatos[4];
	
	        // Edad 51 o mas (Muy ACTIVO)
	        pocoPR1 = listaMenus(4); pP1 = preciosPlatos[4];
	        pocoPR2 = listaMenus(0); pP2 = preciosPlatos[0];
	        pocoPR3 = listaMenus(5); pP3 = preciosPlatos[5];
	        pocoPR4 = listaMenus(1); pP4 = preciosPlatos[1];
	    } else {
	        cout << "------------------------------------------------" << endl;
	        cout << "No tiene edad suficiente para recomendaciones o ingres� un dato inv�lido. Intente nuevamente." << endl;
	        return;
	    }
	
	    imprimirPlatosRecomendados(muyPR1, muyPR2, muyPR3, muyPR4, pocoPR1, pocoPR2, pocoPR3, pocoPR4, mP1, mP2, mP3, mP4, pP1, pP2, pP3, pP4);
	}
	
	//BLOQUE Realizar Pedidos  y RECIBO.
void realizarPedidos(int edadCliente, int nC, int j, pedido pedidoC[], datosDia diaDatos[], double preciosPlatos[]) {
    // Verificar si hay suficientes raciones disponibles
    int racionesDisponibles = pedidoC[j].racionesDisponibles;

    if (racionesDisponibles <= 0 || racionesDisponibles < pedidoC[j].cantPedidos) {
        cout << "Lo sentimos, el plato \"" << pedidoC[j].nombreP << "\" no tiene suficientes raciones disponibles para el d�a de hoy." << endl;
        cout << "Por favor, elija otro plato o disminuya la cantidad pedida." << endl;

        // Leer el nombre del nuevo pedido
        cin.ignore();
        cout << "Ingrese el nombre del nuevo pedido: ";
        getline(cin, pedidoC[j].nombreP);

        // Leer la nueva cantidad de porciones
        cout << "Ingrese la nueva cantidad de porciones (debe ser menor o igual a " << racionesDisponibles << "): ";
        cin >> pedidoC[j].cantPedidos;

        // Verificar que la nueva cantidad sea un valor v�lido (mayor a 0 y menor o igual a las raciones disponibles)
        while (pedidoC[j].cantPedidos <= 0 || pedidoC[j].cantPedidos > racionesDisponibles) {
            cout << "La cantidad ingresada no es v�lida. Ingrese una cantidad v�lida: ";
            cin >> pedidoC[j].cantPedidos;
        }

        cin.ignore(); // Agregar esta l�nea para ignorar el salto de l�nea

        // Actualizar cantidad de raciones disponibles
        racionesDisponibles -= pedidoC[j].cantPedidos;
        pedidoC[j].racionesDisponibles = racionesDisponibles;
    } else {
        // El pedido se puede realizar correctamente
        float totalPrecio = 0.0;
        pedidoC[j].inversion = pedidoC[j].inversionXPlato * pedidoC[j].cantPedidos * pedidoC[j].cantPredeterminada;
        pedidoC[j].racionesDisponibles -= pedidoC[j].cantPredeterminada;
; // Actualizar cantidad de raciones disponibles
        cout << "        /////////////////////////////////////////////////////" << endl;
        cout << endl;
        cout << "            [Recibo de Consumo, Restaurante \"RICOMAR\"]" << endl;
        cout << endl;
        cout << endl;
        cout << "          Nombre del cliente:    " << pedidoC[j].nombreCliente << endl;
        cout << "          Plato:        " << pedidoC[j].nombreP << endl;
        cout << "          Cantidad:       		 " << pedidoC[j].cantPedidos << endl;
        totalPrecio = pedidoC[j].precio * pedidoC[j].cantPedidos;
        cout << "          Precio por unidad:    s/." << pedidoC[j].precio << endl;
        cout << "          ----------------------------------------------" << endl;
        cout << "          Total a pagar:    s/." << totalPrecio << endl;
        cout << endl;
        cout << "        /////////////////////////////////////////////////////" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        // Actualizar datos del d�a en la estructura diaDatos
        int diaActual = pedidoC[j].diaPedido;
        diaDatos[diaActual].ingresosDia += totalPrecio;
        diaDatos[diaActual].inversionDia += (pedidoC[j].inversionXPlato * pedidoC[j].cantPredeterminada);
        diaDatos[diaActual].gananciaDia = diaDatos[diaActual].ingresosDia - diaDatos[diaActual].inversionDia;
    }
}
	
	////////////////-------- SECCION INVERSION ------ ///////////////////////
	
	//BLOQUE Precio Pedido
	void precioPlato(pedido pedidoC[], int nC, int j, double preciosPlatos[]) {
	    if (pedidoC[j].nombreP == "Arroz con pollo") {
	        pedidoC[j].precio = preciosPlatos[0];
	        pedidoC[j].inversionXPlato = 8.00;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[0];
	    } else if (pedidoC[j].nombreP == "Tallarines verdes con pollo") {
	        pedidoC[j].precio = preciosPlatos[1];
	        pedidoC[j].inversionXPlato = 7.30;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[1];
	    } else if (pedidoC[j].nombreP == "Causa peruana") { 
	        pedidoC[j].precio = preciosPlatos[2];
	        pedidoC[j].inversionXPlato = 4.60;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[2];
	    } else if (pedidoC[j].nombreP == "Cuy al horno") {
	        pedidoC[j].precio = preciosPlatos[3];
	        pedidoC[j].inversionXPlato = 18.00;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[3];
	    } else if (pedidoC[j].nombreP == "Aji de gallina") {
	        pedidoC[j].precio = preciosPlatos[4];
	        pedidoC[j].inversionXPlato = 5.60;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[4];
	    } else if (pedidoC[j].nombreP == "Lomo saltado") {
	        pedidoC[j].precio = preciosPlatos[5];
	        pedidoC[j].inversionXPlato = 7.50;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[5];
	    } else if (pedidoC[j].nombreP == "Ceviche mixto") {
	        pedidoC[j].precio = preciosPlatos[6];
	        pedidoC[j].inversionXPlato = 7.50;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[6];
	    } else if (pedidoC[j].nombreP == "Jalea de mariscos") {
	        pedidoC[j].precio = preciosPlatos[7];
	        pedidoC[j].inversionXPlato = 8.60;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[7];
	    } else if (pedidoC[j].nombreP == "Tacu Tacu con bistec") {
	        pedidoC[j].precio = preciosPlatos[8];
	        pedidoC[j].inversionXPlato = 8.60;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[8];
	    } else if (pedidoC[j].nombreP == "Anticuchos") {
	        pedidoC[j].precio = preciosPlatos[9];
	        pedidoC[j].inversionXPlato = 4.60;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[9];
	    } else if (pedidoC[j].nombreP == "Torta de selva negra") {
	        pedidoC[j].precio = preciosPlatos[10];
	        pedidoC[j].inversionXPlato = 4.00;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[10];
	    } else if (pedidoC[j].nombreP == "Arroz con leche") {
	        pedidoC[j].precio = preciosPlatos[11];
	        pedidoC[j].inversionXPlato = 1.50;
	        pedidoC[j].cantPredeterminada = cantPredeterminada[11];
	    } else {
	        cout << "El pedido ingresado no tiene un precio definido. (Reportar a administracion)" << endl;
	    }
	}
	// BLOQUE Reporte diario
	void reporteDia(datosDia diaDatos[], int diaActual, pedido pedidoC[], int totalClientes) {
		float totalInversionDia = 0.0;
		 
	    cout << "--------------------------------------------------" << endl;
	    cout << "Resumen dia "<<dSemana[diaActual] << endl;
	    cout << "-------------------------------------------" << endl;
	    cout << "Platos pedidos:" << endl;
	    cout << "-------------------------------------------" << endl;
	    for (int j = 0; j < totalClientes; ++j) {
	        if (pedidoC[j].diaPedido == diaActual) {
	        	totalInversionDia += pedidoC[j].inversionXPlato * pedidoC[j].cantPedidos * pedidoC[j].cantPredeterminada;
	            cout << "Cliente: " << pedidoC[j].nombreCliente << endl;
	            cout << "Plato: " << pedidoC[j].nombreP << endl;
	            cout << "Cantidad: " << pedidoC[j].cantPedidos << endl;
	            cout << "Precio por unidad: s/." << pedidoC[j].precio << endl;
	            cout << "Total a pagar: s/." << pedidoC[j].precio * pedidoC[j].cantPedidos << endl;
	            cout << "-------------------------------------------" << endl;
	        }
	    }
	    diaDatos[diaActual].inversionDia = totalInversionDia;
	    cout << endl;
	    cout << "Ingresos del dia: s/." << diaDatos[diaActual].ingresosDia << endl;
	    cout << "Inversion del dia: s/." << diaDatos[diaActual].inversionDia << endl;
	    cout << endl;
	    cout << "<<< Ganancia del dia: s/." << diaDatos[diaActual].gananciaDia << " >>>" << endl;
	    cout << "-------------------------------------------" << endl;
	}
	
	//BLOQUE Menu de ajustes a cantidad de raciones disponibles.
void ajustarInventario(pedido pedidoC[], int numPlatos) {
    int opcionPlato;
    int nuevaCantidad;

    cout << "Platos disponibles: " << endl;
    for (int i = 0; i < numPlatos; i++) {
        cout << i << ". " << listaMenus(i) << endl;
    }

    cout << "Ingrese el n�mero del plato que desea ajustar: ";
    cin >> opcionPlato;

    if (opcionPlato >= 0 && opcionPlato < numPlatos) {
        cout << "Ingrese la nueva cantidad predeterminada para " << listaMenus(opcionPlato) << ": ";
        cin >> nuevaCantidad;

        if (nuevaCantidad >= 0) {
            pedidoC[opcionPlato].cantPredeterminada = nuevaCantidad; // Actualiza la cantidad predeterminada
            pedidoC[opcionPlato].racionesDisponibles = nuevaCantidad - pedidoC[opcionPlato].cantPedidos; // Actualiza las raciones disponibles
            pedidoC[opcionPlato].inversion = pedidoC[opcionPlato].inversionXPlato * pedidoC[opcionPlato].cantPedidos * pedidoC[opcionPlato].cantPredeterminada; // Actualiza la inversi�n total
            cout << "La cantidad de raciones disponibles para " << listaMenus(opcionPlato) << " ha sido ajustada a " << nuevaCantidad << endl;
            cout << "Inversi�n total para " << listaMenus(opcionPlato) << ": s/." << pedidoC[opcionPlato].inversion << endl;
        } else {
            cout << "La cantidad debe ser un valor v�lido (mayor o igual a 0)." << endl;
        }
    } else {
        cout << "Opci�n de plato inv�lida." << endl;
    }
}

	//BLOQUE Calcular INGRESOS y GANANCIA SEMANAL
	void calcularIngresosYGanancias(datosDia diaDatos[], int totalClientes, float& ingresosSemana, float& gananciaSemana) {
	    ingresosSemana = 0.0;
	    gananciaSemana = 0.0;
	    float inversionSemana = 0.0;
	   	for (int i = 0; i < 7; ++i) {
        inversionSemana += diaDatos[i].inversionDia;
        ingresosSemana += diaDatos[i].ingresosDia;
   		}
   		gananciaSemana = ingresosSemana - inversionSemana;
	}
	
	//BLOQUE Datos semana pasada.
	void semanaPasada(datosDia diaDatos[], float ingresosSemana, float gananciaSemana) {
	    float ingresosTotales = 0.0;
	    float gananciaTotal = 0.0;
	
	    for (int i = 0; i < 7; ++i) {
	        diaDatos[i].gananciaDia = diaDatos[i].ingresosDia - diaDatos[i].inversionDia;
	        ingresosTotales += diaDatos[i].ingresosDia;
	        gananciaTotal += diaDatos[i].gananciaDia;
		}
	    // Imprimimos los resultados finales de la semana pasada
	    cout << "///////////////////////////////////////////////////////////////////////////////"<< endl;
	    cout << endl;
	    cout << "//////////////////////////////////////////////////////////////////////////////"<< endl;
	    cout << endl;
	    cout << endl;
	    cout << "---------------- RESUMEN DE ESTA SEMANA PASADA -------------"<< endl;
	    cout << endl;
	    cout << endl;
	    cout << "Ingresos totales de la semana: s/." << ingresosSemana << endl;
	    cout << "Ganancia total de la semana: s/." << gananciaSemana << endl;
	    cout << "//////////////////////////////////////////////////" << endl;
	    if (gananciaSemana >= 0) {
	        cout << "En la semana ha tenido ganancias. Felicitaciones!" << endl;
	    } else {
	        cout << "En la semana ha tenido perdidas significativas, URGENTEMENTE haga cambios en los platos." << endl;
	    }
	    cout << "//////////////////////////////////////////////////" << endl;
	}
	
	
	//BLOQUE Ajustes de precios de platos.
	void ajustarPrecios(pedido pedidoC[], int nC, double preciosPlatos[]) {
    cout << "********** MENU DE AJUSTES DE PRECIOS **********" << endl;
    cout << endl;	
    cout << "[ 1 ] Realizar Ajustes a los precios" << endl;
    cout << "[ - ] Salir" << endl;
    cout << endl;	
    cout << "***********************************************" << endl;

    char opcion;
    cin >> opcion;

    while (opcion == '1') {
        cout << "******************* LISTA DE PLATOS ******************" << endl;
        for (int i = 0; i < 12; i++) {
            cout << "[" << i << "]. " << listaMenus(i) << " (Precio actual: s/." << preciosPlatos[i] << ")" << endl;
        }
        cout << "******************************************************" << endl;

        int opcionPlato;
        cin >> opcionPlato;
        if (opcionPlato >= 0 && opcionPlato <= 11) {
            cout << "Ingrese el nuevo precio para " << listaMenus(opcionPlato) << ": s/. ";
            float nuevoPrecio;
            cin >> nuevoPrecio;
            preciosPlatos[opcionPlato] = nuevoPrecio;
            cout << "El precio de " << listaMenus(opcionPlato) << " ha sido ajustado a s/." << nuevoPrecio << endl;
        } else {
            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }

        cout << endl;
        cout << "�Desea ajustar otro plato?" << endl;
        cout << "[ 1 ] SI" << endl;
        cout << "[ - ] NO (Salir)" << endl;
        cin >> opcion;

        if (opcion != '1') {
            break;
        }
    }
}
