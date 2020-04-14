#include <math.h>
#include "CFenetre.h"
#include "CPolynome.h"

#include <iostream>
using namespace std;

double f(double x) {
    return sin(x);
}

double g(double x) {
    return cos(x);
}

int main() {

    CPolynome monPoly(4);
    cin >> monPoly;
    cout << monPoly << endl;
    

    double precision = 0.01; //la precision augmente le nombre de points

    CFenetre maFenetre1(200, 200, 3.14*6, 4, 9, 2);
    maFenetre1.setRectOffset(300, 10);   //expliquer dans le rapport que c'est juste un ajout
                                        //de m_rox et m_roy dans tous les SetOffset

    maFenetre1.afficherRectV2(RGB(255, 255, 255));
    maFenetre1.afficherCourbe(f, precision, RGB(255, 0, 0));
    maFenetre1.afficherCourbe(g, precision, RGB(0, 255, 0));
    maFenetre1.afficherIntervalles();

    precision = 0.001;
    CFenetre maFenetre2(200, 200, 4, 4, 1, 3);
    maFenetre2.setRectOffset(510, 10);
    maFenetre2.afficherRectV2(RGB(255, 255, 255));
    maFenetre2.afficherPolynome(monPoly, precision, RGB(0,0,255));
    maFenetre2.afficherIntervalles();
    //donner le passage en argument de la fonction dans
    //le rapport

    cin.get(); cin.get(); //pause la console
    return 0;
}
