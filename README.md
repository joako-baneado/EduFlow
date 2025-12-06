# EduFlow Compiler

**EduFlow** es un compilador y simulador diseñado para la gestión de flujos de matrícula académica. Permite definir cursos, reglas de prerequisitos y workflows de etapas de matrícula, así como simular procesos de inscripción de estudiantes validando reglas académicas.

## Características

- **Definición de Cursos:** Configuración de créditos, capacidad, horarios y prerequisitos.
- **Reglas Académicas:** Validación de requisitos lógicos complejos.
- **Workflows de Matrícula:** Definición de etapas con límites de créditos y restricciones.
- **Simulación:** Ejecución de intentos de matrícula para estudiantes con perfiles específicos.

## Requisitos del Sistema (Linux)

Este proyecto está diseñado para compilarse en entornos Linux. Asegúrate de tener instaladas las siguientes dependencias.

### Instalación de Dependencias

Dependiendo de tu distribución (o si usas un contenedor), ejecuta:

**Debian/Ubuntu:**

```bash
sudo apt update
sudo apt install cmake llvm-dev libantlr4-runtime-dev default-jdk build-essential
```

**Alpine Linux** (común en contenedores):

```bash
apk add cmake make g++ llvm-dev antlr4-cpp-runtime-dev openjdk11
```

**Arch Linux:**

```bash
sudo pacman -S cmake llvm antlr4-runtime java-runtime-common base-devel
```

## Estructura del Proyecto

```
EduFlow/
├── src/
│   ├── ast/           # Definiciones del Árbol de Sintaxis Abstracta
│   ├── codegen/       # Generación de código (LLVM IR / Ejecución)
│   ├── visitor/       # Patrón Visitor para recorrer el árbol ANTLR
│   ├── EduFlow.g4     # Gramática ANTLR4 del lenguaje
│   └── main.cpp       # Punto de entrada del compilador
├── antlr-4.13.2-complete.jar  # Herramienta para generación de parser
├── CMakeLists.txt     # Configuración de construcción
└── *.in               # Archivos de prueba (Test inputs)
```

## Guía de Compilación (Paso a Paso)

Sigue estos comandos en tu terminal Linux para generar el ejecutable.

### 1. Limpieza y Preparación

Ubícate en la raíz del proyecto `EduFlow`. Si existía una compilación previa, límpiala:

```bash
rm -rf build
mkdir build
cd build
```

### 2. Configuración con CMake

Genera los Makefiles necesarios. CMake detectará automáticamente LLVM y Java en tu sistema Linux.

```bash
cmake ..
```

_Salida esperada:_ Deberías ver mensajes como `Found LLVM` y `Found Java`.

### 3. Compilación del Proyecto

Ejecuta el comando `make` para compilar el código fuente y generar el parser de ANTLR.

```bash
make
```

### 4. Ejecución

Una vez termine la compilación, el ejecutable `eduflow` estará listo en el directorio `build`.

```bash
# Otorgar permisos de ejecución si es necesario
chmod +x eduflow

# Ejecutar con el archivo de prueba
./eduflow ../Test.in
```

## Ejemplo de Código EduFlow

```eduflow
define course CS101 {
    set credits = 4;
    set capacity = 30;
    set department = "Computer Science";
}

define rule BasicReq {
    require credits_completed > 20;
}

simulate "Matricula 2024-1" using SimpleStrategy {
    for student {
        set id = "u202010101";
        set credits_completed = 25;
    }
    attempt enroll in [CS101];
}
```
