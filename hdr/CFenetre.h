#ifndef DEF_CFENETRE
#define DEF_CFENETRE

#include <windows.h>
#include <CPolynome.h>

class CFenetre {
public:
    //rect_x et rect_y : largeur et longueur de la fenêtre en pixel
    //zoom_x et zoom_y : amplitude en abscisse et ordonnée de la fenêtre
    //x et y : coordonnées de l'origine dans la base de zoom_x et zoom_y
    CFenetre(int rect_x, int rect_y, int zoom_x = 4, int zoom_y = 4, int x = 2, int y = 2);

    void afficherRectV2(COLORREF const& COULEUR) const;
    void afficherCourbe(double (*f)(double), double const& precision, COLORREF const& COULEUR) const;
    void afficherPolynome(CPolynome monPoly, double const& precision, COLORREF const& COULEUR) const;
    void afficherIntervalles() const;

    void setRectOffset(int const& x, int const& y);
    void setOrigin(int const& x, int const& y);
    void setAmplitude(int const& zoom_x, int const& zoom_y);

private:
    HDC m_monDC;
    int m_rectx, m_recty;
    int m_zoomy, m_zoomx;
    int m_offsetx, m_offsety;
    int m_rox, m_roy; //rectOffset
};

#endif