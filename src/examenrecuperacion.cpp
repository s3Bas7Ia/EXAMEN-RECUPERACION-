#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>
#include "../lib/mgUtility.h"
#include "../lib/mgcolor.h"
using namespace std;

const string MGCEDULA = "1727470468";
const string MGNOMBRE = "Mateo Sebastian Guerrero Barba";

struct mgCoordenada
{
    int capBelica;
    string geolocalizacion;
    string detArsenal;
    struct mgCoordenada *izq, *der;
};

typedef struct mgCoordenada *ABB;
ABB arbol            = NULL ;
int arbolNroNodos    = 0 ;
int arbolCapBelica   = 0 ;
string arbolSecCarga = "" ;
int const TKError    = -1 ;  
int const TKBomba    = -2 ;
string const ALFA    = "abc." ;

ABB crearNodo(const string data)  
{
    try
    {
        vector<string> splitData;
        mgSplitStr(data,',',splitData);
        ABB nuevaCoor = new(struct mgCoordenada);
        nuevaCoor->capBelica    = stoi(splitData[0]); 
        nuevaCoor->geolocalizacion    = mgTrim(splitData[1]);
        nuevaCoor->detArsenal     = mgTrim(splitData[2]);
        nuevaCoor->izq = NULL;
        nuevaCoor->der = NULL;
        return nuevaCoor;
    }
    catch(const exception& e)
    {
        setTextColor(textColorRed);
        cout << ">> Error: "<< data << " -> " << e.what() << endl;
        setTextColor(textColorGreen);
    }
    return NULL;
}

void Loading(string str)
{ 
    string c= " \\|/-"; 
    for(int i=0; i<= 100; i++)
    {   
        cout<< "\r " << c[i % 4] << " " << i << "%   ";
        usleep(5000);
    }
    cout << str  << endl;
}

void insertar(ABB &arbol, ABB coord) 
{
    if(arbol==NULL)
    {
        arbol = coord; 
        arbolNroNodos++;
        arbolCapBelica += coord->capBelica;
        arbolSecCarga  += to_string(coord->capBelica) + " ";
    }
    else if(coord->capBelica < arbol->capBelica)
        insertar(arbol->izq, coord);
    else if(coord->capBelica > arbol->capBelica)
        insertar(arbol->der, coord);
}

void getCoordenadas() 
{
    string str;
    fstream f;
    cout << "[+]Leyendo coordenadas ... " << endl;
    f.open("../coordenadas.txt", ios_base::in); 
    if ( f.is_open() ) 
        while( !f.eof() )
        {
            getline( f, str );
            ABB coord  = crearNodo(str);
            if(coord != NULL)
            {
                    insertar(arbol , coord);
                    Loading(str);
            }
        }
    else
        cout << "Error de abrir el archivo de coordenadas" << endl;
    f.close();
}

int main(void)
{
    setTextColor(textColorGreen);
    getCoordenadas();
    
    setTextColor(textColorCyan);
    cout << endl << "\n\n[+]Informacion Arbol Binario de capacidad belica Ucrania";
    cout << endl << "   Developer-Nombre : "  << MGNOMBRE
        << endl << "   Developer-Cedula : "  << MGCEDULA
        << endl << "   Capacidad Belica : "  << arbolCapBelica
        << endl << "   Coordenada-Total : "  << arbolNroNodos
        << endl << "   Coordenada-SecCarga: " << arbolSecCarga;
}