#include "CFenetre.h"
#include <iostream>
#include <math.h>
using namespace std;

CFenetre::CFenetre(int rect_x, int rect_y, int zoom_x, int zoom_y, int x, int y):
m_rectx(rect_x), m_recty(rect_y)
{
    //initialisation de la console
    HWND fenetreConsole = GetConsoleWindow();
    m_monDC = GetDC(fenetreConsole);

    setAmplitude(zoom_x, zoom_y);
    setOrigin(x, y);
}

void CFenetre::afficherRectV2(COLORREF const& COULEUR) const
{
    double intervalx = (double)m_rectx/m_zoomx; //on converti en double pour eviter les décalages dû aux arrondies
    double intervaly = (double)m_recty/m_zoomy; //SetPixel gère tout seul le cas des coordonnées en double

    for(int m = 0; m <= m_zoomx; m++) //graduation abscisse
    {
        for(int m2 = 0; m2 <= m_recty; m2++) //grande graduation
            SetPixel(m_monDC, m*intervalx, m2, RGB(100,100,100));

        for(int m1 = -3; m1 <= 3; m1++) //epaisseur de la petite graduation
            SetPixel(m_monDC, m*intervalx, m_offsety + m1, COULEUR);
    }


    for(int n = 0; n <= m_zoomy; n++) //graduation abscisse
    {
        for(int n2 = 0; n2 <= m_rectx; n2++) //grande graduation
            SetPixel(m_monDC, n2, n*intervaly, RGB(100,100,100));

        for(int n1 = -3; n1 <= 3; n1++) //epaisseur de la graduation
            SetPixel(m_monDC, m_offsetx + n1, n*intervaly, COULEUR);
    }

    for(int i = 0; i <= m_rectx; i++) //partie haute et basse
    {
        SetPixel(m_monDC, i, 0, COULEUR);
        SetPixel(m_monDC, i, m_recty, COULEUR);
    }

    for(int j = 0; j <= m_recty; j++) //partie gauche et droite
    {
        SetPixel(m_monDC, 0, j, COULEUR);
        SetPixel(m_monDC, m_rectx, j, COULEUR);
    }

    for(int k = 0; k < m_rectx; k++) //axe des abscisses
    {
        SetPixel(m_monDC, k, m_offsety, COULEUR);
    }

    for(int l = 0; l < m_recty; l++) //axe des ordonnées
    {
        SetPixel(m_monDC, m_offsetx, l, COULEUR);
    }
}

void CFenetre::afficherCourbe(double (*f)(double), double const& precision, COLORREF const& COULEUR) const
{
    double intervalx = (double)m_rectx/m_zoomx;
    double intervaly = (double)m_recty/m_zoomy;
    double xmin = (-m_offsetx)/(intervalx);
    double xmax = (m_rectx - m_offsetx)/(intervalx);

    double ymin = (-m_offsety)/(intervaly);
    double ymax = (m_recty - m_offsety)/(intervaly);

    cout << "Dx[" << xmin << ";" << xmax << "]";
    cout << "Dy[" << ymin << ";" << ymax << "]" << " ";

    for(double x = xmin; x < xmax; x+=precision)
    {
        int yC = -(m_offsety + intervaly*f(x)) + 2*m_offsety; //le - pour inverser la courbe
        if((m_offsetx + ((m_rectx/(xmax-xmin)*x)) < m_rectx && yC < m_recty))
            //on n'affiche pas la courbe en dehors du cadre
            SetPixel(m_monDC, m_offsetx + ((m_rectx/(xmax-xmin)*x)), yC, COULEUR);
    }
}

void CFenetre::setOrigin(int const& x, int const& y)
{
    m_offsetx = x * (double)m_rectx/m_zoomx; //car floor est utilisé dans SetPixel
    m_offsety = y * (double)m_recty/m_zoomy; //on veut que tout s'aligne parfaitement
}

void CFenetre::setAmplitude(int const& zoom_x, int const& zoom_y)
{
    m_zoomx = zoom_x;
    m_zoomy = zoom_y;
}