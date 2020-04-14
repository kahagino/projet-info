#include <math.h>
#include "CFenetre.h"
#include "CPolynome.h"

#include <iostream>
using namespace std;

double f(double x) {
    return pow(x,2); //x^2
}

int main() {

    CPolynome monPoly(1); //création d'un polynome de degré 3
    cin >> monPoly; //l'utilisateur rentre les coeffs
    cout << monPoly << endl; //on affiche le polynôme

    CFenetre maFenetre(200, 200, 6, 6, 3, 5); //création d'une fenêtre de taille 200x200
    
    //placement de la fenêtre dans la console (optionnel)
    maFenetre.setRectOffset(10, 240);

    maFenetre.afficherRectV2(RGB(255, 255, 255)); //affichage des graduations
    maFenetre.afficherPolynome(monPoly, 0.001, RGB(255,0,0));



    CPolynome monPoly2(3); //création d'un polynome de degré 3
    cin >> monPoly2; //l'utilisateur rentre les coeffs
    cout << monPoly2 << endl; //on affiche le polynôme

    CFenetre maFenetre2(200, 200, 6, 6, 3, 5); //création d'une fenêtre de taille 200x200
    
    //placement de la fenêtre dans la console (optionnel)
    maFenetre2.setRectOffset(220, 240);

    maFenetre2.afficherRectV2(RGB(255, 255, 255)); //affichage des graduations
    maFenetre2.afficherPolynome(monPoly2, 0.001, RGB(255,0,0));



    CPolynome monPoly3(4); //création d'un polynome de degré 3
    cin >> monPoly3; //l'utilisateur rentre les coeffs
    cout << monPoly3 << endl; //on affiche le polynôme

    CFenetre maFenetre3(200, 200, 6, 6, 3, 3); //création d'une fenêtre de taille 200x200
    
    //placement de la fenêtre dans la console (optionnel)
    maFenetre3.setRectOffset(430, 240);

    maFenetre3.afficherRectV2(RGB(255, 255, 255)); //affichage des graduations
    maFenetre3.afficherPolynome(monPoly3, 0.001, RGB(255,0,0));

    maFenetre3.afficherIntervalles();



    cin.get(); cin.get(); //pause la console
    return 0;
}
