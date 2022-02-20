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

int main()
{

    system("pause");
}