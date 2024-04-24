##Almacenamiento de Hojas de Vida**

Este programa en C++ permite gestionar el almacenamiento de hojas de vida de empleados y la autenticación de usuarios. A continuación se presenta una descripción general del programa:

### Funcionalidades Principales:

1. **Inicio de Sesión**:
   - El usuario debe iniciar sesión con su nombre de usuario y contraseña para acceder al sistema.

2. **Menú Principal**:
   - **Registrar Hoja de Vida**: Permite registrar una nueva hoja de vida para un empleado.
   - **Consultar Hoja de Vida**: Permite buscar y consultar hojas de vida por código de empleado, apellidos-nombres o número de cédula.
   - **Mostrar Códigos de Empleados**: Lista todos los códigos de empleados registrados.
   - **Modificar Hoja de Vida**: Permite modificar los datos de una hoja de vida existente.
   - **Desvincular Empleado**: Elimina la hoja de vida de un empleado.
   - **Eliminar Todos los Registros**: Borra todas las hojas de vida almacenadas.
   - **Registrar Usuario**: Permite registrar un nuevo usuario para acceder al sistema.

### Consideraciones:

- **Código de Empleados**: Cada empleado tiene un código único asignado.
- **Formato de Datos**: Se solicitan diversos datos personales, académicos y laborales para completar la hoja de vida.
- **Validación de Datos**: No se realiza una validación exhaustiva de los datos ingresados.
- **Archivos de Datos**: Se asume que los archivos `HVIDAS.DAT` y `HVUSUARIOS.DAT` existen previamente y tienen el formato adecuado.
- **Interfaz de Usuario**: La interfaz está diseñada para ser utilizada en una consola de texto.

### Requisitos del Sistema:

- Este programa está diseñado para ser ejecutado en un entorno compatible con C++ y tiene dependencias estándar de C++.
- Se requiere un sistema operativo compatible con la compilación y ejecución de programas en C++.

### Uso del Programa:

1. Iniciar el programa y autenticarse con un usuario y contraseña válidos.
2. Utilizar las opciones del menú para registrar, consultar, modificar o eliminar hojas de vida, así como para gestionar usuarios del sistema.
