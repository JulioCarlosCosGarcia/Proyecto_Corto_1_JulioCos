// nombre: Julio Carlos Cos García
// Carnet: 202308039
#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
// colores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

string tablero[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
int Tablero();
int Modo_PvP();
int Modo_PvP_otra_vez(string Jugador1, string Jugador2);
int Modo_PvC();
int Actualizar_Tablero(int posicion, string signo);
string Verificar_Ganador();
void ReiniciarTablero();
int ObtenerMovimientoAleatorio();
bool EsMovimientoValido(int posicion);
int posicion,p_j1,p_j2,p_pc;

int main() {
    int op;
    cout<<YELLOW<<"       Juego de totito     "<<RESET<<endl;
    cout<<YELLOW<<"1. Modo PVP "<<RESET<<endl;
    cout<<YELLOW<<"2. Modo PVC "<<RESET<<endl;
    cout<<GREEN<<"-----------------------------"<<RESET<<endl;
    cout<<WHITE<<"Ingrese la opcion deseada: "<<RESET;
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
    int numero_random = rand() % 2,Volver_a_jugar;

    cout<<CYAN<<"Jugador 1 Ingrese su nombre: "<<RESET;
    cin>>Jugador1;
    cout<<MAGENTA<<"Jugador 2 Ingrese su nombre: "<<RESET;
    cin>>Jugador2;

    if(numero_random==0){
        signo_J1 = "X";  
        signo_J2 = "O";
        cout<<"Al jugador: "<<Jugador1<<" le toco el: "<<signo_J1<<" y al jugador: "<<Jugador2<<" le toco el: "<<signo_J2<<endl; 
    }else{
        signo_J1 = "O";  
        signo_J2 = "X";
         cout<<"Al jugador: "<<Jugador1<<" le toco el: "<<signo_J1<<" y al jugador: "<<Jugador2<<" le toco el: "<<signo_J2<<endl; 
    }

    cout<<endl;
    Tablero();
    for(int i=1; i<=9; i++){
        if(i % 2 != 0) {
            cout<<CYAN<<"Jugador: "<<Jugador1<<", ingrese la posicion deseada: "<< RESET;
            cin>>posicion;
            Actualizar_Tablero(posicion, signo_J1);
        } else {
            cout <<MAGENTA <<"Jugador: "<<Jugador2<<", ingrese la posicion deseada: "<< RESET;
            cin>>posicion;
            Actualizar_Tablero(posicion, signo_J2);
        }
        string ganador = Verificar_Ganador();
        if(ganador == signo_J1) {
            p_j1 += 1;
            cout <<"Puntaje Jugador "<<Jugador1<<"es de: "<<p_j1<<endl;
            cout <<"Puntaje Jugador "<<Jugador2<<"es de: "<<p_j2<<endl;
            cout<<CYAN<<"Jugador:"<<Jugador1<<" Gano con"<<RESET;
        }else if(ganador == signo_J2) {
            p_j2 += 1;
            cout <<"Puntaje Jugador "<<Jugador1<<"es de: "<<p_j1<<endl;
            cout <<"Puntaje Jugador "<<Jugador2<<"es de: "<<p_j2<<endl;
            cout<<MAGENTA<<"Jugador:"<<Jugador2<<" Gano con"<<RESET;
        }
        if(ganador != "") {
            cout << "el simbolo: " << ganador << endl;
            cout << "Desean Jugar de nuevo ? (1 es Si y 2 es no)"<<endl;
            cout << "Ingrese la opcion deceada: ";
            cin>>Volver_a_jugar;
            cout <<endl;
            if (Volver_a_jugar==1){
                Modo_PvP_otra_vez( Jugador1, Jugador2);
            }else if (Volver_a_jugar==2){
                cout << "Gracias por Jugar";
            }
        }
    }
}
int Modo_PvP_otra_vez(string Jugador1, string Jugador2) {
    string signo_J1, signo_J2;
    int  Volver_a_jugar;

    ReiniciarTablero(); // Limpia el tablero antes de comenzar un nuevo juego

    cout << Jugador1 << ", elija con qué simbolo quiere jugar (X o O): ";
    cin >> signo_J1;

    if (signo_J1 == "X") {
        cout << "El jugador 1 eligio la X, entonces al jugador 2 le toca la O" << endl;
        signo_J2 = "O";
    } else {
        cout << "El jugador 1 eligio la O, entonces al jugador 2 le toca la X" << endl;
        signo_J2 = "X";
    }
    cout << endl;
  
    Tablero();
    for (int i = 1; i <= 9; i++) {
        if (i % 2 != 0) {
            cout << "Jugador:" << Jugador1 << ", ingrese la posicion deseada: ";
            cin >> posicion;
            Actualizar_Tablero(posicion, signo_J1);
        } else {
            cout << "Jugador:" << Jugador2 << ", ingrese la posicion deseada: ";
            cin >> posicion;
            Actualizar_Tablero(posicion, signo_J2);
        }
        string ganador = Verificar_Ganador();
        if(ganador == signo_J1) {
            p_j1 += 1;
            cout <<"Puntaje Jugador "<<Jugador1<<"es de: "<<p_j1<<endl;
            cout <<"Puntaje Jugador "<<Jugador2<<"es de: "<<p_j2<<endl;
            cout<<CYAN<<"Jugador:"<<Jugador1<<" Gano con"<<RESET;
        }else if(ganador == signo_J2) {
            p_j2 += 1;
            cout <<"Puntaje Jugador "<<Jugador1<<"es de: "<<p_j1<<endl;
            cout <<"Puntaje Jugador "<<Jugador2<<"es de: "<<p_j2<<endl;
            cout<<MAGENTA<<"Jugador:"<<Jugador2<<" Gano con"<<RESET;
            
        }
        if(ganador != "") {
            cout << "el simbolo: " << ganador << endl;
            cout << "Desean Jugar de nuevo ? (1 es Si y 2 es no)"<<endl;
            cout << "Ingrese la opcion deceada: ";
            cin>>Volver_a_jugar;
            cout <<endl;
            if (Volver_a_jugar==1){
                Modo_PvP_otra_vez( Jugador1, Jugador2);
            }else if (Volver_a_jugar==2){
                cout << "Gracias por Jugar";
            }
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------
int Modo_PvC(){
    string Jugador1, JugadorPC, signo_J1, signo_PC;
    int numero_random = rand() % 2,posicion,Volver_a_jugar,Posicion_PC = rand() % 9 + 1;
    cout<<"Jugador 1 Ingrese su nombre: ";
    cin>>Jugador1;
    cout<<endl;
    Tablero();
    if(numero_random==0){
        signo_J1 = "X";  
        signo_PC = "O";
        cout<<"Al jugador: "<<Jugador1<<" le toco el: "<<signo_J1<<" y al PC le toco el: "<<signo_PC<<endl; 
    }else{
        signo_J1 = "O";  
        signo_PC = "X";
        cout<<"Al jugador: "<<Jugador1<<" le toco el: "<<signo_J1<<" y al PC le toco el: "<<signo_PC<<endl; 
    }


    for(int i=1; i<=9; i++){
        if(i % 2 != 0) {
            cout<<CYAN<<"Jugador:"<<Jugador1<<", ingrese la posicion deseada: "<< RESET;
            cin>>posicion;
            Actualizar_Tablero(posicion, signo_J1);
        } else {
            posicion = ObtenerMovimientoAleatorio();
            cout << "La computadora eligió la posición: " << posicion << endl;
            Actualizar_Tablero(posicion, signo_PC);
        }
        string ganador = Verificar_Ganador();
        if(ganador == signo_J1) {
            p_j1 += 1;
            cout <<"Puntaje Jugador "<<Jugador1<<"es de: "<<p_j1<<endl;
            cout <<"Puntaje Jugador "<<JugadorPC<<"es de: "<<p_pc<<endl;
            cout<<CYAN<<"Jugador:"<<Jugador1<<" Gano con "<<RESET;
        }else if(ganador == signo_PC) {
            p_pc += 1;
            cout <<"Puntaje Jugador"<<Jugador1<<"es de: "<<p_j1<<endl;
            cout <<"Puntaje Jugador"<<JugadorPC<<"es de: "<<p_pc<<endl;
            cout<<MAGENTA<<"La PC Gano con "<<RESET;
        }
        if(ganador != "") {
            cout << " el digno " << ganador << endl;
            cout << "Desean Jugar de nuevo ? (1 = Si y 2 = no)"<<endl;
            cout << "Ingrese la opcion deceada: ";
            cin>>Volver_a_jugar;
            cout <<endl;
            if (Volver_a_jugar==1){
                Modo_PvP_otra_vez( Jugador1, signo_PC);
                posicion=0;
            }else if (Volver_a_jugar==2){
                cout << "Gracias por Jugar";
            }
        }
    }
}
bool EsMovimientoValido(int posicion) {
    if (posicion < 1 || posicion > 9) {
        return false;
    }
    // Calcula la fila y columna correspondientes a la posición en el tablero
    int fila = (posicion - 1) / 3;
    int columna = (posicion - 1) % 3;
    // Verifica si la casilla correspondiente está vacía
    return (tablero[fila][columna] != "X" && tablero[fila][columna] != "O");
}

int ObtenerMovimientoAleatorio() {
    int movimiento;
    do {
        movimiento = rand() % 9 + 1; // Genera un número aleatorio entre 1 y 9
    } while (!EsMovimientoValido(movimiento)); // Verifica si el movimiento es válido
    return movimiento;
}
//------------------------------------------------------------------------------------------------------------------
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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (count == posicion) {
                if (tablero[i][j] == "X" || tablero[i][j] == "O") {
                    cout << "La posicion ya esta ocupada. Elija otra." << endl;
                    return -1;
                }
                tablero[i][j] = signo;
            }
            count++;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (tablero[i][j] == "X") {
                cout << GREEN << tablero[i][j] << RESET;
            } else if (tablero[i][j] == "O") {
                cout << YELLOW << tablero[i][j] << RESET;
            } else {
                cout << tablero[i][j];
            }
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

string Verificar_Ganador() {
    // Verificar filas
    for(int i = 0; i < 3; i++) {
        if(tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return tablero[i][0];
        }
    }

    // Verificar columnas
    for(int i = 0; i < 3; i++) {
        if(tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            return tablero[0][i];
        }
    }

    // Verificar diagonales
    if(tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return tablero[0][0];
    }
    if(tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        return tablero[0][2];
    }

    // Verificar empate
    bool empate = true;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (tablero[i][j] != "X" && tablero[i][j] != "O") {
                empate = false;
                break;
            }
        }
        if (!empate) {
            break;
        }
    }
    if (empate) {
        return "Empate";
    }
    posicion = 0;
}

void ReiniciarTablero() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = to_string(i * 3 + j + 1);
        }
    }
}
