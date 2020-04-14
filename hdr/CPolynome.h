#ifndef DEF_CPOLYNOME
#define DEF_CPOLYNOME

#include <iostream>

class CPolynome {
public:
    CPolynome(int nbcoeff);
    ~CPolynome();

    double calcule(double const& x);

    void afficher() const;
    void saisirCoeff();

    friend std::ostream& operator<<(std::ostream& out, CPolynome const& self);
    friend std::istream& operator>>(std::istream& in, CPolynome & self);

private:

    double* m_coeff; //m_coeff
    int m_nc; //nombre de coeff
};

#endif