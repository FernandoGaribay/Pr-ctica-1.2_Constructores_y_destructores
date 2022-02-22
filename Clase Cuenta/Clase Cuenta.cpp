#include <iostream>
#include <cstring>
#pragma warning(disable : 4996) // Desabilita las warning's de metodos como strcpy_s

using namespace std;

class Cuenta { // Clase Cuenta
private:
    int numeroCuenta; // Atributo: Numero de cuenta
    char* nombreTitular; // Atributo: Nombre del titular
    double saldo; // Atributo: Saldo

public:
    Cuenta();
    Cuenta(int, char const*, double);
    Cuenta(const Cuenta&);
    ~Cuenta();

    void setNumeroCuenta(int); // Set: Numero de cuenta
    void setNombreTitular(char const*); // Set: Nombre del titular
    void setSaldo(double); // Set: Saldo

    int getNumeroCuenta(); // Get: Numero de cuenta
    char* getNombreTitular(); // Get: Nombre del titular
    double getSaldo(); // Get: Saldo

    void depositar(double);
    void retirar(double);
    void mostrarCuenta(); // Metodo: Mostrar cuenta
};

// Constructor por defecto
Cuenta::Cuenta() {
    setNumeroCuenta(1);
    nombreTitular = new char[20];
    setNombreTitular(" ");
    saldo = 0;
}

// Constructor parametrizado
Cuenta::Cuenta(int numeroCuenta, char const* nombreTitular, double saldo) {
    this->nombreTitular = new char[strlen(nombreTitular) + 1];
    setNumeroCuenta(numeroCuenta);
    setNombreTitular(nombreTitular);
    this->saldo = saldo;
}

// Constructor copia
Cuenta::Cuenta(const Cuenta& p) {
    this->nombreTitular = new char[strlen(p.nombreTitular) + 1];
    setNumeroCuenta(p.numeroCuenta);
    setNombreTitular(p.nombreTitular);
    setSaldo(p.saldo);
}

// Destructor
Cuenta::~Cuenta() {
    delete[] nombreTitular;
}

void Cuenta::setNumeroCuenta(int numeroCuenta) { // Set: Numero de cuenta
    this->numeroCuenta = numeroCuenta;
}

void Cuenta::setNombreTitular(char const* nombreTitular) { // Set: Nombre del titular
    strcpy(this->nombreTitular, nombreTitular);
}

void Cuenta::setSaldo(double saldo) { // Set: Saldo
    this->saldo = saldo;
}


int Cuenta::getNumeroCuenta() { // Get: Numero de cuenta
    return numeroCuenta;
}

char* Cuenta::getNombreTitular() { // Get: Nombre del titular
    return nombreTitular;
}

double Cuenta::getSaldo() { // Get: Saldo
    return saldo;
}


void Cuenta::depositar(double cantidad) {
    this->saldo += cantidad;
}

void Cuenta::retirar(double cantidad) {
    this->saldo -= cantidad;
}

void Cuenta::mostrarCuenta() { // Metodo: Mostrar cuenta
    cout << "\nNumero de cuenta: " << getNumeroCuenta()
        << "\nNombre del titular: " << getNombreTitular() 
        << "\nSaldo: " << getSaldo() 
        << endl;
}

int main()
{
    Cuenta cuenta1; // Objeto de Cuenta1
    Cuenta cuenta2(2, "Fernando", 1000); // Objeto de Cuenta2 (Con los parametros que pide el constructor)
    Cuenta cuenta3 = cuenta2; // Objeto de Cuenta3 (Copia del objeto cuenta2)

    cuenta3.depositar(200); // Se deposita 200$ pesos a la cuenta 3
    cuenta3.retirar(100); // Se retira 100$ pesos en la cuenta 2

    cuenta1.mostrarCuenta(); // Se muestra la informacion del objeto cuenta1
    cuenta2.mostrarCuenta(); // Se muestra la informacion del objeto cuenta2
    cuenta3.mostrarCuenta(); // Se muestra la informacion del objeto cuenta3

    cuenta1.~Cuenta(); // Se destruye el objeto cuenta1
    cuenta2.~Cuenta(); // Se destruye el objeto cuenta2
    cuenta3.~Cuenta(); // Se destruye el objeto cuenta3

    cout << endl;
    system("pause");
}