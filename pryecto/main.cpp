#include <iostream>
#include <fstream>
#include<string>

using namespace std;

void mostrarEstadoVuelo(int estado){
    if(estado == 1)
            cout<<"Vuelo Programado."<<endl;
    else
        cout<<"Vuelo Realizado."<<endl;

}

void mostrarEstadoPasajero(int estado){
    if(estado == 1)
            cout<<"Estado: Pasajero en reserva."<<endl;
    else
        cout<<"Estado: Pasajero a bordo"<<endl;

}

struct Hora{
    int hora;
    int minutos;
};

struct Fecha{
    int dia;
    int mes;
    int anio;
};

struct Pasajero{

    string nombre;
    int edad;
    string numDocumento;
    int estado; // 1: reserva | 2: abordo
    Pasajero *sgtePasajero;
    string numVuelo;
};

struct Vuelo{

    int estado; // Estado de un vuelo 1: programado 2:realizado
    string numVuelo;
    string origen;
    string destino;
    string nomPiloto;
    string matriAvion;
    Hora *hora;
    Fecha *fecha;
    Vuelo *sgteVuelo;
    Pasajero *pasajeros;

};

void insertarVuelos(Vuelo *&nuevoVuelo, Vuelo *&PTRVuelo){

    if(PTRVuelo == NULL){
        PTRVuelo = nuevoVuelo;
    }else{

        Vuelo *j = PTRVuelo;
        while(j->sgteVuelo != NULL){
            j = j->sgteVuelo;
        }
        j->sgteVuelo = nuevoVuelo;
    }

}

void insertarPasajero(Pasajero *nuevo_pasajero, Pasajero *&PTR){

    if(PTR == NULL){
        PTR = nuevo_pasajero;

    }else{

        Pasajero *j = PTR;
        while(j->sgtePasajero != NULL){
            j = j->sgtePasajero;
        }
        j->sgtePasajero = nuevo_pasajero;

    }


}

void mostrarListaPasajeros(Pasajero *PTR){

        Pasajero *j = PTR;
        cout<<"Listado de pasajeros"<<endl;
        while(j->sgtePasajero != NULL){
            cout<<"Nombre: "<<j->nombre<<endl;
            cout<<"Edad: "<<j->edad<<endl;
            mostrarEstadoPasajero(j->estado);
            cout<<"Numero de vuelo: "<<j->numVuelo<<endl;
            cout<<"Documento: "<<j->numDocumento<<endl;
            cout<<"----------------------------------"<<endl;
            j = j->sgtePasajero;
        }
        cout<<"Nombre: "<<j->nombre<<endl;
        cout<<"Edad: "<<j->edad<<endl;
        mostrarEstadoPasajero(j->estado);
        cout<<"Numero de vuelo: "<<j->numVuelo<<endl;
        cout<<"Documento: "<<j->numDocumento<<endl;
        cout<<"----------------------------------"<<endl;
}

void mostrarListaVuelos(Vuelo *PTR){

        Vuelo *j = PTR;
        cout<<"Listado de vuelos"<<endl;
        while(j->sgteVuelo != NULL){
            cout<<"Numero del vuelo: "<<j->numVuelo<<endl;
            mostrarEstadoVuelo(j->estado);
            cout<<"Origen: "<<j->origen<<endl;
            cout<<"Destino: "<<j->destino<<endl;
            cout<<"Nombre del piloto: "<<j->nomPiloto<<endl;
            cout<<"Matricula del avion: "<<j->matriAvion<<endl;
            cout<<"Hora: "<<j->hora->hora<<":"<<j->hora->minutos<<endl;
            cout<<"Fecha: "<<j->fecha->dia<<"/"<<j->fecha->mes<<"/"<<j->fecha->anio<<endl;
            Pasajero *iter_pasajero = j->pasajeros;
            cout<<"Pasajeros del vuelo"<<endl;
            while(iter_pasajero->sgtePasajero!=NULL){

                cout<<iter_pasajero->nombre<<" -- ";

                iter_pasajero = iter_pasajero->sgtePasajero;
            }
            cout<<iter_pasajero->nombre<<endl;
            cout<<"----------------------------------"<<endl;
            j = j->sgteVuelo;
        }
        cout<<"Numero del vuelo: "<<j->numVuelo<<endl;
        mostrarEstadoVuelo(j->estado);
        cout<<"Origen: "<<j->origen<<endl;
        cout<<"Destino: "<<j->destino<<endl;
        cout<<"Nombre del piloto: "<<j->nomPiloto<<endl;
        cout<<"Matricula del avion: "<<j->matriAvion<<endl;
        cout<<"Hora: "<<j->hora->hora<<":"<<j->hora->minutos<<endl;
        cout<<"Fecha: "<<j->fecha->dia<<"/"<<j->fecha->mes<<"/"<<j->fecha->anio<<endl;
        cout<<"----------------------------------"<<endl;
}

