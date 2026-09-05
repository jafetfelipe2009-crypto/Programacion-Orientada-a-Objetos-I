
#include <iostream>   // Permite usar cout y cin.
#include <cstdlib>    // Permite usar rand() y srand().
#include <ctime>      // Permite usar time() y clock().
#include <iomanip>    // Permite usar setprecision().
#include <string>     // Permite usar string.

using namespace std;

// Cantidad maxima de numeros que puede guardar el programa.
const int MAX = 10000;

// FUNCION mostrarArreglo
// Muestra todos los elementos de un arreglo.
void mostrarArreglo(int numeros[], int n) {
    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << "\n";
}
// FUNCION copiarArreglo
// Copia los valores de un arreglo a otro.
// Se usa para conservar los numeros originales.
void copiarArreglo(int origen[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}

// FUNCION invertirArreglo
// Invierte un arreglo ya ordenado de menor a mayor.
// De esta forma se obtiene el orden descendente.
void invertirArreglo(int numeros[], int n) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio < fin) {
        int aux = numeros[inicio];
        numeros[inicio] = numeros[fin];
        numeros[fin] = aux;

        inicio++;
        fin--;
    }
}
// BURBUJA
// Compara elementos vecinos y los intercambia cuando estan
// en el orden incorrecto.
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}

// INSERCION
// Toma cada numero y lo coloca en la posicion correcta dentro
// de la parte del arreglo que ya se encuentra ordenada.
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int actual = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > actual) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = actual;
    }
}
// SELECCION
// Busca el numero menor y lo coloca en la siguiente posicion
// disponible del arreglo.
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int posicionMenor = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[posicionMenor]) {
                posicionMenor = j;
            }
        }

        int aux = a[i];
        a[i] = a[posicionMenor];
        a[posicionMenor] = aux;
    }
}

