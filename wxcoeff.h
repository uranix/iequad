#ifndef __IEQUAD_WANDZURAXIAO_H__
#error "This file should not be included directly"
#endif

template <class Function, typename Ret>
struct TriQuad<5, Function, Ret> {
    static Ret eval(const Function &f) {
        return TriQuadHelper<Function, Ret>::pointA(0.2250000000000000E+00, f)
           + TriQuadHelper<Function, Ret>::pointB(0.1323941527885062E+00, f, 0.05971587178977)
           + TriQuadHelper<Function, Ret>::pointB(0.1259391805448271E+00, f, 0.79742698535309);
    }
};
