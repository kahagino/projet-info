#include <math.h>
#include "CFenetre.h"
#include "CPolynome.h"

#include <iostream>
using namespace std;

double f(double x) {
    return pow(x,2); //x^2
}

int main() {

    CPolynome monPoly(4); //création d'un polynome de degré 3
    cin >> monPoly; //l'utilisateur rentre les coeffs
    cout << monPoly << endl; //on affiche le polynôme

    CFenetre maFenetre(200, 200); //création d'une fenêtre de taille 200x200
    
    //placement de la fenêtre dans la console (optionnel)
    maFenetre.setRectOffset(10, 240);

    maFenetre.afficherRectV2(RGB(255, 255, 255)); //affichage des graduations
    maFenetre.afficherPolynome(monPoly, 0.001, RGB(255,0,0));

    maFenetre.afficherIntervalles();



    cin.get(); cin.get(); //pause la console
    return 0;
}