void mostrarVuelosProgramadosORealizado(Vuelo *PTR, int estado){

        Vuelo *j = PTR;
        if(estado == 1)
            cout<<"Listado de vuelos Programados"<<endl;
        else
            cout<<"Listado de vuelos Realizados"<<endl;

        while(j->sgteVuelo != NULL){
            if(j->estado == estado){
            cout<<"Matricula: "<<j->matriAvion<<endl;
            cout<<"Numero del vuelo: "<<j->numVuelo<<endl;
            cout<<"Nombre del piloto: "<<j->nomPiloto<<endl;
            cout<<"Origen: "<<j->origen<<endl;
            cout<<"Destino: "<<j->destino<<endl;

            cout<<"----------------------------------"<<endl;
            }

            j = j->sgteVuelo;
        }
        if(j->estado == estado){
            cout<<"Matricula: "<<j->matriAvion<<endl;
            cout<<"Numero del vuelo: "<<j->numVuelo<<endl;
            cout<<"Nombre del piloto: "<<j->nomPiloto<<endl;
            cout<<"Origen: "<<j->origen<<endl;
            cout<<"Destino: "<<j->destino<<endl;

            cout<<"----------------------------------"<<endl;
        }
}

void mostrarPasajerosDeVueloProgramadosORealizado(Vuelo *PTR, string numVuelo){

        Vuelo *j = PTR;
        cout<<"Listado de pasajeros por vuelo"<<endl;

        while(j->sgteVuelo != NULL){
            if(j->numVuelo == numVuelo){

                Pasajero *k = j->pasajeros;
                while(k->sgtePasajero != NULL){

                    cout<<"----------------------------------"<<endl;
                    cout<<"Nombre: "<<k->nombre<<endl;
                    cout<<"Documento: "<<k->numDocumento<<endl;
                    cout<<"----------------------------------"<<endl;
                    k = k->sgtePasajero;
                }
                cout<<"----------------------------------"<<endl;
                cout<<"Nombre: "<<k->nombre<<endl;
                cout<<"Documento: "<<k->numDocumento<<endl;
                cout<<"----------------------------------"<<endl;
            }

            j = j->sgteVuelo;
        }
       if(j->numVuelo == numVuelo){
                Pasajero *k = j->pasajeros;
                while(k->sgtePasajero != NULL){

                    cout<<"----------------------------------"<<endl;
                    cout<<"Nombre: "<<k->nombre<<endl;
                    cout<<"Documento: "<<k->numDocumento<<endl;
                    cout<<"----------------------------------"<<endl;
                    k = k->sgtePasajero;
                }
                cout<<"----------------------------------"<<endl;
                cout<<"Nombre: "<<k->nombre<<endl;
                cout<<"Documento: "<<k->numDocumento<<endl;
                cout<<"----------------------------------"<<endl;
            }
}

void mostrarListaVuelosXPasajero(Pasajero *PTRPasajero, Vuelo *PTRVuelo, int estado){

        Pasajero *iter_pasajero = PTRPasajero;

        cout<<"Listado de pasajeros"<<endl;
        while(iter_pasajero->sgtePasajero != NULL){

            Vuelo *iter_vuelo = PTRVuelo;
            cout<<"-------------------------------"<<endl;
            cout<<"Pasajero: "<<iter_pasajero->nombre<<endl;
            cout<<"Documento: "<<iter_pasajero->numDocumento<<endl;
            cout<<"-----------"<<endl;
            while(iter_vuelo->sgteVuelo != NULL){

                Pasajero *iter_lista_pasajeros = iter_vuelo->pasajeros;

                if(iter_vuelo->estado == estado){
                    while(iter_lista_pasajeros->sgtePasajero != NULL){

                        if(iter_lista_pasajeros->numDocumento == iter_pasajero->numDocumento){

                            cout<<"Vuelo Numero: "<<iter_vuelo->numVuelo<<endl;

                            mostrarEstadoVuelo(iter_vuelo->estado);
                            cout<<"-----------"<<endl;

                        }

                        iter_lista_pasajeros = iter_lista_pasajeros->sgtePasajero;
                    }
                    if(iter_lista_pasajeros->numDocumento == iter_pasajero->numDocumento){

                        cout<<"Vuelo Numero: "<<iter_vuelo->numVuelo<<endl;
                        mostrarEstadoVuelo(iter_vuelo->estado);
                        cout<<"-----------"<<endl;

                    }
                }


                iter_vuelo = iter_vuelo->sgteVuelo;
            }

            if(iter_vuelo->estado == estado){
                Pasajero *iter_lista_pasajeros = iter_vuelo->pasajeros;

                while(iter_lista_pasajeros->sgtePasajero != NULL){

                    if(iter_lista_pasajeros->numDocumento == iter_pasajero->numDocumento){

                        cout<<"Vuelo Numero: "<<iter_vuelo->numVuelo<<endl;
                        mostrarEstadoVuelo(iter_vuelo->estado);
                        cout<<"-----------"<<endl;

                    }

                    iter_lista_pasajeros = iter_lista_pasajeros->sgtePasajero;
                }
                if(iter_lista_pasajeros->numDocumento == iter_pasajero->numDocumento){

                    cout<<"Vuelo Numero: "<<iter_vuelo->numVuelo<<endl;
                    mostrarEstadoVuelo(iter_vuelo->estado);
                    cout<<"-----------"<<endl;

                }
                cout<<"-------------------------------"<<endl;
            }

            iter_pasajero = iter_pasajero->sgtePasajero;
        }
}

