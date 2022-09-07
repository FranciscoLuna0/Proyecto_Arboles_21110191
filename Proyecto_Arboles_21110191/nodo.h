#pragma once
#pragma once
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


class nodo {
public:
    int dato;
    nodo* izquierda;
    nodo* derecha;
    int altura;
};

int max(int a, int b);

int Altura(nodo* N) {
    if (N == nullptr)
        return 0;
    return N->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

nodo* newNode(int key) {
    nodo* node = new nodo();
    node->dato = key;
    node->izquierda = NULL;
    node->derecha = NULL;
    node->altura = 1;
    return (node);
}

nodo* rightRotate(nodo* D) {
    nodo* I = D->izquierda;
    nodo* T2 = I->derecha;
    I->derecha = D;
    D->izquierda = T2;
    D->altura = max(Altura(D->izquierda),
        Altura(D->derecha)) +
        1;
    I->altura = max(Altura(I->izquierda),
        Altura(I->derecha)) +
        1;
    return I;
}

nodo* leftRotate(nodo* I) {
    nodo* D = I->derecha;
    nodo* T = D->izquierda;
    D->izquierda = I;
    I->derecha = T;
    I->altura = max(Altura(I->izquierda),
        Altura(I->derecha)) +
        1;
    D->altura = max(Altura(D->izquierda),
        Altura(D->derecha)) +
        1;
    return D;
}

int getBalanceFactor(nodo* N) {
    if (N == NULL)
        return 0;
    return Altura(N->izquierda) -
        Altura(N->derecha);
}

nodo* insertNode(nodo* node, int dato) {
    if (node == NULL) {
        return (newNode(dato));
        cout << "Creo el nodo " << dato << endl;
    }
    if (dato < node->dato) {
        node->izquierda = insertNode(node->izquierda, dato);
    }

    else if (dato > node->dato) {
        node->derecha = insertNode(node->derecha, dato);
    }
    else
        return node;

    node->altura = 1 + max(Altura(node->izquierda),
        Altura(node->derecha));

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
        if (dato < node->izquierda->dato) {
            return rightRotate(node);
        }

        else if (dato > node->izquierda->dato) {
            node->izquierda = leftRotate(node->izquierda);
            return rightRotate(node);
        }
    }

    if (balanceFactor < -1) {
        if (dato > node->derecha->dato) {
            return leftRotate(node);
        }
        else if (dato < node->derecha->dato) {
            node->derecha = rightRotate(node->derecha);
            return leftRotate(node);
        }
    }

    return node;
}

nodo* nodeWithMimumValue(nodo* node) {
    nodo* current = node;
    while (current->izquierda != NULL)
        current = current->izquierda;
    return current;
}

nodo* deleteNode(nodo* raiz, int dato) {
    if (raiz == nullptr)
        return raiz;
    if (dato < raiz->dato)
        raiz->izquierda = deleteNode(raiz->izquierda, dato);
    else if (dato > raiz->dato)
        raiz->derecha = deleteNode(raiz->derecha, dato);
    else {
        if ((raiz->izquierda == NULL) ||
            (raiz->derecha == NULL)) {
            nodo* temp = raiz->izquierda ? raiz->izquierda : raiz->derecha;
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            }
            else
                *raiz = *temp;
            free(temp);
        }
        else {
            nodo* temp = nodeWithMimumValue(raiz->derecha);
            raiz->dato = temp->dato;
            raiz->derecha = deleteNode(raiz->derecha,
                temp->dato);
        }
    }

    if (raiz == NULL)
        return raiz;

    raiz->altura = 1 + max(Altura(raiz->izquierda),
        Altura(raiz->derecha));
    int balanceFactor = getBalanceFactor(raiz);
    if (balanceFactor > 1) {
        if (getBalanceFactor(raiz->izquierda) >= 0) {
            return rightRotate(raiz);
        }
        else {
            raiz->izquierda = leftRotate(raiz->izquierda);
            return rightRotate(raiz);
        }
    }
    if (balanceFactor < -1) {
        if (getBalanceFactor(raiz->derecha) <= 0) {
            return leftRotate(raiz);
        }
        else {
            raiz->derecha = rightRotate(raiz->derecha);
            return leftRotate(raiz);
        }
    }
    return raiz;
}

void preOrden(nodo* raiz)
{
    if (raiz != NULL)
    {
        cout << raiz->dato << " ";
        preOrden(raiz->izquierda);
        preOrden(raiz->derecha);
    }
}

void enOrden(nodo* raiz)
{
    if (raiz != NULL)
    {
        enOrden(raiz->izquierda);
        cout << raiz->dato << " ";
        enOrden(raiz->derecha);
    }
}

void postOrden(nodo* Raiz)
{
    if (Raiz != NULL)
    {
        postOrden(Raiz->izquierda);
        postOrden(Raiz->derecha);
    }
}


void MostrarArbol_Vistachida(nodo* arbol, int contador)
{
    if (arbol == NULL) {
        if (contador == 0) {
            cout << "\n\n\tArbol vacio\n\n";
        }
        return;
    }
    else
    {
        MostrarArbol_Vistachida(arbol->derecha, contador + 1);
        for (int i = 0; i < contador; i++)
        {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        MostrarArbol_Vistachida(arbol->izquierda, contador + 1);
    }
}
