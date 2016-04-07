from numpy.polynomial.legendre import leggauss

with open('gausscoeff.h', 'w') as f:
    f.write('#ifndef __TRIINT_GAUSS_H__\n#error "This file should not be included directly"\n#endif\n')
    for d in range(1, 51):
        x, w = leggauss(d)
        x = (1 + x) / 2
        w = w / 2
        for i in range(len(w)):
            f.write('template<> struct GaussQuadCoeff<%d,%d> { constexpr ' % (d, i))
            f.write('static double node = %.18e, weight = %.18e; };\n' % (x[i], w[i]))
        f.write('\n')
