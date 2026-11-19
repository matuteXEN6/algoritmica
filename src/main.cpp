/*
 * ============================================================================
 *  ACTIVIDAD 9 - PRÁCTICA EN PAPEL: "PENSAR ANTES DE PROGRAMAR"
 *  Actividades de Contingencia y Continuidad Pedagógica) 2026
 *
 *  Materia:      Laboratorio de Programación
 *  Escuela:      EEST N.º 1 - "Eduardo Ader", Vicente López
 *  Curso:        5.º año 3.º - Grupos A-B (miércoles y jueves 15:15 a 17:15)
 *  Docente:      Mansilla Muñoz York Elías
 *  Estudiante:   Mateo Roberts
 *  Archivo:      src/main.cpp  <-- Código fuente resuelto de referencia
 *  Versión:      1.0.0
 *
 *  Este archivo es la transcripción a C++ de los algoritmos diseñados primero
 *  en papel (pseudocódigo + diagrama de flujo + prueba de escritorio).
 *  El orden de ejecución respeta el orden de los ejercicios de la consigna.
 * ============================================================================
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

/* ---------- Constantes globales (ejercicios 0 y 1) ---------- */
const int NOTA_MINIMA = 6;      // Requisito EJERCICIO 1: constante NOTA_MINIMA = 6
const int ANIO_ACTUAL = 2026;   // Año de referencia del Ejemplo Guiado 0

/* ---------- Utilidades ---------- */
void separador() {
    cout << "------------------------------------------------------------\n";
}

void titulo(const string& texto) {
    cout << '\n';
    separador();
    cout << texto << '\n';
    separador();
}

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/* ==========================================================================
 *  EJERCICIO 0 (EJEMPLO GUIADO): "Hola Mundo" con cálculo de edad
 * ========================================================================== */
void ejercicio0() {
    titulo("EJERCICIO 0 - Hola Mundo personalizado (Edad 2026)");

    string nombre;
    int anioNacimiento;
    int edad;

    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su año de nacimiento: ";
    cin >> anioNacimiento;

    edad = ANIO_ACTUAL - anioNacimiento;

    cout << "Hola " << nombre << ", tu edad estimada en 2026 es: "
         << edad << " años.\n";
}

/* ==========================================================================
 *  EJERCICIO 1: El Sensor de Aprobación
 *  Variables, constantes y condicionales (rombo de decisión)
 * ========================================================================== */
void ejercicio1() {
    titulo("EJERCICIO 1 - Sensor de Aprobación (NOTA_MINIMA = 6)");

    float nota1, nota2, promedio;

    cout << "Ingrese nota1 (Primer Cuatrimestre): ";
    cin >> nota1;
    cout << "Ingrese nota2 (Segundo Cuatrimestre): ";
    cin >> nota2;

    promedio = (nota1 + nota2) / 2.0f;

    cout << fixed << setprecision(2);
    cout << "Promedio calculado: " << promedio << '\n';

    if (promedio >= NOTA_MINIMA) {
        cout << "APROBADO\n";
    } else {
        cout << "A INTENSIFICACIÓN\n";
    }

    cout << setprecision(6) << defaultfloat;  // restauro formato
}

/* ==========================================================================
 *  EJERCICIO 2: El Bucle del Contador de Vidas
 *  Estructura repetitiva MIENTRAS (while) con flecha de retorno
 * ========================================================================== */
void ejercicio2() {
    titulo("EJERCICIO 2 - Bucle del Contador de Vidas");

    int vidas = 3;

    while (vidas > 0) {
        cout << "Jugador activo. Vidas restantes: " << vidas << '\n';
        vidas = vidas - 1;
    }

    cout << "GAME OVER\n";
}

/* ==========================================================================
 *  EJERCICIO 3: Registro de Jugador en Memoria (struct)
 *  Agrupación heterogénea: texto + entero + booleano
 * ========================================================================== */
struct Jugador {
    string nickname;   // Texto
    int nivel;         // Entero
    bool esVIP;        // Booleano: Verdadero / Falso
};

