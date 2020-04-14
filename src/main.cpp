#include <math.h>
#include "CFenetre.h"

#include <iostream>
using namespace std;

double f(double x) {
    return sin(x);
}

int main() {
    //int min(-10), max(10);
    int zoom_y = 2; //compression en ordonnée
    int zoom_x = int(4*3.14); //compression en abscisse
    double precision = 0.001; //la precision augmente le nombre de points

    CFenetre maFenetre(800, 400);
    maFenetre.setOrigin(zoom_x/2, (zoom_y/2), zoom_x, zoom_y);
    maFenetre.afficherRectV2(zoom_x, zoom_y, RGB(255, 255, 255));
    maFenetre.afficherCourbe(f, precision, zoom_x, zoom_y, RGB(255, 0, 0));
    //donner le passage en argument de la fonction dans
    //le rapport

    cin.ignore();
    return 0;
}
