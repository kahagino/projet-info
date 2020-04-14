#ifndef DEF_CFENETRE
#define DEF_CFENETRE

#include <windows.h>

class CFenetre {
public:
    CFenetre(int rect_x, int rect_y);

    void afficherRectV2(int const& zoom_x, int const& zoom_y, COLORREF const& COULEUR) const;
    void afficherCourbe(double (*f)(double), double const& precision, int const& zoom_x, int const& zoom_y,
                        COLORREF const& COULEUR) const;
    void setOrigin(int const& x, int const& y, int const& zoom_x, int const& zoom_y);

private:
    HDC m_monDC;
    int m_rectx, m_recty;
    int m_offsetx, m_offsety;
};

#endif