#include "CPolynome.h"

#include <iostream>
using namespace std;

CPolynome::CPolynome(int nbcoeff): m_nc(nbcoeff)
{
    m_coeff = new double[m_nc];
}

CPolynome::~CPolynome()
{
    delete[] m_coeff;
}

void CPolynome::afficher() const
{ 
    int puissance = m_nc - 1;
    for(int i = 0; i < m_nc; i++)
    {
        if(i < m_nc -2)
            cout << "(" << m_coeff[i] << ").x^" << puissance << " + ";
        else if(i == m_nc -2)
            cout << "(" << m_coeff[i] << ").x + ";
        else if(i == m_nc -1)
            cout << "(" << m_coeff[i] << ")";
        else
            cout << "?";
        
        puissance -= 1;
    }
}

void CPolynome::saisirCoeff()
{
    delete[] m_coeff; //on supprime les anciennes valeurs
    m_coeff = new double[m_nc];

    for(int i = 0; i < m_nc; i++) //on demande les nouveaux coeff
    {
        cout << "coeff " << i+1 << " ?> ";
        cin >> m_coeff[i];
    }
}

ostream& operator<<(ostream& out, CPolynome const& self)
{
    self.afficher();
    return out;
}

istream& operator>>(istream& in, CPolynome & self)
{
    self.saisirCoeff();
    return in;
}