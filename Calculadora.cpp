#include<iostream>
#include<stdio.h>
using namespace std;

class fraccion{
   
    public:
      
            int numerador;
            int denominador;
    
        void mostrar()
        {
            cout<<numerador<<"/"<<denominador<<endl;
        }
        fraccion suma(fraccion f1, fraccion f2)
        {
            fraccion resultado;
            resultado.numerador=f1.numerador*f2.denominador+f2.numerador*f1.denominador;
            resultado.denominador=f1.denominador*f2.denominador;
            return resultado;
        }
        fraccion resta(fraccion f1, fraccion f2)
        {
            fraccion resultado;
            resultado.numerador=f1.numerador*f2.denominador-f2.numerador*f1.denominador;
            resultado.denominador=f1.denominador*f2.denominador;
            return resultado;
        }
        fraccion multiplicacion(fraccion f1, fraccion f2)
        {
            fraccion resultado;
            resultado.numerador=f1.numerador*f2.numerador;
            resultado.denominador=f1.denominador*f2.denominador;
            return resultado;
        }fraccion division(fraccion f1, fraccion f2)
        {
            fraccion resultado;
            resultado.numerador=f1.numerador*f2.denominador;
            resultado.denominador=f1.denominador*f2.numerador;
            return resultado;
        }
        fraccion simplificar(fraccion f1)
        {
            fraccion resultado;
            int a=f1.numerador;
            int b=f1.denominador;
            while(b!=0)
            {
                int r=a%b;
                a=b;
                b=r;
            }
            resultado.numerador=f1.numerador/a;
            resultado.denominador=f1.denominador/a;
            return resultado;
        }
};
int main()
{fraccion f;
 fraccion f1;
 fraccion f2;
 fraccion resultado;
    int opcion;
    cout<<"*/*/*/*/*/*/*/Calculadora de fracciones*/*/*/*/*/*/*/"<<endl;
    cout<<"Ingrese el numerador de la primera fraccion: ";
    cin>>f1.numerador;
    cout<<"Ingrese el denominador de la primera fraccion: ";
    cin>>f1.denominador;    
    cout<<"Ingrese el numerador de la segunda fraccion: ";  
    cin>>f2.numerador;
    cout<<"Ingrese el denominador de la segunda fraccion: ";
    cin>>f2.denominador;
    cout << "\nSeleccione una operacion:" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch(opcion)
    {
        case 1:
            resultado=f.suma(f1,f2);
            break;
        case 2:
            resultado=f.resta(f1,f2);
            break;
        case 3:
            resultado=f.multiplicacion(f1,f2);
            break;
        case 4:
            resultado=f.division(f1,f2);
            break;
    }
    cout<<"El resultado es: ";
    resultado.simplificar(resultado).mostrar();
}