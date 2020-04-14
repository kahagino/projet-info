#include <windows.h>
#include <math.h>
#include <iostream>

using namespace std;

void drawRect(HDC& monDC, int& rect_x, int& rect_y, int& offset_x, int& offset_y, int& min, int& max, int& zoom_y, COLORREF& COULEUR)
{
    for(int m = 0; m < max-min; m++) //graduation abscisse
    {
        for(int m2 = 0; m2 <= rect_y; m2++) //grande graduation
            SetPixel(monDC, m*(rect_x/(max-min)), m2, RGB(100,100,100));

        for(int m1 = -3; m1 <= 3; m1++) //epaisseur de la petite graduation
            SetPixel(monDC, m*(rect_x/(max-min)), offset_y + m1, COULEUR);
    }


    for(int n = 0; n < zoom_y; n++) //graduation abscisse
    {
        for(int n2 = 0; n2 <= rect_x; n2++) //grande graduation
            SetPixel(monDC, n2, n*(rect_y/(zoom_y)), RGB(100,100,100));

        for(int n1 = -3; n1 <= 3; n1++) //epaisseur de la graduation
            SetPixel(monDC, offset_x + n1, n*(rect_y/(zoom_y)), COULEUR);
    }

    for(int i = 0; i < rect_x; i++) //partie haute et basse
    {
        SetPixel(monDC, i, 0, COULEUR);
        SetPixel(monDC, i, rect_y, COULEUR);
    }

    for(int j = 0; j < rect_y; j++) //partie gauche et droite
    {
        SetPixel(monDC, 0, j, COULEUR);
        SetPixel(monDC, rect_x, j, COULEUR);
    }

    for(int k = 0; k < rect_x; k++) //axe des abscisses
    {
        SetPixel(monDC, k, offset_y, COULEUR);
    }

    for(int l = 0; l < rect_y; l++) //axe des ordonnées
    {
        SetPixel(monDC, offset_x, l, COULEUR);
    }
}

double f(double x) {
    return 0.01*pow(x, 3);
}

int main() {

    //initialisation de la console
    HWND fenetreConsole = GetConsoleWindow();
    HDC monDC = GetDC(fenetreConsole);

    //choix de la couleur
    COLORREF COULEUR = RGB(255,255,255); 

    int offset_x, offset_y, rect_x, rect_y, min, max;
    rect_x = 800; rect_y = 400;
    offset_x = int(rect_x/2); offset_y = int(rect_y/2);

    min = -20; max = 20;
    int zoom_y = 20; //compression en ordonnée

    drawRect(monDC, rect_x, rect_y, offset_x, offset_y, min, max, zoom_y, COULEUR);

    double precision = 0.01; //la precision augmente le temps de calcule

    for(double x = min; x < max; x+=precision)
    {
        int yC = -(offset_y + int((rect_y/zoom_y*(f(x))))) + rect_y; //le - pour inverser la courbe
        if((offset_x + ((rect_x/(max-min)*x)) < rect_x && yC < rect_y))
            //on n'affiche pas la courbe en dehors du cadre
            SetPixel(monDC, offset_x + ((rect_x/(max-min)*x)), yC, COULEUR);
    }

    //affichage dans la console
    ReleaseDC(fenetreConsole, monDC);
    cin.ignore();
    return 0;
}
