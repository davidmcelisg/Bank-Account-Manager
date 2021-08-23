#include <iostream>
using namespace std;
#include "Chequera.h"

int main () {
  //Main Actividad 6

  CtaBanc *arrDatos[19];
  //Creación de objetos aleatorios para arreglo (fines estéticos)
  arrDatos[0]=new CtaBanc(111,500);
  arrDatos[1]=new CtaBanc(222,100);
  arrDatos[2]=new CtaBanc(333,150);
  arrDatos[3]=new Chequera(121,350,7.5);



  int opcion = 1;
  int obj = 3;
  int numCta = 1;
  bool encuentra = false;


  while (opcion != 5) {
    cout << endl << "Menu" << endl << "1. Alta de Cuenta" << endl << "2. Depositar en Cuenta" << endl << "3. Retirar de Cuenta" << endl << "4. Desplegar todas las Cuentas" << endl << "5. Salir" << endl;
    cout << "Entrega un número del 1 al 5: ";
    cin >> opcion;

    if (opcion == 1) {
      if (obj < 19) {
      cout << "Ingrese 1 para abrir nueva Cuenta Bancaria" << endl << "Ingrese 2 para abrir nueva Chequera" << endl;
      int tipo;
      cin >> tipo;
      do {
        cout << "Ingrese el número de Cuenta/Chequera que desea: ";
        cin >> numCta;
        for (int z = 0; z < obj; z++) {
          encuentra = false;
          if (arrDatos[z]->getNumCuenta() == numCta) {
            encuentra = true;
            cout << "Error. Ese número de cuenta ya existe" << endl;
          }
        }
      } while (encuentra == true);
      obj++;
      if (tipo == 1) {
        cout << endl << "Alta Cuenta: " << endl;
        arrDatos[obj]=new CtaBanc(numCta,0);
        cout << "Cuenta dada de alta de manera exitosa!";
      }
      else if (tipo == 2) {
        cout << endl << "Alta Chequera: " << endl;
        cout << "Ingrese el número de comisión que desea: ";
        double numComision;
        cin >> numComision;
        arrDatos[obj]=new Chequera(numCta,0,numComision);
        cout << "Chequera dada de alta de manera exitosa!";
      }
      else {
        cout << "Error. Ingrese 1 para Cuenta o 2 para Chequera";
      }
      } else {
        cout << "Ya se dió de alta el número maximo de cuentas" << endl;
      }
    } 
    else if (opcion == 2) {
      cout << "Ingrese el número en el arreglo de cuenta que desea: ";
      int ii;
      cin >> ii;
      if (ii < 0 || ii > 19) {
        cout << "La cuenta es inexistente" << endl;
      }
      else {
        cout << "Ingrese la cantidad a depositar: ";
        double cantidad;
        cin >> cantidad;
        arrDatos[ii]->deposita(cantidad);
      }
    }
    else if (opcion == 3) {
      cout << "Ingrese el número en el arreglo de cuenta que desea: ";
      int jj;
      cin >> jj;
      if (jj < 0 || jj > 19) {
        cout << "La cuenta es inexistente" << endl;
      }
      else {
        cout << "Ingrese la cantidad a retirar: ";
        double cantRetiro;
        cin >> cantRetiro;
        arrDatos[jj]->retira(cantRetiro);
      }
    }
    else if (opcion == 4) {
      for (int i = 0; i<obj ;i++) {
      arrDatos[i]->mostrar();
      //cout << "endl";
      }
    }
    else if (opcion == 5) {
      exit(0);
    }
    else {
      cout << endl << endl << "Menu" << endl << "1. Alta de Cuenta" << endl << "2. Depositar en Cuenta" << endl << "3. Retirar de Cuenta" << endl << "4. Desplegar todas las Cuentas" << endl << "5. Salir" << endl;
      cout << "Entrega un número del 1 al 5: ";
      cin >> opcion;
    }
  }
}

/*
    //Main Actividad 3
    Chequera ch;
    CtaBanc cb;
    int numCta;
    double saldo, com;
    cout << "Teclea el numero de cuenta de la cuenta bancaria ";
    cin >> numCta;
    cb.setNumCuenta(numCta);
    cout << "Teclea el saldo inicial para el cliente de la cuenta bancaria ";
    cin >> saldo;
    cb.setSaldo(saldo);
    cout << "Teclea el numero de cuenta de la chequera ";
    cin >> numCta;
    ch.setNumCuenta(numCta);
    cout << "Teclea el saldo inicial para el cliente de la chequera";
    cin >> saldo;
    ch.setSaldo(saldo);
    cout << "Teclea  la comision por retiro de la chequera ";
    cin >> com;
    ch.setComision(com);
    cout << "Los datos de la cuenta bancaria son " << endl;
    cb.mostrar();
    cout << "Los datos de la cuenta de cheques son " << endl;
    ch.mostrar();
    cb.retira(100);
    ch.retira(100);
    cout << "despues de retirar datos de cuenta bancaria " << endl;
    cb.mostrar();
    cout << "despues de retirar datos de chequera " << endl;
    ch.mostrar();
    */