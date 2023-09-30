# Tarea_2_ICI2244-1
![265290404-697cadcf-5b6e-4fd4-9301-baa3883555c3](https://github.com/MatiasPUCV/Tarea_2_ICI2244-1/assets/142541831/f7e25f5f-2a2a-4568-83e9-b1b9e08cd79a)

## Compilación:

Ejecute en el directorio:

`gcc -Iinclude -o Tarea1 src/main.c src/app.c src/csv.c src/hashmap.c src/list.c src/point.c src/turist.c src/util.c`

Tambien puede usar `compile.bat` o usar cmake.

## Información de uso:
**1. Registrar punto de interés** <char* nombre, char* tipo, char* dirección, char* horario, char* descripción>:

Se ingresa los datos del lugar y la aplicación los almacena.

**2. Mostrar datos de punto de interés** <char* nombre>:

Se ingresa el nombre del lugar y la aplicación muestra sus datos.

**3. Eliminar punto de interés** <char* nombre>:

Se ingresa el nombre del lugar y la aplicación lo elimina.

**4. Registrar turista** <char* pasaporte, char* nombre, char* país>:

Se ingresa los datos del turista y la aplicación los almacena.

**5. Agregar lugar favorito a turista** <char* pasaporte, char* nombre_lugar>:

Se ingresa el pasaporte del turista y el nombre del lugar favorito agregar, y la aplicación lo agrega a la lista de lugares favoritos del turista.

**6. Mostrar turistas por país** <char* país>:

La aplicación muestra todos los turistas de un país específico.

**7. Mostrar todos los puntos de interés de un tipo** <char* tipo>:

La aplicación muestra todos los lugares de un tipo específico.

**8. Importar puntos de interés y turistas desde archivos CSV** <char* nombre_archivo_puntos, char* nombre_archivo_turistas>:

Se ingresa del archivo y la aplicación carga todos los puntos de interés o turistas, que contenga.

**9. Exportar puntos de interés y turistas a archivos CSV** <char* nombre_archivo_puntos, char* nombre_archivo_turistas>:

La aplicación exporta todos los puntos de interés o turistas, a un archivo CSV.

**0. Cerrar**:
Cierra la aplicación.