void ejercicio3() {
    titulo("EJERCICIO 3 - Registro de Jugador (struct)");

    Jugador jugador;   // instancia de la estructura Jugador
    int valorVIP;

    cout << "Ingrese nickname: ";
    cin >> jugador.nickname;
    cout << "Ingrese nivel: ";
    cin >> jugador.nivel;
    cout << "Ingrese esVIP (1 = Verdadero, 0 = Falso): ";
    cin >> valorVIP;
    jugador.esVIP = (valorVIP == 1);

    if (jugador.esVIP == true) {
        cout << "Bienvenido al Servidor VIP, " << jugador.nickname << '\n';
    } else {
        cout << "Bienvenido al Servidor Estándar, " << jugador.nickname << '\n';
    }
    cout << "Nivel registrado: " << jugador.nivel << '\n';
}

/* ==========================================================================
 *  EJERCICIO 4: Control de Inventario con Arreglos (vector)
 *  Recorrido con índice i y detección de stock == 0
 * ========================================================================== */
void ejercicio4() {
    titulo("EJERCICIO 4 - Control de Inventario (vector stock)");

    int stock[5] = {12, 0, 5, 30, 0};
    int i = 0;

    while (i < 5) {
        if (stock[i] == 0) {
            cout << "ALERTA: Sin stock en la posición " << i << '\n';
        }
        i = i + 1;
    }
}

/* ==========================================================================
 *  ANEXO TÉCNICO (referencias de la consigna)
 *  - Arreglos multidimensionales (matrices) en C++  -> GeeksforGeeks
 *  - Herencia con modificador protected             -> cplusplus.com
 *  - Constructores y listas de inicialización       -> Microsoft Learn
 * ========================================================================== */

class CuentaBase {
protected:                       // accesible desde la clase derivada
    string nickname;
    int nivel;

public:
    CuentaBase(const string& nick, int niv)   // constructor de la clase base
        : nickname(nick), nivel(niv) {}

    virtual ~CuentaBase() = default;          // destructor virtual

    void mostrarDatos() const {
        cout << "Datos protegidos -> nickname: " << nickname
             << " | nivel: " << nivel << '\n';
    }
};

class JugadorVIP : protected CuentaBase {
private:
    bool accesoServidor;

public:
    // Lista de inicialización: se llama primero al constructor de CuentaBase
    JugadorVIP(const string& nick, int niv, bool acceso)
        : CuentaBase(nick, niv), accesoServidor(acceso) {}

    void mostrarBienvenida() const {
        mostrarDatos();   // permitido porque la herencia es protected
        cout << "Acceso VIP (herencia protected): "
             << (accesoServidor ? "VERDADERO" : "FALSO") << '\n';
    }
};

void anexoTecnico() {
    titulo("ANEXO TÉCNICO - Matrices, herencia protected y constructores");

    // Matriz 2 x 5: dos filas de inventario
    int matrizStock[2][5] = {
        {12, 0, 5, 30, 0},
        { 8, 3, 0, 15, 7}
    };

    cout << "Matriz de stock (2 filas x 5 posiciones):\n";
    cout << "        pos0  pos1  pos2  pos3  pos4\n";
    for (int f = 0; f < 2; ++f) {
        cout << "Fila " << f << " :";
        for (int c = 0; c < 5; ++c) {
            cout << setw(6) << matrizStock[f][c];
        }
        cout << '\n';
    }

    JugadorVIP invitado("Rothbard", 5, true);
    invitado.mostrarBienvenida();
}

/* ==========================================================================
 *  PROGRAMA PRINCIPAL
 * ========================================================================== */
int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);   // salida UTF-8 para tildes en consola Windows
#endif

    cout << "============================================================\n";
    cout << " ACTIVIDAD 9 - PENSAR ANTES DE PROGRAMAR\n";
    cout << " EEST N.1 'Eduardo Ader' | Laboratorio de Programación\n";
    cout << " Estudiante: Mateo Roberts | Prof. Mansilla Muñoz York Elías\n";
    cout << "============================================================\n";

    ejercicio0();

    // Caso A (nota1 = 4, nota2 = 8) y Caso B (nota1 = 3, nota2 = 5)
    ejercicio1();
    ejercicio1();

    ejercicio2();
    ejercicio3();
    ejercicio4();
    anexoTecnico();

    titulo("FIN DE LA EJECUCIÓN - Todos los algoritmos verificados");
    return 0;
}
