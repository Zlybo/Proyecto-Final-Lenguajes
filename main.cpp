
// Codigo hecho con Clion de NetBeans
// Si se va a compilar con g++ desde el cmd, cambiar # include "clasificacion.h" a "clasificacion.cpp"
// Por alguna extraña razon (ya que funciona y deja de fucionar sin que yo modifique el codigo),
// algunas veces no carga los archivos txt cuando se compila con g++
# include "clasificacion.h"

# include <iostream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <fstream>

using namespace std;

// no pude agregar la Ñ y las tildes

// retorna True si la palabra está en el archivo de texto
bool buscar(string n_archivo, string buscar) {
    ifstream archivo(n_archivo);
    string linea;
    while (getline(archivo, linea)) {
        if (linea == buscar) {
            return true;
        }
    }
    return false;
}

int main() {
    string prueba;
    cout << "Ingrese una oracion: " << endl;
    getline(cin, prueba);

    // Convertir la string en minúsculas
    string minusculas;
    for (char i: prueba) {
        minusculas.push_back(tolower(i));
    }

    // Dividir la string y poner cada parte en una lista
    vector<string> composicion;
    istringstream entrada(minusculas);
    string txt_auxiliar;
    while (getline(entrada, txt_auxiliar, ' ')) {
        composicion.push_back(txt_auxiliar);
    }
    //----------------------------------------------------------------------------------------
    // Clasificar la lista


    string txt_sujeto;
    int nums_sujetos = 0;
    int nums_verbos = 0;
    string txt_predicado;

    bool valido = true;

    Clase predicado("Predicado", "", 99);
    Clase sujeto("Sujeto", "", 99);
    Clase verbo("Verbo", "", 99);

    // Recorremos la oración
    for (int i = 0; i < composicion.size(); i++) {
        // Cuando un sujeto es más de una palabra cada palabra se suma a la variable txt_sujeto para luego pasársela al sujeto
        txt_sujeto = composicion[i];
        //Sujetos
        if (nums_sujetos == 0) {
            // Sujetos con artículos
            if (i == 0 && buscar("Articulos.txt", composicion[i])) {
                // Cuando una oración empieza con un artículo, la siguiente palabra hace parte del sujeto
                // Solucionar: La casa de mi mamá es muy grande
                txt_sujeto.append(" " + composicion[i + 1]);
                i = i + 2; // Saltamos lo que ya se clasificó

                if (composicion[i] == "de" || (composicion[i] == "de mi") || (composicion[i] == "y") ||
                    (composicion[i] == "y su") || (composicion[i] == "o") || (composicion[i] == "e")) {
                    txt_sujeto.append(" " + composicion[i] + " " + composicion[i + 1]);
                    i = i + 2;
                }
                // Pasamos los valores al objeto
                sujeto.setPosicion(i - 1); // i-1 = posición actual
                sujeto.setTexto(txt_sujeto);
                nums_sujetos = 1;
            }
                // Todos los pronombres al incio de la oración son sujetos
            else if (i == 0 && buscar("Pronombres.txt", composicion[i])) {
                sujeto.setPosicion(i);
                sujeto.setTexto(sujeto.getTexto() + " " + composicion[i]);
                nums_sujetos = 1;
                i = i + 1;
            }

                // Si ninguna condición anterior se cumple, el sujeto es un sustantivo o un nombre o un apellido
            else if (buscar("Sustantivos.txt", composicion[i]) ||
                     buscar("Nombres_Propios.txt", composicion[i]) ||
                     buscar("Apellidos.txt", composicion[i])) {
                if (composicion[i + 1] == "y") {
                    txt_sujeto += " " + composicion[i + 1] + " " + composicion[i + 2];
                    i = i + 2;
                }
                sujeto.setPosicion(i);
                sujeto.setTexto(txt_sujeto);
                nums_sujetos = 1;
                i = i + 1;
            }
        }

        if (buscar("Verbos_Conjugados.txt", composicion[i])) {
            // Si hay mas de 2 verbos, break
            if (nums_verbos == 1) {
                cout << "Oracion Invalida" << endl;
                valido = false;
                break;
            }
            verbo.setTexto(composicion[i]);
            verbo.setPosicion(i);
            nums_verbos = 1;
            i = i + 1;
        }

        if (i > composicion.size() - 1) {
            break;
        }

        // Lo que no se haya clasificado se convierte en predicado
        if (buscar("Verbos_Copulativo_Conjugados.txt", composicion[i])) {
            cout << "Oracion Invalida" << endl;
            valido = false;
            break;
        }
        predicado.setPosicion(i);
        txt_predicado.append(composicion[i] + " ");
    }
    predicado.setTexto(txt_predicado);
    cout << sujeto.getTexto() << " -" << sujeto.getTipo() << endl;
    cout << verbo.getTexto() << " -" << verbo.getTipo() << endl;
    cout << predicado.getTexto() << " -" << predicado.getTipo() << endl;

    if (valido) {
        if (sujeto.getPosicion() < verbo.getPosicion() && verbo.getPosicion() < predicado.getPosicion()) {
            cout << "Oracion simple valida" << endl;
        } else {
            cout << "Oracion invalida" << endl;
        }
    }

}

// Si después del verbo esta alguna palabra perteneciente al nucleo copulativo break;