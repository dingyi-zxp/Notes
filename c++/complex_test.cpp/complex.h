#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex;
complex &__doapl(complex *ths, const complex &r);
complex &__doami(complex *ths, const complex &r);
complex &__doamp(complex *ths, const complex &r);

class complex {
public:
  complex(double r = 0, double i = 0) : re(r), im(i) {}
  complex &operator+=(const complex &);
  complex &operator-=(const complex &);
  complex &operator*=(const complex &);
  complex &operator/=(const complex &);
  double real() const { return re; }
  double imag() const { return im; }

private:
  double re, im;

  friend complex &__doapl(complex *, const complex &);
  friend complex &__doaml(complex *, const complex &);
  friend complex &__doami(complex *, const complex &);
};

inline complex &__doapl(complex *ths, const complex &r) {
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}

inline complex &complex::operator+=(const complex &r) {
  return __doapl(this, r);
}

inline complex &__doami(complex *ths, const complex &r) {
  ths->im -= r.im;
  ths->re -= r.re;
  return *ths;
}

inline complex &complex::operator-=(const complex &r) {
  return __doami(this, r);
}

inline complex &__doaml(complex *ths, const complex &r) {
  double f = ths->re * r.re - ths->im * r.im;
  ths->im = ths->re * r.im + ths->im * r.re;
  ths->re = f;
  return *ths;
}

inline complex &complex::operator*=(const complex &r) {
  return __doaml(this, r);
}

inline double imag(const complex &x) { return x.imag(); }

inline double real(const complex &x) { return x.real(); }

inline complex operator+(const complex &x, const complex &y) {
  return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex operator+(double x, const complex &y) {
  return complex(x + real(y), imag(y));
}

inline complex operator+(const complex &x, double y) {
  return complex(real(x) + y, imag(x));
}
#endif
