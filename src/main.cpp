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

    CPolynome monPoly(2);
    cin >> monPoly;
    cout << monPoly << endl;
    /*
    double precision = 0.001; //la precision augmente le nombre de points

    CFenetre maFenetre(400, 400);
    
    maFenetre.afficherRectV2(RGB(255, 255, 255));
    maFenetre.afficherCourbe(f, precision, RGB(255, 0, 0));
    maFenetre.afficherCourbe(g, precision, RGB(0, 255, 0));
    //donner le passage en argument de la fonction dans
    //le rapport
    */

    //cin.ignore(); //pause la console
    return 0;
}
