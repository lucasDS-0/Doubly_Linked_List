#include "Lista.h"

Lista::Lista() : _longitud(0), _primptr(nullptr), _ultptr(nullptr) {}

Lista::Lista(const Lista& l) : Lista() {
    *this = l;
}

Lista::~Lista() {
    Nodo* n = this->_primptr;
    while (n != nullptr) {
        this->_primptr = this->_primptr->_sigptr;
        delete n;
        n = this->_primptr;
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    int h = this->_longitud;
    for (int j = 0; j < h; ++j) {
        this->eliminar(0);
    }
    for (int i = 0; i < aCopiar._longitud; ++i) {
        this->agregarAtras(aCopiar.iesimo(i));
    }
    return *this;
}


void Lista::agregarAdelante(const int& elem) {
    this->_longitud++;
    Nodo* nuevo = new Nodo(elem);
    nuevo->_sigptr = this->_primptr;
    if (this->_primptr != nullptr) {
        this->_primptr->_antptr = nuevo;
    } else {
        this->_ultptr = nuevo;
    }
    this->_primptr = nuevo;
}

void Lista::agregarAtras(const int& elem) {
    this->_longitud++;
    Nodo* nuevo = new Nodo(elem);
    nuevo->_antptr = this->_ultptr;
    if (this->_ultptr != nullptr) {
        this->_ultptr->_sigptr = nuevo;
    } else {
        this->_primptr = nuevo;
    }
    this->_ultptr= nuevo;
}

void Lista::eliminar(Nat i) {
    this->_longitud--;
    Nodo* n = buscar(i);
    if (n->_antptr != nullptr) {
        n->_antptr->_sigptr = n->_sigptr;
    } else {
        this->_primptr = n->_sigptr;
    }
    if (n->_sigptr != nullptr) {
        n->_sigptr->_antptr = n->_antptr;
    } else {
        this->_ultptr = n->_antptr;
    }
    delete n;
}

int Lista::longitud() const {
    return this->_longitud;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* n = buscar(i);
    return n->_valor;
}

int& Lista::iesimo(Nat i) {
    Nodo* n = buscar(i);
    return n->_valor;
}

void Lista::mostrar(ostream& o) {
    o << "{";
    for (int i = 0; i < _longitud; i++) {
        o << this->iesimo(i) << ",";
    }
    o << "}";
}

Lista::Nodo::Nodo(const int &elem) : _antptr(nullptr), _valor(elem), _sigptr(nullptr) {}

Lista::Nodo::~Nodo() {}

Lista::Nodo* Lista::buscar(Nat elem) {
    Nodo* n = this->_primptr;
    while (elem != 0) {
        n = n->_sigptr;
        elem--;
    }
    return n;
}

Lista::Nodo* Lista::buscar(Nat elem) const{
    Nodo* n = this->_primptr;
    while (elem != 0) {
        n = n->_sigptr;
        elem--;
    }
    return n;
}
