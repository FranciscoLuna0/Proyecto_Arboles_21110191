
#include <iostream>
#include "nodo.h"

using namespace std;

int main() {
    nodo* Raiz = NULL;
    //int a = 1;
    //int b;

    Raiz = insertNode(Raiz, 5);
    Raiz = insertNode(Raiz, 4);
    Raiz = insertNode(Raiz, 8);
    Raiz = insertNode(Raiz, 6);
    Raiz = insertNode(Raiz, 7);
    Raiz = insertNode(Raiz, 9);


    //Raiz = insertNode(Raiz, 100);
    //Raiz = insertNode(Raiz, 40);
    //Raiz = insertNode(Raiz, 90);
    //Raiz = insertNode(Raiz, 60);
    //Raiz = insertNode(Raiz, 200);

    //do
    //{
    //    cout << "digite un nuevo dato" << endl;
    //    cin >>
    //    system("cls");
    //    MostrarArbol_Vistachida(Raiz, 0);
    //} while (a!=0);

    MostrarArbol_Vistachida(Raiz, 0);
    system("pause");


    return 0;

}