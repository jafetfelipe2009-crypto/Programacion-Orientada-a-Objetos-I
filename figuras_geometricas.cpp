#include<iostream>
#include<cmath>
using namespace std;

class cuadrado{
        
    public:
    int lado;
        void ingresarValores() {
        cout << "Ingrese el lado del cuadrado: ";
        cin >> lado;
        cout << "¡Valores guardados correctamente!\n";
     }

        
        void area(int lado){
            cout<<"El area del cuadrado es: "<<lado*lado<<endl;
        }
        void perimetro(){
            cout<<"El perimetro del cuadrado es: "<<4*lado<<endl;
        }
        void dibujar(int lado){
            for(int i=0;i<lado;i++)
            {
                for(int j=0;j<lado;j++)
                {
                    cout<<"* ";
                }
                cout<<endl;
            }
        }
};
class rectangulo{
    public:
    int base, altura;
       void ingresarValores() {
        cout << "Ingrese la base del rectángulo: ";
        cin >> base;
        cout << "Ingrese la altura del rectángulo: ";
        cin >> altura;
       }    
        void area(){
            cout<<"El area del rectangulo es: "<<base*altura<<endl;
        }
        void perimetro(){
            cout<<"El perimetro del rectangulo es: "<<2*(base+altura)<<endl;
        }
        void dibujar(){
            for(int i=0;i<altura;i++)
            {
                for(int j=0;j<base;j++)
                {
                    cout<<"* ";
                }
                cout<<endl;
            }
        }
};
class triangulo{
    public:
    int base, altura;
        void ingresarValores() {
        cout << "Ingrese la base del triángulo: ";
        cin >> base;
        cout << "Ingrese la altura del triángulo: ";
        cin >> altura;
        }   
        void area(){
            cout<<"El area del triangulo es: "<<(base*altura)/2<<endl;
        }
        void perimetro(){
            cout<<"El perimetro del triangulo es: "<<base+altura+(sqrt(base*base+altura*altura))<<endl;
        }
        void dibujar(){
            for(int i=0;i<altura;i++)
            {
                for(int j=0;j<base;j++)
                {
                    if(j<=i)
                        cout<<"* ";
                    else
                        cout<<"  ";
                }
                cout<<endl;
            }
        }
};
class circulo{
    public:
    int radio;
        void ingresarValores() {
        cout << "Ingrese el radio del círculo: ";
        cin >> radio;
        }    
        void area(){
            cout<<"El area del circulo es: "<<3.1416*radio*radio<<endl;
        }
        void perimetro(){
            cout<<"El perimetro del circulo es: "<<2*3.1416*radio<<endl;
        }
        void dibujar(){
            for(int i=0;i<2*radio;i++)
            {
                for(int j=0;j<2*radio;j++)
                {
                    if((i-radio)*(i-radio)+(j-radio)*(j-radio)<=radio*radio)
                        cout<<"* ";
                    else
                        cout<<"  ";
                }
                cout<<endl;
            }
        }
};
class rombo{
    public:
    int diagonal_mayor, diagonal_menor;
        void ingresarValores() {
        cout << "Ingrese la diagonal mayor del rombo: ";
        cin >> diagonal_mayor;
        cout << "Ingrese la diagonal menor del rombo: ";
        cin >> diagonal_menor;
        }   
        void area(){
            cout<<"El area del rombo es: "<<(diagonal_mayor*diagonal_menor)/2<<endl;
        }
        void perimetro(){
            cout<<"El perimetro del rombo es: "<<2*sqrt((diagonal_mayor/2)*(diagonal_mayor/2)+(diagonal_menor/2)*(diagonal_menor/2))<<endl;
        }
        void dibujar()
        {
            for(int i=0;i<diagonal_mayor;i++)
            {
                for(int j=0;j<diagonal_mayor;j++)
                {
                    if(abs(i-diagonal_mayor/2)+abs(j-diagonal_mayor/2)<=diagonal_menor/2)
                        cout<<"* ";
                    else
                        cout<<"  ";
                }
            }
        }   
};
class trapecio{
    public:
    int base_mayor, base_menor, altura;
        void ingresarValores() {
        cout << "Ingrese la base mayor del trapecio: ";
        cin >> base_mayor;
        cout << "Ingrese la base menor del trapecio: ";
        cin >> base_menor;
        cout << "Ingrese la altura del trapecio: ";
        cin >> altura;
        }
        void area(){
            cout<<"El area del trapecio es: "<<(base_mayor+base_menor)*altura/2<<endl;
        }
        void perimetro(){
            cout<<"El perimetro del trapecio es: "<<base_mayor+base_menor+2*sqrt(((base_mayor-base_menor)/2)*((base_mayor-base_menor)/2)+altura*altura)<<endl;
        }
        void dibujar(){
            for(int i=0;i<altura;i++)
            {
                for(int j=0;j<base_mayor;j++)
                {
                    if(j>= (base_mayor-base_menor)/2 && j<(base_mayor-base_menor)/2+base_menor)
                        cout<<"* ";
                    else
                        cout<<"  ";
                }
                cout<<endl;
            }
        }
};
class pentagono{
    public:
    int lado;
        void ingresarValores() {
        cout << "Ingrese el lado del pentagono: ";
        cin >> lado;
        }
        void area(){
            cout<<"El area del pentagono es: "<<(5*lado*lado)/(4*tan(3.1416/5))<<endl;
        }
        void perimetro(){
            cout<<"El perimetro del pentagono es: "<<5*lado<<endl;
        }
        void dibujar(){
            for(int i=0;i<lado;i++)
            {
                for(int j=0;j<lado;j++)
                {
                    if(i+j>=lado-1 && j-i<=lado-1)
                        cout<<"* ";
                    else
                        cout<<"  ";
                }
                cout<<endl;
            }
        }
};
class hexagono{
    public:
    int lado;
        
