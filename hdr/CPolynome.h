#ifndef DEF_CPOLYNOME
#define DEF_CPOLYNOME

class CPolynome {
public:
    CPolynome();
    ~CPolynome();

private:

    double* m_coeff; //m_coeff
    int m_nc; //nombre de coeff
};

#endif