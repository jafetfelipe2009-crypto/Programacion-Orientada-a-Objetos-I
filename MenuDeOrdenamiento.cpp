
// Libreria para usar cout y cin (mostrar y leer datos por consola).
#include <iostream>
// Libreria para usar rand() y srand(), que generan numeros aleatorios.
#include <cstdlib>
// Libreria para trabajar con el tiempo y usar clock() y time().
#include <ctime>
// Libreria para dar formato a la salida, por ejemplo setw() y setprecision().
#include <iomanip>
// Libreria para trabajar con cadenas de texto mediante el tipo string.
#include <string>
using namespace std;

const int MAX = 10000;

void copiarArreglo(int origen[], int destino[], int n) {
    // Recorre todas las posiciones del arreglo desde 0 hasta n - 1.
    for (int i = 0; i < n; i++) {
        // Copia el valor de origen en la misma posicion de destino.
        destino[i] = origen[i];
    }
}
// FUNCION bubbleSort
// Ordena un arreglo usando el metodo Burbuja.
// Compara elementos vecinos y los intercambia si estan desordenados.
void bubbleSort(int a[], int n) {
    // El ciclo externo indica cuantas pasadas se realizan.
    for (int i = 0; i < n - 1; i++) {
        // El ciclo interno compara los elementos vecinos.
        // n - i - 1 evita revisar los elementos que ya quedaron ordenados.
        for (int j = 0; j < n - i - 1; j++) {
            // Si el elemento actual es mayor que el siguiente, se intercambian.
            if (a[j] > a[j + 1]) {
                // Variable auxiliar para no perder el valor durante el intercambio.
                int aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}

// FUNCION insertionSort
// Ordena un arreglo usando Insercion.
// Toma cada elemento y lo coloca en la posicion correcta de la parte ya ordenada.
void insertionSort(int a[], int n) {
    // Se empieza desde la posicion 1 porque se considera que a[0] ya esta ordenado.
    for (int i = 1; i < n; i++) {
        // Guarda temporalmente el elemento que se quiere insertar.
        int actual = a[i];

        // j comienza una posicion antes del elemento actual.
        int j = i - 1;

        // Mientras no se llegue al inicio y los valores sean mayores que 'actual',
        // se desplazan una posicion hacia la derecha.
        while (j >= 0 && a[j] > actual) {
            a[j + 1] = a[j];
            j--;
        }

        // Coloca el elemento guardado en la posicion correcta.
        a[j + 1] = actual;
    }
}

// =============================================================
// FUNCION selectionSort
// Ordena un arreglo usando Seleccion.
// Busca el elemento menor y lo coloca en la primera posicion disponible.
// =============================================================
void selectionSort(int a[], int n) {
    // Recorre el arreglo hasta la penultima posicion.
    for (int i = 0; i < n - 1; i++) {
        // Se supone al inicio que la posicion i contiene el valor menor.
        int menor = i;

        // Busca un valor menor en las posiciones siguientes.
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[menor]) {
                // Guarda la posicion donde se encontro un valor mas pequeño.
                menor = j;
            }
        }

        // Intercambia el elemento actual con el menor encontrado.
        int aux = a[i];
        a[i] = a[menor];
        a[menor] = aux;
    }
}


// FUNCION mezclar
// Es una funcion auxiliar de Merge Sort.
// Une dos partes de un arreglo que ya estan ordenadas.
// izquierda: primera posicion del bloque.
// medio: punto donde se divide el bloque.
// derecha: ultima posicion del bloque.
void mezclar(int a[], int izquierda, int medio, int derecha) {
    // Calcula cuantos elementos hay en el bloque que se va a mezclar.
    int cantidad = derecha - izquierda + 1;

    // Crea dinamicamente un arreglo temporal con la cantidad necesaria.
    int* temp = new int[cantidad];

    // i recorre la mitad izquierda.
    int i = izquierda;

    // j recorre la mitad derecha.
    int j = medio + 1;

    // k indica la posicion donde se va guardando en el arreglo temporal.
    int k = 0;

    // Compara elementos de ambas mitades mientras queden datos en las dos.
    while (i <= medio && j <= derecha) {
        if (a[i] < a[j]) {
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    // Si quedaron elementos en la mitad izquierda, se copian al temporal.
    while (i <= medio) {
        temp[k] = a[i];
        i++;
        k++;
    }

    // Si quedaron elementos en la mitad derecha, se copian al temporal.
    while (j <= derecha) {
        temp[k] = a[j];
        j++;
        k++;
    }

    // Copia los valores ordenados del arreglo temporal al arreglo original.
    for (int x = 0; x < cantidad; x++) {
        a[izquierda + x] = temp[x];
    }

    // Libera la memoria que se habia reservado con new.
    delete[] temp;
}


// FUNCION mergeSort
// Ordena el arreglo mediante el metodo Merge Sort.
// Divide el arreglo en partes pequeñas y luego las vuelve a unir ordenadas.
// Esta funcion es recursiva porque se llama a si misma.
void mergeSort(int a[], int izquierda, int derecha) {
    // Solo se divide si existe mas de un elemento en el bloque.
    if (izquierda < derecha) {
        // Calcula la posicion central del bloque.
        int medio = (izquierda + derecha) / 2;

        // Ordena recursivamente la mitad izquierda.
        mergeSort(a, izquierda, medio);

        // Ordena recursivamente la mitad derecha.
        mergeSort(a, medio + 1, derecha);

        // Une las dos mitades ya ordenadas.
        mezclar(a, izquierda, medio, derecha);
    }
}
// FUNCION particion
// Es una funcion auxiliar de Quick Sort.
// Toma un pivote y coloca los valores menores a su izquierda
// y los mayores a su derecha.
// Devuelve la posicion final del pivote.
int particion(int a[], int inicio, int fin) {
    // Se usa el ultimo elemento del bloque como pivote.
    int pivote = a[fin];

    // i indica la ultima posicion donde se ha colocado un valor menor al pivote.
    int i = inicio - 1;

    // Recorre desde inicio hasta una posicion antes del pivote.
    for (int j = inicio; j < fin; j++) {
        // Si el valor actual es menor que el pivote, se mueve a la izquierda.
        if (a[j] < pivote) {
            i++;

            // Intercambia a[i] con a[j].
            int aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    }

    // Coloca el pivote despues de los elementos menores.
    int aux = a[i + 1];
    a[i + 1] = a[fin];
    a[fin] = aux;

    // Retorna la posicion definitiva del pivote.
    return i + 1;
}
// FUNCION quickSort
// Ordena el arreglo usando Quick Sort.
// Divide el arreglo alrededor de un pivote y ordena cada parte.
// Tambien es una funcion recursiva.
void quickSort(int a[], int inicio, int fin) {
    // Solo trabaja si el bloque tiene al menos dos elementos.
    if (inicio < fin) {
        // Se realiza la particion y se obtiene la posicion del pivote.
        int p = particion(a, inicio, fin);

        // Ordena los elementos que quedaron antes del pivote.
        quickSort(a, inicio, p - 1);

        // Ordena los elementos que quedaron despues del pivote.
        quickSort(a, p + 1, fin);
    }
}
// FUNCION countingSort
// Ordena contando cuantas veces aparece cada valor.
// Es adecuado cuando el rango de numeros no es demasiado grande.
void countingSort(int a[], int n) {
    // Si no hay elementos, termina inmediatamente.
    if (n == 0) {
        return;
    }

    // Se supone inicialmente que el primer valor es el menor y el mayor.
    int menor = a[0];
    int mayor = a[0];

    // Busca el menor y el mayor valor del arreglo.
    for (int i = 1; i < n; i++) {
        if (a[i] < menor) {
            menor = a[i];
        }

        if (a[i] > mayor) {
            mayor = a[i];
        }
    }

    // Calcula cuantas posiciones necesita el arreglo contador.
    int rango = mayor - menor + 1;

    // Crea dinamicamente el arreglo contador.
    int* contador = new int[rango];

    // Inicializa todos los contadores en cero.
    for (int i = 0; i < rango; i++) {
        contador[i] = 0;
    }

    // Cuenta cuantas veces aparece cada numero.
    for (int i = 0; i < n; i++) {
        contador[a[i] - menor]++;
    }

    // Indica en que posicion del arreglo original se va a escribir.
    int posicion = 0;

    // Recorre todos los posibles valores del rango.
    for (int i = 0; i < rango; i++) {
        // Mientras un valor tenga apariciones pendientes, se escribe en el arreglo.
        while (contador[i] > 0) {
            a[posicion] = i + menor;
            posicion++;
            contador[i]--;
        }
    }

    // Libera la memoria utilizada por el contador.
    delete[] contador;
}
// FUNCION medirTiempo
// Ejecuta un algoritmo y calcula cuanto tarda en milisegundos.
// opcion: numero del algoritmo elegido.
// numeros[]: arreglo original.
// n: cantidad de numeros.
// Devuelve un valor double con el tiempo empleado.
double medirTiempo(int opcion, int numeros[], int n) {
    // Crea una copia para que cada algoritmo ordene los mismos datos originales.
    int copia[MAX];
    copiarArreglo(numeros, copia, n);

    // Guarda el instante en que comienza el algoritmo.
    clock_t inicio = clock();

    // El switch selecciona el algoritmo de acuerdo con la opcion recibida.
    switch (opcion) {
        case 1:
            bubbleSort(copia, n);
            break;

        case 2:
            insertionSort(copia, n);
            break;

        case 3:
            selectionSort(copia, n);
            break;

        case 4:
            mergeSort(copia, 0, n - 1);
            break;

        case 5:
            quickSort(copia, 0, n - 1);
            break;

        case 6:
            countingSort(copia, n);
            break;
    }

    // Guarda el instante cuando termina el algoritmo.
    clock_t fin = clock();

    // Convierte la diferencia de tiempo a milisegundos.
    double tiempo = double(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;

    // Devuelve el tiempo calculado.
    return tiempo;
}
// FUNCION nombreAlgoritmo
// Recibe el numero de una opcion y devuelve el nombre del algoritmo.
string nombreAlgoritmo(int opcion) {
    switch (opcion) {
        case 1:
            return "Bubble Sort";

        case 2:
            return "Insertion Sort";

        case 3:
            return "Selection Sort";

        case 4:
            return "Merge Sort";

        case 5:
            return "Quick Sort";

        case 6:
            return "Counting Sort";
    }

    // Se devuelve este texto si la opcion no corresponde a ningun algoritmo.
    return "Desconocido";
}
// FUNCION mostrarResultados
// Muestra los nombres de los algoritmos ejecutados y sus tiempos.
void mostrarResultados(string nombres[], double tiempos[], int cantidad) {
    // Si no hay resultados, muestra un mensaje y termina la funcion.
    if (cantidad == 0) {
        cout << "\nNo hay resultados guardados.\n";
        return;
    }

    // Encabezado de la tabla de resultados.
    cout << "RESULTADOS DE LOS ALGORITMOS\n";
    // Recorre todos los resultados almacenados.
    for (int i = 0; i < cantidad; i++) {
        // setw(18) reserva espacio para el nombre.
        // left alinea el texto a la izquierda.
        // fixed evita notacion cientifica.
        // setprecision(4) muestra cuatro decimales.
        cout << setw(18) << left << nombres[i]
             << ": " << fixed << setprecision(4)
             << tiempos[i] << " ms\n";
    }
}
// FUNCION guardarResultado
// Guarda el nombre de un algoritmo y el tiempo que demoro.
// Si ya existe un resultado para ese algoritmo, actualiza su tiempo.
// cantidad se pasa por referencia (&) para poder modificar su valor original.
void guardarResultado(string nombre, double tiempo,
                      string nombres[], double tiempos[], int& cantidad) {
    // Variable que indica si el algoritmo ya estaba guardado.
    bool encontrado = false;

    // Busca el nombre del algoritmo en los resultados existentes.
    for (int i = 0; i < cantidad; i++) {
        if (nombres[i] == nombre) {
            // Si ya existe, reemplaza el tiempo anterior por el nuevo.
            tiempos[i] = tiempo;
            encontrado = true;
        }
    }

    // Si no estaba guardado y todavia hay espacio, agrega un nuevo resultado.
    if (!encontrado && cantidad < 6) {
        nombres[cantidad] = nombre;
        tiempos[cantidad] = tiempo;
        cantidad++;
    }
}

// FUNCION menuOrdenamiento
// Muestra un submenu para seleccionar un metodo de ordenamiento.
// Permite ejecutar uno solo o los seis algoritmos.
void menuOrdenamiento(int numeros[], int n,
                      string nombres[], double tiempos[], int& cantidadResultados) {
    // Guarda la opcion elegida dentro del submenu.
    int opcion;

    // do-while hace que el menu aparezca al menos una vez.
    do {
        cout << "\nMETODOS DE ORDENAMIENTO\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Selection Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Counting Sort\n";
        cout << "7. Ejecutar todos\n";
        cout << "8. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        // Si se eligio uno de los seis algoritmos.
        if (opcion >= 1 && opcion <= 6) {
            // Calcula el tiempo del algoritmo seleccionado.
            double tiempo = medirTiempo(opcion, numeros, n);

            // Obtiene su nombre a partir del numero de opcion.
            string nombre = nombreAlgoritmo(opcion);

            // Guarda el resultado para poder mostrarlo despues.
            guardarResultado(nombre, tiempo, nombres, tiempos, cantidadResultados);

            // Muestra el tiempo obtenido.
            cout << nombre << " demoro "
                 << fixed << setprecision(4)
                 << tiempo << " ms\n";
        }

        // Si el usuario elige ejecutar todos los algoritmos.
        else if (opcion == 7) {
            // Recorre las opciones del 1 al 6.
            for (int i = 1; i <= 6; i++) {
                double tiempo = medirTiempo(i, numeros, n);
                string nombre = nombreAlgoritmo(i);

                guardarResultado(nombre, tiempo, nombres, tiempos, cantidadResultados);

                cout << nombre << " demoro "
                     << fixed << setprecision(4)
                     << tiempo << " ms\n";
            }
        }

        // Si se ingreso una opcion que no existe y tampoco es 8.
        else if (opcion != 8) {
            cout << "Opcion incorrecta.\n";
        }

    // El submenu se repite hasta seleccionar la opcion 8.
    } while (opcion != 8);
}
// FUNCION PRINCIPAL main
// Es el punto donde comienza la ejecucion del programa.
int main() {
    // Arreglo principal donde se almacenan los numeros aleatorios.
    int numeros[MAX];

    // Indica cuantos numeros se generaron realmente.
    int cantidadNumeros = 0;

    // Guarda la opcion seleccionada en el menu principal.
    int opcion;

    // Arreglo para guardar los nombres de los seis algoritmos.
    string nombres[6];

    // Arreglo para guardar el tiempo de cada algoritmo.
    double tiempos[6];

    // Indica cuantos resultados se encuentran guardados.
    int cantidadResultados = 0;

    // Inicializa la semilla de rand() usando la hora actual.
    // Esto ayuda a que los numeros aleatorios cambien cada vez que se ejecuta.
    srand(time(NULL));

    // El menu principal se repite hasta que el usuario elige salir.
    do {
        cout << "COMPARACION DE ORDENAMIENTOS\n";
        cout << "1. Generar numeros aleatorios\n";
        cout << "2. Mostrar numeros\n";
        cout << "3. Ordenar con un metodo\n";
        cout << "4. Comparar todos los metodos\n";
        cout << "5. Mostrar resultados\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";

        // Lee la opcion escrita por el usuario.
        cin >> opcion;

        // switch permite ejecutar una accion diferente segun la opcion elegida.
        switch (opcion) {

            case 1: {
                // Guarda el valor minimo y maximo del rango solicitado.
                int minimo, maximo;

                cout << "Cantidad de numeros: ";
                cin >> cantidadNumeros;

                // Verifica que la cantidad sea valida y no exceda MAX.
                if (cantidadNumeros <= 0 || cantidadNumeros > MAX) {
                    cout << "Cantidad no valida. Maximo: " << MAX << "\n";

                    // Se coloca cero para indicar que no existen datos validos.
                    cantidadNumeros = 0;

                    // break termina este case y vuelve al menu principal.
                    break;
                }

                // Solicita los limites del rango de numeros aleatorios.
                cout << "Valor minimo: ";
                cin >> minimo;

                cout << "Valor maximo: ";
                cin >> maximo;

                // Comprueba que el minimo sea menor o igual al maximo.
                if (minimo > maximo) {
                    cout << "El minimo no puede ser mayor que el maximo.\n";
                    cantidadNumeros = 0;
                    break;
                }

                // Llena el arreglo con numeros aleatorios dentro del rango pedido.
                for (int i = 0; i < cantidadNumeros; i++) {
                    // rand() genera un numero entero pseudoaleatorio.
                    // El modulo % limita el numero al tamaño del rango.
                    numeros[i] = minimo + rand() % (maximo - minimo + 1);
                }

                // Borra logicamente los resultados anteriores porque ahora hay
                // un nuevo conjunto de numeros para comparar.
                cantidadResultados = 0;

                cout << "Numeros generados correctamente.\n";
                break;
            }
            case 2:
                // Verifica si primero se generaron numeros.
                if (cantidadNumeros == 0) {
                    cout << "Primero debe generar numeros.\n";
                } else {
                    cout << "\nNumeros generados:\n";

                    // Recorre el arreglo y muestra cada numero.
                    for (int i = 0; i < cantidadNumeros; i++) {
                        cout << numeros[i] << " ";
                    }

                    cout << "\n";
                }
                break;
            case 3:
                if (cantidadNumeros == 0) {
                    cout << "Primero debe generar numeros.\n";
                } else {
                    // Abre el submenu de algoritmos de ordenamiento.
                    menuOrdenamiento(numeros, cantidadNumeros,
                                     nombres, tiempos, cantidadResultados);
                }
                break;
            case 4:
                if (cantidadNumeros == 0) {
                    cout << "Primero debe generar numeros.\n";
                } else {
                    // Ejecuta los algoritmos numerados del 1 al 6.
                    for (int i = 1; i <= 6; i++) {
                        // Calcula el tiempo del algoritmo actual.
                        double tiempo = medirTiempo(i, numeros, cantidadNumeros);

                        // Obtiene el nombre correspondiente.
                        string nombre = nombreAlgoritmo(i);

                        // Guarda o actualiza el resultado.
                        guardarResultado(nombre, tiempo,
                                         nombres, tiempos, cantidadResultados);

                        // Muestra inmediatamente el tiempo obtenido.
                        cout << nombre << " demoro "
                             << fixed << setprecision(4)
                             << tiempo << " ms\n";
                    }
                }
                break;
            case 5:
                mostrarResultados(nombres, tiempos, cantidadResultados);
                break;
            case 6:
                cout << "Programa terminado.\n";
                break;

            // Se ejecuta si la opcion ingresada no esta entre 1 y 6.
            default:
                cout << "Opcion incorrecta.\n";
        }

    // Mientras la opcion no sea 6, el menu principal vuelve a mostrarse.
    } while (opcion != 6);

    // return 0 indica que el programa finalizo correctamente.
    return 0;
}