void cambiarEstadoVuelo(Vuelo *PTR_vuelos, string numeroVuelo){

    Vuelo *iter_vuelo = PTR_vuelos;

    while(iter_vuelo->sgteVuelo != NULL){

        if(numeroVuelo == iter_vuelo->numVuelo){
            iter_vuelo->estado = 2;
        }

        iter_vuelo = iter_vuelo->sgteVuelo;
    }

    if(numeroVuelo == iter_vuelo->numVuelo){
        iter_vuelo->estado = 2;
    }
}

void cambiarEstadoPasajero(Pasajero *PTR_pasajero, string documento){

    Pasajero *iter_pasajero = PTR_pasajero;

    while(iter_pasajero->sgtePasajero != NULL){

        if(documento == iter_pasajero->numDocumento){
            iter_pasajero->estado = 2;
        }

        iter_pasajero = iter_pasajero->sgtePasajero;
    }

    if(documento == iter_pasajero->numDocumento){
        iter_pasajero->estado = 2;
    }
}

void leerVuelos(string fileName, Vuelo *&PTRVuelo){
    ifstream archivo(fileName);
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {

            Vuelo *nuevoVuelo = new Vuelo;
            Hora *nuevaHora = new Hora;
            Fecha *NuevaFecha = new Fecha;

            nuevoVuelo->sgteVuelo = NULL;
            nuevoVuelo->pasajeros = NULL;


            nuevoVuelo->estado = stoi(linea.substr(0,linea.find_first_of("|"))) ;
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            nuevoVuelo->numVuelo = linea.substr(0,linea.find_first_of("|"));
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            nuevoVuelo->origen = linea.substr(0,linea.find_first_of("|"));
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            nuevoVuelo->destino = linea.substr(0,linea.find_first_of("|"));
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            nuevoVuelo->nomPiloto = linea.substr(0,linea.find_first_of("|"));
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            nuevoVuelo->matriAvion = linea.substr(0,linea.find_first_of("|"));
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            string hora = linea.substr(0,linea.find_first_of("|"));
            nuevaHora->hora = stoi(hora.substr(0,hora.find_first_of(":")));
            hora = hora.substr(hora.find_first_of(":")+1,hora.size());
            nuevaHora->minutos = stoi(hora);
            nuevoVuelo->hora = nuevaHora;


            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            string fecha = linea.substr(0,linea.size());

            NuevaFecha->dia = stoi(fecha.substr(0,fecha.find_first_of("/")));

            fecha = fecha.substr(fecha.find_first_of("/")+1,fecha.size());

            NuevaFecha->mes = stoi(fecha.substr(0,fecha.find_first_of("/")));
            fecha = fecha.substr(fecha.find_first_of("/")+1,fecha.size());
            NuevaFecha->anio = stoi(fecha);

            nuevoVuelo->fecha = NuevaFecha;

            insertarVuelos(nuevoVuelo, PTRVuelo);


        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." << endl;
    }
}

void leerPasajero(string fileName, Pasajero *&PTRPasajero){
    ifstream archivo(fileName);
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {

            Pasajero *nuevoPasajero = new Pasajero;

            nuevoPasajero->sgtePasajero = NULL;

            nuevoPasajero->numDocumento = linea.substr(0,linea.find_first_of("|")) ;
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            nuevoPasajero->edad = stoi(linea.substr(0,linea.find_first_of("|")));
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            nuevoPasajero->nombre = linea.substr(0,linea.find_first_of("|"));
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            nuevoPasajero->estado = stoi(linea.substr(0,linea.find_first_of("|")));
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());

            nuevoPasajero->numVuelo = linea.substr(0,linea.find_first_of("|"));
            linea = linea.substr(linea.find_first_of("|")+1,linea.length());



            insertarPasajero(nuevoPasajero, PTRPasajero);


        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." << endl;
    }
}


