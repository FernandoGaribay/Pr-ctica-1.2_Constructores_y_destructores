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

int main()
{

    system("pause");
}