// FUNCION mezclar
// Funcion auxiliar de Merge Sort.
// Une dos partes ya ordenadas del arreglo.
void mezclar(int a[], int izquierda, int medio, int derecha) {
    int cantidad = derecha - izquierda + 1;
    int* temporal = new int[cantidad];

    int i = izquierda;
    int j = medio + 1;
    int k = 0;

    while (i <= medio && j <= derecha) {
        if (a[i] <= a[j]) {
            temporal[k] = a[i];
            i++;
        } else {
            temporal[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= medio) {
        temporal[k] = a[i];
        i++;
        k++;
    }

    while (j <= derecha) {
        temporal[k] = a[j];
        j++;
        k++;
    }

    for (int x = 0; x < cantidad; x++) {
        a[izquierda + x] = temporal[x];
    }

    delete[] temporal;
}

// MERGE SORT
// Divide el arreglo en partes pequenas y despues las vuelve
// a unir en forma ordenada.
void mergeSort(int a[], int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = (izquierda + derecha) / 2;

        mergeSort(a, izquierda, medio);
        mergeSort(a, medio + 1, derecha);
        mezclar(a, izquierda, medio, derecha);
    }
}
// FUNCION particion
// Funcion auxiliar de Quick Sort.
// Coloca los numeros menores al pivote a la izquierda y los
// mayores a la derecha.
int particion(int a[], int inicio, int fin) {
    int pivote = a[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (a[j] < pivote) {
            i++;

            int aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    }

    int aux = a[i + 1];
    a[i + 1] = a[fin];
    a[fin] = aux;

    return i + 1;
}
// QUICK SORT
// Usa un pivote para separar los numeros en grupos y luego
// ordena cada grupo.
void quickSort(int a[], int inicio, int fin) {
    if (inicio < fin) {
        int posicionPivote = particion(a, inicio, fin);

        quickSort(a, inicio, posicionPivote - 1);
        quickSort(a, posicionPivote + 1, fin);
    }
}
// COUNTING SORT
// Cuenta cuantas veces aparece cada numero y luego reconstruye
// el arreglo en orden.
void countingSort(int a[], int n) {
    if (n <= 0) {
        return;
    }

    int menor = a[0];
    int mayor = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < menor) {
            menor = a[i];
        }

        if (a[i] > mayor) {
            mayor = a[i];
        }
    }

    int rango = mayor - menor + 1;
    int* contador = new int[rango];

    for (int i = 0; i < rango; i++) {
        contador[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        contador[a[i] - menor]++;
    }

    int posicion = 0;

    for (int i = 0; i < rango; i++) {
        while (contador[i] > 0) {
            a[posicion] = i + menor;
            posicion++;
            contador[i]--;
        }
    }

    delete[] contador;
}
// FUNCION nombreAlgoritmo
// Devuelve el nombre del metodo segun la opcion seleccionada.
string nombreAlgoritmo(int opcion) {
    switch (opcion) {
        case 1: return "Bubble Sort";
        case 2: return "Insertion Sort";
        case 3: return "Selection Sort";
        case 4: return "Merge Sort";
        case 5: return "Quick Sort";
        case 6: return "Counting Sort";
    }

    return "Desconocido";
}
// FUNCION ordenar
// Recibe la opcion elegida y ejecuta el algoritmo correspondiente.
void ordenar(int opcion, int numeros[], int n) {
    switch (opcion) {
        case 1:
            bubbleSort(numeros, n);
            break;

        case 2:
            insertionSort(numeros, n);
            break;

        case 3:
            selectionSort(numeros, n);
            break;

        case 4:
            mergeSort(numeros, 0, n - 1);
            break;

        case 5:
            quickSort(numeros, 0, n - 1);
            break;

        case 6:
            countingSort(numeros, n);
            break;
    }
}

// FUNCION ordenarConMetodo
// Crea una copia de los numeros originales, aplica el algoritmo
// elegido, permite escoger ascendente o descendente y muestra
// el resultado final.
void ordenarConMetodo(int numeros[], int n) {
    int opcionMetodo;
    int tipoOrden;
    int copia[MAX];

    cout << "\nMETODOS DE ORDENAMIENTO\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "6. Counting Sort\n";
    cout << "Seleccione un metodo: ";
    cin >> opcionMetodo;

    if (opcionMetodo < 1 || opcionMetodo > 6) {
        cout << "Opcion incorrecta.\n";
        return;
    }

    cout << "\nTIPO DE ORDEN\n";
    cout << "1. Ascendente (menor a mayor)\n";
    cout << "2. Descendente (mayor a menor)\n";
    cout << "Seleccione una opcion: ";
    cin >> tipoOrden;

    if (tipoOrden != 1 && tipoOrden != 2) {
        cout << "Opcion incorrecta.\n";
        return;
    }

    // Conserva los datos originales.
    copiarArreglo(numeros, copia, n);

    cout << "\nNumeros antes de ordenar:\n";
    mostrarArreglo(copia, n);

    // Inicia la medicion del tiempo.
    clock_t inicio = clock();

    // Ordena de menor a mayor con el metodo seleccionado.
    ordenar(opcionMetodo, copia, n);

    // Si se eligio descendente, invierte el resultado.
    if (tipoOrden == 2) {
        invertirArreglo(copia, n);
    }

    // Termina la medicion del tiempo.
    clock_t fin = clock();

    double tiempo = double(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;

    cout << "\nMetodo utilizado: " << nombreAlgoritmo(opcionMetodo) << "\n";

    if (tipoOrden == 1) {
        cout << "Orden: Ascendente\n";
    } else {
        cout << "Orden: Descendente\n";
    }

    cout << "\nNumeros ordenados:\n";
    mostrarArreglo(copia, n);

    cout << "Tiempo: " << fixed << setprecision(4)
         << tiempo << " ms\n";
}

// FUNCION compararMetodos
// Ejecuta los seis algoritmos con los mismos numeros y muestra
// cuanto demora cada uno.
void compararMetodos(int numeros[], int n) {
    int copia[MAX];

    cout << "\nCOMPARACION DE METODOS\n";
    for (int opcion = 1; opcion <= 6; opcion++) {
        copiarArreglo(numeros, copia, n);

        clock_t inicio = clock();
        ordenar(opcion, copia, n);
        clock_t fin = clock();

        double tiempo = double(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;

        cout << setw(18) << left << nombreAlgoritmo(opcion)
             << ": " << fixed << setprecision(4)
             << tiempo << " ms\n";
    }
}

// FUNCION PRINCIPAL
// Aqui empieza la ejecucion del programa.
int main() {
    int numeros[MAX];
    int cantidad = 0;
    int opcion;

    // Hace que rand() genere valores diferentes en cada ejecucion.
    srand(time(NULL));

    do {
        cout << "   PROGRAMA DE ORDENAMIENTO\n";
        cout << "1. Generar numeros aleatorios\n";
        cout << "2. Ingresar numeros manualmente\n";
        cout << "3. Mostrar numeros actuales\n";
        cout << "4. Ordenar con un metodo\n";
        cout << "5. Comparar todos los metodos\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            // Genera numeros aleatorios.
            case 1: {
                int minimo;
                int maximo;

                cout << "Cantidad de numeros: ";
                cin >> cantidad;

                if (cantidad <= 0 || cantidad > MAX) {
                    cout << "Cantidad incorrecta. El maximo es " << MAX << ".\n";
                    cantidad = 0;
                    break;
                }

                cout << "Valor minimo: ";
                cin >> minimo;

                cout << "Valor maximo: ";
                cin >> maximo;

                if (minimo > maximo) {
                    cout << "El minimo no puede ser mayor que el maximo.\n";
                    cantidad = 0;
                    break;
                }

                for (int i = 0; i < cantidad; i++) {
                    numeros[i] = minimo + rand() % (maximo - minimo + 1);
                }

                cout << "Numeros generados correctamente.\n";
                break;
            }

            // Permite escribir los numeros manualmente.
            case 2:
                cout << "Cantidad de numeros: ";
                cin >> cantidad;

                if (cantidad <= 0 || cantidad > MAX) {
                    cout << "Cantidad incorrecta. El maximo es " << MAX << ".\n";
                    cantidad = 0;
                    break;
                }

                cout << "Ingrese los numeros:\n";

                for (int i = 0; i < cantidad; i++) {
                    cout << "Numero " << i + 1 << ": ";
                    cin >> numeros[i];
                }

                cout << "Numeros guardados correctamente.\n";
                break;

            // Muestra los numeros guardados.
            case 3:
                if (cantidad == 0) {
                    cout << "Primero debe ingresar o generar numeros.\n";
                } else {
                    cout << "\nNumeros actuales:\n";
                    mostrarArreglo(numeros, cantidad);
                }
                break;

            // Permite escoger cualquiera de los seis algoritmos.
            case 4:
                if (cantidad == 0) {
                    cout << "Primero debe ingresar o generar numeros.\n";
                } else {
                    ordenarConMetodo(numeros, cantidad);
                }
                break;

            // Ejecuta los seis metodos para comparar sus tiempos.
            case 5:
                if (cantidad == 0) {
                    cout << "Primero debe ingresar o generar numeros.\n";
                } else {
                    compararMetodos(numeros, cantidad);
                }
                break;

            case 6:
                cout << "Programa terminado.\n";
                break;

            default:
                cout << "Opcion incorrecta.\n";
        }

    } while (opcion != 6);

    return 0;
}


    // return 0 indica que el programa finalizo correctamente.
    return 0;
}
