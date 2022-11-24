# include <iostream>

using namespace std;

class Clase {
private:
    string tipo;
    string texto;
    int posicion;

public:
    Clase(string, string, int);

    ~Clase();

    string getTipo();

    string getTexto();

    int getPosicion();

    void setTipo(string tipo);

    void setTexto(string texto);

    void setPosicion(int posicion);
};