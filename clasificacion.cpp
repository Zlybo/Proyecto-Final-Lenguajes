//
// Created by andre on 22/11/2022.
//

#include "clasificacion.h"

Clase::Clase(string _tipo, string _texto, int _posicion) {
    tipo = _tipo;
    texto = _texto;
    posicion = _posicion;
}

Clase::~Clase() = default;

string Clase::getTipo() {
    return tipo;
}

string Clase::getTexto() {
    return texto;
}

int Clase::getPosicion() {
    return posicion;
}

void Clase::setTipo(string tipo) {
    Clase::tipo = tipo;
}

void Clase::setTexto(string texto) {
    Clase::texto = texto;
}

void Clase::setPosicion(int posicion) {
    Clase::posicion = posicion;
}