void organizarPasajerosXVuelo(Pasajero *PTRPasajeros, Vuelo *PTRVuelos){

    Vuelo *vuelo_iter = PTRVuelos;
    while(vuelo_iter->sgteVuelo!=NULL){

        Pasajero *pasajero_iter = PTRPasajeros;
        Pasajero *lista_pasajeros = new Pasajero;
        lista_pasajeros->sgtePasajero = NULL;
        lista_pasajeros = NULL;
        while(pasajero_iter->sgtePasajero!=NULL){
            if(pasajero_iter->numVuelo == vuelo_iter->matriAvion){

                Pasajero *nuevo = new Pasajero;
                nuevo->edad = pasajero_iter->edad;
                nuevo->estado  = pasajero_iter->estado;
                nuevo->nombre = pasajero_iter->nombre;
                nuevo->numDocumento = pasajero_iter->numDocumento;
                nuevo->numVuelo = pasajero_iter->numVuelo;
                nuevo->sgtePasajero = NULL;

                insertarPasajero(nuevo,lista_pasajeros);

            }

            pasajero_iter = pasajero_iter->sgtePasajero;

        }
        vuelo_iter->pasajeros = lista_pasajeros;

        vuelo_iter = vuelo_iter->sgteVuelo;
    }
    Pasajero *pasajero_iter = PTRPasajeros;
    Pasajero *lista_pasajeros = new Pasajero;
    while(pasajero_iter->sgtePasajero!=NULL){

        if(pasajero_iter->numVuelo == vuelo_iter->matriAvion){
            insertarPasajero(pasajero_iter,lista_pasajeros);
        }

        pasajero_iter = pasajero_iter->sgtePasajero;

    }
    vuelo_iter->pasajeros = lista_pasajeros;


}

int main()
{
    Pasajero * PTRPasajero = NULL;
    Vuelo * PTRVuelo = NULL;
    int op, estado_vuelo;
    string numeroVuelo, documentoPasajero;

    cout<<"Bienvenido a la gestion de vuelos con listas simples"<<endl;
    do{
        cout<<"1. Leer vuelos y pasajeros"<<endl;
        cout<<"2. Mostrar lista de vuelos"<<endl;
        cout<<"3. Mostrar lista pasajeros"<<endl;
        cout<<"4. Mostrar vuelos programados o realizados"<<endl;
        cout<<"5. Mostrar lista de vuelos por pasajero"<<endl;
        cout<<"6. Cambiar estado de un vuelo"<<endl;
        cout<<"7. Cambiar estado de un pasajero"<<endl;
        cout<<"8. Mostrar lista de pasajero de vuelo programado o realizado"<<endl;
        cout<<"9. Salir"<<endl;
        cin>>op;

        switch(op){
            case 1:{
                leerVuelos("vuelos.txt",PTRVuelo);
                leerPasajero("pasajeros.txt",PTRPasajero);
                organizarPasajerosXVuelo(PTRPasajero,PTRVuelo);
                break;
            }
            case 2:{
                mostrarListaVuelos(PTRVuelo);
                break;
            }
            case 3:{
                mostrarListaPasajeros(PTRPasajero);
                break;
            }
            case 4:{

                cout<<"¿qué estado busca?"<<endl;
                cout<<"1. Programado"<<endl;
                cout<<"2. Realizado"<<endl;
                cin>>estado_vuelo;
                mostrarVuelosProgramadosORealizado(PTRVuelo,estado_vuelo);
                break;
            }
            case 5:{
                cout<<"¿qué estado busca?"<<endl;
                cout<<"1. Programado"<<endl;
                cout<<"2. Realizado"<<endl;
                cin>>estado_vuelo;
                mostrarListaVuelosXPasajero(PTRPasajero,PTRVuelo,estado_vuelo);
                break;
            }
            case 6:{

                cout<<"Ingrese el numero del vuelo"<<endl;
                cin>>numeroVuelo;
                cambiarEstadoVuelo(PTRVuelo, numeroVuelo);
                break;
            }
            case 7:{
                cout<<"Ingrese el numero del documento del pasajero"<<endl;
                cin>>documentoPasajero;
                cambiarEstadoPasajero(PTRPasajero, documentoPasajero);
                break;
            }
            case 8:{
                cout<<"Ingrese el numero del vuelo"<<endl;
                cin>>numeroVuelo;
                mostrarPasajerosDeVueloProgramadosORealizado(PTRVuelo,numeroVuelo);

                break;
            }
            case 9:{
                cout<<"gracias por participar"<<endl;
                break;
            }
            default:{
                cout<<"Valor no valido"<<endl;
                break;
            }
        }


    }while(op!=9);

    return 0;
}
