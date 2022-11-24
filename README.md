# Proyecto-Final-Lenguajes

Codigo hecho con Clion de NetBeans

Version: C++ 14

Integrantes: Andrés Julián Gil Nagles

Video desmotracion: https://youtu.be/dmpP99Bw1Z0

Importante:

- En la carpeta "cmake-build-debug" estan las listas utilizadas como archivos.txt

- El programa no funciona correctamente si se le agrega una ñ o alguna tilde.

- Los pronombres "tu" y "el" con minusculas se usan en su version de pronombre personal (tú y él)

- Si se va a compilar con g++ desde el cmd, descargar todo tal cual y si presenta algun error de compilacion debe entrar al archivo main.cpp y cambiar # include "clasificacion.h" a "clasificacion.cpp"

- Por alguna extraña razon (ya que funciona y deja de fucionar sin que yo modifique el codigo), algunas veces no carga los archivos txt cuando se compila con g++ preferible usar Clion o replit

Descripcion:

El programa recibe una oracion y la clasifica por su sujeto, verbo y predicado para luego verificar si esta escrita de la forma SUJETO + VERBO + PREDICADO dando error cuando el sujeto y el verbo se escriben después del predicado, cuando una oracion tiene 2 o mas verbos y con oraciones con predicados con núcleo copulativo compuesto ( ser, estar parecer) 

Ejemplo:

Oracion: La cancha de futbol tiene muchos huecos

la cancha de futbol -Sujeto

tiene -Verbo

muchos huecos  -Predicado

Oracion simple valida
