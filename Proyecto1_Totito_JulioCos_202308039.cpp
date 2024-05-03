// nombre: Julio Carlos Cos García
// Carnet: 202308039
#include <iostream>
#include <string>
using namespace std;

string tablero[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
int Tablero();
int Modo_PvP();
int Modo_PvC();
int Actualizar_Tablero(int posicion, string signo);

int main() {
    int op;
    cout<<"       Juego de totito     "<<endl;
    cout<<"1. Modo PVP "<<endl;
    cout<<"2. Modo PVC "<<endl;
    cout<<"Ingrese la opcion deseada: ";
    cin>>op;
    cout<<endl;
    switch (op)
    {
    case 1:
        cout<<"Selecciono la opcion 1: Modo PVP" << endl;
        Modo_PvP();
        break;
    case 2:
        cout<<"Selecciono la opcion 2: Modo PVC"<<endl;
        Modo_PvC();
        break;
    default:
        break;
    }
    return 0;
}

int Modo_PvP(){
    string Jugador1, Jugador2, signo_J1, signo_J2;
    int posicion;
    cout<<"Jugador 1 Ingrese su nombre: ";
    cin>>Jugador1;
    cout<<"Jugador 2 Ingrese su nombre: ";
    cin>>Jugador2;
    cout<<Jugador1<<", elija con que simbolo quiere Jugar (X o O):";
    cin>>signo_J1;
    if(signo_J1 == "X"){
        cout<<"El jugador 1 eligio la X, entonces al jugador 2 le toca la O";      
        signo_J2 = "O";  // Usa el operador de asignación '=' aquí
    }else{
        cout<<"El jugador 1 eligio la O, entonces al jugador 2 le toca la X";      
        signo_J2 = "X";  // Usa el operador de asignación '=' aquí
    }
    cout<<endl;
    Tablero();
    for(int i=1; i<=9; i++){
        if(i % 2 != 0) {
            cout<<"Jugador:"<<Jugador1<<", ingrese la posición deseada: ";
            cin>>posicion;
            Actualizar_Tablero(posicion, signo_J1);
        } else {
            cout<<"Jugador:"<<Jugador2<<", ingrese la posición deseada: ";
            cin>>posicion;
            Actualizar_Tablero(posicion, signo_J2);
        }
    }
}
int Modo_PvC(){
    string Jugados1,computadora,ganador,perdedor;
    cout<<"Jugador 1 Ingrese su nombre: ";
    cin>>Jugados1;
    Tablero();
}
int Tablero(){
    int count = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << count;
            if (j != 2) {
                cout << "|";
            }
            count++;
        }
        cout << endl;
        if (i != 2) {
            cout << "-----" << endl;
        }
    }
    cout<<endl;
}
int Actualizar_Tablero(int posicion, string signo) {
    int count = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(count == posicion) {
                tablero[i][j] = signo;
            }
            count++;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << tablero[i][j];
            if (j != 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i != 2) {
            cout << "-----" << endl;
        }
    }
    cout<<endl;
}