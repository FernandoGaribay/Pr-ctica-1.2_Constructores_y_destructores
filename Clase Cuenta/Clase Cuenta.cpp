#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

class Cuenta {
private:
    int numeroCuenta;
    char* nombreTitular;
    double saldo;

public:
    Cuenta();
    Cuenta(int, char const*, double);
    Cuenta(const Cuenta&);
    ~Cuenta();

    void setNumeroCuenta(int);
    void setNombreTitular(char const*);

    int getNumeroCuenta();
    char* getNombreTitular();
    double getSaldo();

    void depositar(double);
    void retirar(double);
    void verDatosCuenta();
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
}

// Destructor
Cuenta::~Cuenta() {
    delete[] nombreTitular;
}

void Cuenta::setNumeroCuenta(int numeroCuenta) {
    this->numeroCuenta = numeroCuenta;
}

void Cuenta::setNombreTitular(char const* nombreTitular) {
    strcpy(this->nombreTitular, nombreTitular);
}


int Cuenta::getNumeroCuenta() {
    return numeroCuenta;
}

char* Cuenta::getNombreTitular() {
    return nombreTitular;
}
double Cuenta::getSaldo() {
    return saldo;
}


void Cuenta::depositar(double cantidad) {
    this->saldo += cantidad;
}

void Cuenta::retirar(double cantidad) {
    if (saldo > cantidad)
        this->saldo -= cantidad;
}

void Cuenta::verDatosCuenta() {
    cout << getNumeroCuenta() << endl << getNombreTitular() << endl << getSaldo() << endl;
}

int main()
{
    Cuenta cuenta1;
    Cuenta cuenta2(2, "Fernando", 1000);
    Cuenta cuenta3 = cuenta2;

    cuenta1.verDatosCuenta();
    cuenta2.verDatosCuenta();
    cuenta2.verDatosCuenta();


    system("pause");
}