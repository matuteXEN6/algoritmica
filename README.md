# 🧠 Actividad 9 — Práctica en papel: "Pensar antes de programar"

> Actividades de Contingencia y Continuidad Pedagógica) 2026

| Dato | Valor |
|---|---|
| Materia | Laboratorio de Programación |
| Escuela | EEST N.º 1 – "Eduardo Ader", Vicente López |
| Curso | 5.º año 3.º – Grupos A-B (miércoles y jueves, 15:15 a 17:15 h) |
| Docente | Mansilla Muñoz York Elías |
| Estudiante | **Mateo Roberts** |
| Versión | 1.0.0 |
| Fecha límite | 19 de noviembre de 2026 |

---

## 1. Objetivo pedagógico

Desacoplar el razonamiento lógico del lenguaje de programación. Antes de escribir código en
C, C++ o Python, el programador debe ser capaz de:

1. Diseñar la secuencia algorítmica mediante **diagramas de flujo universales**.
2. Simular la memoria RAM y el procesador en papel mediante la **prueba de escritorio (dry run)**.
3. Comprender que variables, condicionales, bucles, vectores y estructuras son conceptos
   abstractos e independientes de cualquier IDE o entorno.

## 2. Estructura del repositorio (obligatoria, según la consigna)

```
/algoritmica/
├── .gitignore                      <-- Exclusión de binarios (*.exe, *.out, .vscode/)
├── LICENSE                         <-- Licencia MIT escolar
├── README.md                       <-- Portada de la actividad y explicación técnica
├── docs/
│   ├── InformeEEST1_LPR2026_ACT09_RobertsMateo_v1.0.0.pdf   <-- Informe APA v7
│   └── hojas/                      <-- Hojas de carpeta digitalizadas (figuras del informe)
│       ├── 00_simbolologia.png
│       ├── 00_plantilla_dryrun.png
│       ├── hoja_ej0.png
│       ├── hoja_ej1.png
│       ├── hoja_ej2.png
│       ├── hoja_ej3.png
│       └── hoja_ej4.png
├── src/
│   └── main.cpp                    <-- Código fuente resuelto de referencia
└── capturas/
    └── matriz_ejecucion.png        <-- Captura de la ejecución en consola
```

## 3. Explicación técnica de lo resuelto

| Ejercicio | Concepto | Resultado verificado |
|---|---|---|
| **0 – Ejemplo guiado** | Variables, constantes y salida personalizada | `Ana`, 2000 → edad 26 en 2026 |
| **1 – Sensor de aprobación** | `NOTA_MINIMA = 6`, condicional con rombo | Caso A (4, 8) → promedio 6,00 → **APROBADO**; Caso B (3, 5) → promedio 4,00 → **A INTENSIFICACIÓN** |
| **2 – Contador de vidas** | Bucle `mientras vidas > 0` con flecha de retorno | 3 → 2 → 1 → 0 y salida **GAME OVER** |
| **3 – Registro de jugador** | `struct Jugador { nickname, nivel, esVIP }` | `Rothbard`, 5, Verdadero → **Bienvenido al Servidor VIP, Rothbard** |
| **4 – Control de inventario** | Vector `stock[5] = {12, 0, 5, 30, 0}`, recorrido con `i` | Alertas en las posiciones **1** y **4** |
| **Anexo** | Matriz 2×5, herencia `protected` y constructores (listas de inicialización) | Matriz impresa y acceso VIP verificado |

Cada ejercicio se desarrolló primero **en papel** (pseudocódigo → diagrama de flujo →
prueba de escritorio) y recién después se transcribió a C++ en `src/main.cpp`.

## 4. Compilación y ejecución

Requiere un compilador C++17 (se usó MinGW-w64 8.1.0 incluido con Code::Blocks).

```bash
g++ -std=c++17 -Wall -Wextra -o main.exe src/main.cpp
main.exe
```

Datos de prueba utilizados para la captura (`capturas/matriz_ejecucion.png`):

```
Ana
2000
4
8
3
5
Rothbard
5
1
```

Salidas esperadas (extracto):

```
APROBADO
A INTENSIFICACIÓN
Jugador activo. Vidas restantes: 3
Jugador activo. Vidas restantes: 2
Jugador activo. Vidas restantes: 1
GAME OVER
Bienvenido al Servidor VIP, Rothbard
ALERTA: Sin stock en la posición 1
ALERTA: Sin stock en la posición 4
```

## 5. Entregables

- **Informe APA v7:** `docs/InformeEEST1_LPR2026_ACT09_RobertsMateo_v1.0.0.pdf`
  (portada, resumen, desarrollo técnico, figuras de las hojas de carpeta, resultados,
  conclusión y referencias).
- **Hojas de carpeta:** `docs/hojas/*.png` (diagramas a color y tablas de dry run).
- **Captura de consola:** `capturas/matriz_ejecucion.png`.
- **Código fuente:** `src/main.cpp`.

## 6. Referencias técnicas

- GeeksforGeeks — Arreglos multidimensionales (matrices) en C++: <https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/>
- cplusplus.com — Herencia y modificadores de acceso (`protected`): <https://cplusplus.com/doc/tutorial/inheritance/>
- Microsoft Learn — Constructores y clases derivadas en C++: <https://learn.microsoft.com/es-es/cpp/cpp/constructors-cpp>
- Git Documentation — Control de versiones: <https://git-scm.com/doc>

## 7. Control de versiones

Repositorio Git individual inicializado en esta carpeta. Las URLs públicas (GitHub / GitLab)
deben completarse en la sección *Referencias* del informe APA una vez publicado el repositorio.

---

© 2026 Mateo Roberts · EEST N.º 1 "Eduardo Ader" · Licencia MIT escolar (ver `LICENSE`).