        void ingresarValores() {
        cout << "Ingrese el lado del hexagono: ";
        cin >> lado;
        }
        void area(){
            cout<<"El area del hexagono es: "<<(3*sqrt(3)*lado*lado)/2<<endl;
        }
        void perimetro(){
            cout<<"El perimetro del hexagono es: "<<6*lado<<endl;
        }
        void dibujar(){
            for(int i=0;i<lado;i++)
            {
                for(int j=0;j<2*lado;j++)
                {
                    if(abs(i-lado/2)+abs(j-lado)<=lado/2)
                        cout<<"* ";
                    else
                        cout<<"  ";
                }
                cout<<endl;
            }
        }
};
class octagono{
    public:
    int lado;
        void ingresarValores() {
        cout << "Ingrese el lado del octagono: ";
        cin >> lado;
        }
        void area(){
            cout<<"El area del octagono es: "<<2*(1+sqrt(2))*lado*lado<<endl;
        }
        void perimetro(){
            cout<<"El perimetro del octagono es: "<<8*lado<<endl;
        }
        void dibujar(){
            for(int i=0;i<lado;i++)
            {
                for(int j=0;j<2*lado;j++)
                {
                    if(abs(i-lado/2)+abs(j-lado)<=lado/2)
                        cout<<"* ";
                    else
                        cout<<"  ";
                }
                cout<<endl;
            }
        }
};
class estrella{
    public:
    int lado;
        void ingresarValores() {
        cout << "Ingrese el lado de la estrella: ";
        cin >> lado;
        }
        void area(){
            cout<<"El area de la estrella es: "<<(5*lado*lado)/(4*tan(3.1416/5))<<endl;
        }
        void perimetro(){
            cout<<"El perimetro de la estrella es: "<<10*lado<<endl;
        }
        void dibujar(){
            for(int i=0;i<lado;i++)
            {
                for(int j=0;j<2*lado;j++)
                {
                    if(abs(i-lado/2)+abs(j-lado)<=lado/2)
                        cout<<"* ";
                    else
                        cout<<"  ";
                }
                cout<<endl;
            }
        }
};
class cubo {
    public:
    int lado;
        void ingresarValores() {
        cout << "Ingrese el lado del cubo: ";
        cin >> lado;
        }
        void area(){
            cout<<"El area del cubo es: "<<6*lado*lado<<endl;
        }
        void volumen(){
            cout<<"El volumen del cubo es: "<<lado*lado*lado<<endl;
        }
};
class esfera {
    public:
    int radio;
        void ingresarValores() {
        cout << "Ingrese el radio de la esfera: ";
        cin >> radio;
        }
        void area(){
            cout<<"El area de la esfera es: "<<4*3.1416*radio*radio<<endl;
        }
        void volumen(){
            cout<<"El volumen de la esfera es: "<<(4/3)*3.1416*radio*radio*radio<<endl;
        }
};
class cilindro {
    public:
    int radio, altura;
        void ingresarValores() {
        cout << "Ingrese el radio del cilindro: ";
        cin >> radio;
        cout << "Ingrese la altura del cilindro: ";
        cin >> altura;
        }
        void area(){
            cout<<"El area del cilindro es: "<<2*3.1416*radio*(radio+altura)<<endl;
        }
        void volumen(){
            cout<<"El volumen del cilindro es: "<<3.1416*radio*radio*altura<<endl;
        }
};
class piramide {
    public:
    int base, altura;
        void ingresarValores() {
        cout << "Ingrese la base de la piramide: ";
        cin >> base;
        cout << "Ingrese la altura de la piramide: ";
        cin >> altura;
        }
        void area(){
            cout<<"El area de la piramide es: "<<base*base+2*base*sqrt((base/2)*(base/2)+altura*altura)<<endl;
        }
        void volumen(){
            cout<<"El volumen de la piramide es: "<<(1/3)*base*base*altura<<endl;
        }
};
class cono {
    public:
    int radio, altura;
        void ingresarValores() {
        cout << "Ingrese el radio del cono: ";
        cin >> radio;
        cout << "Ingrese la altura del cono: ";
        cin >> altura;
        }
        void area(){
            cout<<"El area del cono es: "<<3.1416*radio*(radio+sqrt(radio*radio+altura*altura))<<endl;
        }
        void volumen(){
            cout<<"El volumen del cono es: "<<(1/3)*3.1416*radio*radio*altura<<endl;
        }
};

