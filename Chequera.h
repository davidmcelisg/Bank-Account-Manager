#include"CtaBanc.h"

class Chequera : public CtaBanc {
  private:
    double comision;
  public:
    Chequera();
    Chequera(int, double, double);
    double getComision();
    void setComision(double);
    virtual bool retira(double);
    virtual void mostrar();
};

Chequera::Chequera() : CtaBanc() {
  comision = 0;
}
Chequera::Chequera(int nn, double ss, double c) : CtaBanc(nn,ss) {
  comision = c;
}
double Chequera::getComision() {
  return comision;
}
void Chequera::setComision(double c) {
  comision = c;
}
bool Chequera::retira(double cant){
  // cuando atributos son privados
  //if (getSaldo() >= cant + comision){
        //setSaldo(getSaldo()-(cant + comision));
    if (saldo >= cant + comision) {
      saldo -= (cant + comision);
      return true;
    }
else {
  return false;
  }
}
void Chequera::mostrar() {
  //cout << endl <<"Tu cuenta "<<numCuenta<< " tiene un saldo:" <<saldo << "con comision de " << comision << endl;
  CtaBanc::mostrar(); //mandar llamar al mostrar de la clase padre
  cout << "con comision de: " << comision << endl;
}