int main()
{
    int opcion;
    
cout<<"Que tipo de figuras deseas calcular: "<<endl;
cout<<"1. figuras 2D"<<endl;
cout<<"2. figuras 3D"<<endl;

cin>>opcion;
switch(opcion)
{
    case 1:
        cout<<"Que figura deseas calcular: "<<endl;
        cout<<"1. cuadrado"<<endl;
        cout<<"2. rectangulo"<<endl;
        cout<<"3. triangulo"<<endl;
        cout<<"4. circulo"<<endl;
        cout<<"5. estrella"<<endl;
        cout<<"6. rombo"<<endl;
        cout<<"7. trapecio"<<endl;
        cout<<"8. pentagono"<<endl;
        cout<<"9. hexagono"<<endl;
        cout<<"10. octagono"<<endl;
        cin>>opcion;
        switch (opcion)
        {
            case 1:
                cuadrado c;
                int alternativa;
               do
               {
                cout<<"--- FIGURA: CUADRADO ---\n";
                    cout<<"1. Ingresar / Modificar valores\n";
                    cout<<"2. Calcular área\n";
                    cout<<"3. Calcular perímetro\n";
                    cout<<"4. Dibujar figura\n";
                    cout<<"5. Regresar al menú principal\n";
                    cin>>alternativa;
                 switch (alternativa)
                 {
                    case 1:
                        c.ingresarValores();
                        break;
                    case 2:
                        c.area(c.lado);
                        break;
                    case 3:
                        c.perimetro();
                        break;
                    case 4:
                        c.dibujar(c.lado);
                        break;
                    case 5:
                        cout << "Regresando al menú principal...\n";
                    break;
                  }
                  
                }while(opcion!=5);
               
                break;
            case 2:
                rectangulo r;
                int alternativa2;
                do
                {
                    cout<<"--- FIGURA: RECTANGULO ---\n";
                    cout<<"1. Ingresar / Modificar valores\n";
                    cout<<"2. Calcular área\n";
                    cout<<"3. Calcular perímetro\n";
                    cout<<"4. Dibujar figura\n";
                    cout<<"5. Regresar al menú principal\n";
                    cin>>alternativa2;
                 switch (alternativa2)
                 {
                    case 1:
                        r.ingresarValores();
                        break;
                    case 2:
                        r.area();
                        break;
                    case 3:
                        r.perimetro();
                        break;
                    case 4:
                        r.dibujar();
                        break;
                    case 5:
                        cout << "Regresando al menú principal...\n";
                    break;
                  }
                }while(alternativa2!=5);
                break;
            case 3:
                triangulo t;
                int alternativa3;
                do
                {
                    cout<<"--- FIGURA: TRIANGULO ---\n";
                    cout<<"1. Ingresar / Modificar valores\n";
                    cout<<"2. Calcular área\n";
                    cout<<"3. Calcular perímetro\n";
                    cout<<"4. Dibujar figura\n";
                    cout<<"5. Regresar al menú principal\n";
                    cin>>alternativa3;
                 switch (alternativa3)
                 {
                    case 1:
                        t.ingresarValores();
                        break;
                    case 2:
                        t.area();
                        break;
                    case 3:
                        t.perimetro();
                        break;
                    case 4:
                        t.dibujar();
                        break;
                    case 5:
                        cout << "Regresando al menú principal...\n";
                    break;
                  }
                }while(alternativa3!=5);
                break;
            case 4:
                circulo ci;
                int alternativa4;
                do
                {
                    cout<<"--- FIGURA: CIRCULO ---\n";
                    cout<<"1. Ingresar / Modificar valores\n";
                    cout<<"2. Calcular área\n";
                    cout<<"3. Calcular perímetro\n";
                    cout<<"4. Dibujar figura\n";
                    cout<<"5. Regresar al menú principal\n";
                    cin>>alternativa4;
                 switch (alternativa4)
                 {
                    case 1:
                        ci.ingresarValores();
                        break;
                    case 2:
                        ci.area();
                        break;
                    case 3:
                        ci.perimetro();
                        break;
                    case 4:
                        ci.dibujar();
                        break;
                    case 5:
                        cout << "Regresando al menú principal...\n";
                    break;
                  }
                }while(alternativa4!=5);
                break;
            case 5:
                estrella e;
                int alternativa5;
                do
                {
                    cout<<"--- FIGURA: ESTRELLA ---\n";
                    cout<<"1. Ingresar / Modificar valores\n";
                    cout<<"2. Calcular área\n";
                    cout<<"3. Calcular perímetro\n";
                    cout<<"4. Dibujar figura\n";
                    cout<<"5. Regresar al menú principal\n";
                    cin>>alternativa5;
                 switch (alternativa5)
                 {
                    case 1:
                        e.ingresarValores();
                        break;
                    case 2:
                        e.area();
                        break;
                    case 3:
                        e.perimetro();
                        break;
                    case 4:
                        e.dibujar();
                        break;
                    case 5:
                        cout << "Regresando al menú principal...\n";
                    break;
                  }
                }while(alternativa5!=5);
                break;
            case 6:
                rombo ro;
              int alternativa6;
                do
                {
                    cout<<"--- FIGURA: ROMBO ---\n";
                    cout<<"1. Ingresar / Modificar valores\n";
                    cout<<"2. Calcular área\n";
                    cout<<"3. Calcular perímetro\n";
                    cout<<"4. Dibujar figura\n";
                    cout<<"5. Regresar al menú principal\n";
                    cin>>alternativa6;
                 switch (alternativa6)
                 {
                    case 1:
                        ro.ingresarValores();
                        break;
                    case 2:
                        ro.area();
                        break;
                    case 3:
                        ro.perimetro();
                        break;
                    case 4:
                        ro.dibujar();
                        break;
                    case 5:
                        cout << "Regresando al menú principal...\n";
                    break;
                  }
                }while(alternativa6!=5);
                break;
            case 7:
                trapecio tr;
              int alternativa7;
                do
                {
                    cout<<"--- FIGURA: TRAPECIO ---\n";
                    cout<<"1. Ingresar / Modificar valores\n";
                    cout<<"2. Calcular área\n";
                    cout<<"3. Calcular perímetro\n";
                    cout<<"4. Dibujar figura\n";
                    cout<<"5. Regresar al menú principal\n";
                    cin>>alternativa7;
                 switch (alternativa7)
                 {
                    case 1:
                        tr.ingresarValores();
                        break;
                    case 2:
                        tr.area();
                        break;
                    case 3:
                        tr.perimetro();
                        break;
                    case 4:
                        tr.dibujar();
                        break;
                    case 5:
                        cout << "Regresando al menú principal...\n";
                    break;
                  }
                }while(alternativa7!=5);
                break;
            case 8:
                pentagono p;
                int alternativa8;
                do
                {
                    cout<<"--- FIGURA: PENTAGONO ---\n";
                    cout<<"1. Ingresar / Modificar valores\n";
                    cout<<"2. Calcular área\n";
                    cout<<"3. Calcular perímetro\n";
                    cout<<"4. Dibujar figura\n";
                    cout<<"5. Regresar al menú principal\n";
                    cin>>alternativa8;
                 switch (alternativa8)
                 {
                    case 1:
                        p.ingresarValores();
                        break;
                    case 2:
                        p.area();
                        break;
                    case 3:
                        p.perimetro();
                        break;
                    case 4:
                        p.dibujar();
                        break;
                    case 5:
                        cout << "Regresando al menú principal...\n";
                    break;
                  }
                }while(alternativa8!=5);
                break;
            case 9:
                hexagono h;
                int alternativa9;
                do
                {
                    cout<<"--- FIGURA: HEXAGONO ---\n";
                    cout<<"1. Ingresar / Modificar valores\n";
                    cout<<"2. Calcular área\n";
                    cout<<"3. Calcular perímetro\n";
                    cout<<"4. Dibujar figura\n";
                    cout<<"5. Regresar al menú principal\n";
                    cin>>alternativa9;
                 switch (alternativa9)
                 {
                    case 1:
                        h.ingresarValores();
                        break;
                    case 2:
                        h.area();
                        break;
                    case 3:
                        h.perimetro();
                        break;
                    case 4:
                        h.dibujar();
                        break;
                    case 5:
                        cout << "Regresando al menú principal...\n";
                    break;
                  }
                }while(alternativa9!=5);
                break;
            case 10:
                octagono o;
                int alternativa10;
                do
                {
                    cout<<"--- FIGURA: OCTAGONO ---\n";
                    cout<<"1. Ingresar / Modificar valores\n";
                    cout<<"2. Calcular área\n";
                    cout<<"3. Calcular perímetro\n";
                    cout<<"4. Dibujar figura\n";
                    cout<<"5. Regresar al menú principal\n";
                    cin>>alternativa10;
                 switch (alternativa10)
                 {
                    case 1:
                        o.ingresarValores();
                        break;
                    case 2:
                        o.area();
                        break;
                    case 3:
                        o.perimetro();
                        break;
                    case 4:
                        o.dibujar();
                        break;
                    case 5:
                        cout << "Regresando al menú principal...\n";
                    break;
                  }
                }while(alternativa10!=5);
                break;
        }

        break;
        case 2:
        int opcion;
        cout<<"Que figura deseas calcular: "<<endl;
        cout<<"1. cubo"<<endl;
        cout<<"2. esfera"<<endl;
        cout<<"3. cilindro"<<endl;
        cout<<"4. piramide"<<endl;
        cout<<"5. cono"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            cubo c;
            int opcionCubo;
            do{cout<<"--- FIGURA: CUBO ---\n";
            cout<<"1. Ingresar / Modificar valores\n";
            cout<<"2. Calcular área\n";
            cout<<"3. Calcular volumen\n";
            cout<<"4. Regresar al menú principal\n";
            cin>>opcionCubo;
            switch (opcionCubo)
            {
            case 1:
                c.ingresarValores();
                break;
            case 2:
                c.area();
                break;
            case 3:
                c.volumen();
                break;
            case 4:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
            }
            break;
        }while(opcionCubo!=4);
        case 2:
            esfera e;
            int opcionEsfera;
            do{
            cout<<"--- FIGURA: ESFERA ---\n";
            cout<<"1. Ingresar / Modificar valores\n";
            cout<<"2. Calcular área\n";
            cout<<"3. Calcular volumen\n";
            cout<<"4. Regresar al menú principal\n";
            cin>>opcionEsfera;
            switch (opcionEsfera)
            {
            case 1:
                e.ingresarValores();
                break;
            case 2:
                e.area();
                break;
            case 3:
                e.volumen();
                break;
            case 4:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
            }
            break;
        }while(opcionEsfera!=4);
        case 3:
            cilindro ci;
            int opcionCilindro;
            do{
            cout<<"--- FIGURA: CILINDRO ---\n";
            cout<<"1. Ingresar / Modificar valores\n";
            cout<<"2. Calcular área\n";
            cout<<"3. Calcular volumen\n";
            cout<<"4. Regresar al menú principal\n";
            cin>>opcionCilindro;
            switch (opcionCilindro)
            {
            case 1:
                ci.ingresarValores();
                break;
            case 2:
                ci.area();
                break;
            case 3:
                ci.volumen();
                break;
            case 4:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
            }
            break;
        }while(opcionCilindro!=4);
        case 4:
            piramide p;
            int opcionPiramide;
            do {cout<<"--- FIGURA: PIRÁMIDE ---\n";
            cout<<"1. Ingresar / Modificar valores\n";
            cout<<"2. Calcular área\n";
            cout<<"3. Calcular volumen\n";
            cout<<"4. Regresar al menú principal\n";
            cin>>opcionPiramide;
            switch (opcionPiramide)
            {
            case 1:
                p.ingresarValores();
                break;
            case 2:
                p.area();
                break;
            case 3:
                p.volumen();
                break;
            case 4:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
            }
            break;}while(opcion!=4);
        case 5:
            cono co;
            int opcionCono;
            do {cout<<"--- FIGURA: CONO ---\n";
            cout<<"1. Ingresar / Modificar valores\n";
            cout<<"2. Calcular área\n";
            cout<<"3. Calcular volumen\n";
            cout<<"4. Regresar al menú principal\n";
            cin>>opcionCono;
            switch (opcionCono)
            {
            case 1:
                co.ingresarValores();
                break;
            case 2:
                co.area();
                break;
            case 3:
                co.volumen();
                break;
            case 4:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
            }
            break;
            }while(opcionCono!=4);
        default:
            break;
        }
        break;
    };
}