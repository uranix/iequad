#ifndef __IEQUAD_WANDZURAXIAO_H__
#error "This file should not be included directly"
#endif

template <class Function, typename Ret>
struct TriQuad<1, Function, Ret> {
    static Ret eval(const Function &f) {
        return
            TriQuadHelper<Function, Ret>::pointA(1, f);

    }
};

template <class Function, typename Ret>
struct TriQuad<7, Function, Ret> {
    static Ret eval(const Function &f) {
        return
            TriQuadHelper<Function, Ret>::pointA(2.2500000000000000000e-01, f) +
            TriQuadHelper<Function, Ret>::pointB(1.3239415278850618074e-01, f, 5.9715871789769820459e-02) +
            TriQuadHelper<Function, Ret>::pointB(1.2593918054482715260e-01, f, 7.9742698535308732240e-01);

    }
};

template <class Function, typename Ret>
struct TriQuad<25, Function, Ret> {
    static Ret eval(const Function &f) {
        return
            TriQuadHelper<Function, Ret>::pointA(0.83523399540026902926e-1, f) +
            TriQuadHelper<Function, Ret>::pointB(0.72298488128466752029e-2, f, 0.42691295549240855209e-2) +
            TriQuadHelper<Function, Ret>::pointB(0.74492177361922250921e-1, f, 0.14397510109010589058e00) +
            TriQuadHelper<Function, Ret>::pointB(0.78646473402942187142e-1, f, 0.63048717418853706180e00) +
            TriQuadHelper<Function, Ret>::pointB(0.69283234440482423945e-2, f, 0.95903756116111841241e00) +
            TriQuadHelper<Function, Ret>::pointC(0.29518320704305576220e-1, f, 0.35002990071648349458e-1, 0.13657357812364578407e00) +
            TriQuadHelper<Function, Ret>::pointC(0.39579367861476928795e-1, f, 0.37549070235634689129e-1, 0.33274360477852998920e00);
    }
};

template <class Function, typename Ret>
struct TriQuad<54, Function, Ret> {
    static Ret eval(const Function &f) {
        return
            TriQuadHelper<Function, Ret>::pointB(0.03266181884880487944015733, f, 0.08343840726174951337926754) +
            TriQuadHelper<Function, Ret>::pointB(0.02741281803136407747999023, f, 0.1927790708417376065700458) +
            TriQuadHelper<Function, Ret>::pointB(0.02651003659870316413724953, f, 0.4136056641739479382342145) +
            TriQuadHelper<Function, Ret>::pointB(0.02921596213648582266278810, f, 0.7070644261144502788461565) +
            TriQuadHelper<Function, Ret>::pointB(0.01058460806624409265038093, f, 0.8872742646687885890741947) +
            TriQuadHelper<Function, Ret>::pointB(0.003614643064092248961124457, f, 0.9668497462832582770250640) +
            TriQuadHelper<Function, Ret>::pointC(0.008527748101709749852456852, f, 0.009912203309225319947739701, 0.2395345541547933627666385) +
            TriQuadHelper<Function, Ret>::pointC(0.01391617651669196596278336, f, 0.01580377063022797818417254, 0.4048788073183394387680162) +
            TriQuadHelper<Function, Ret>::pointC(0.004291932940735345710753166, f, 0.005143608816972343955782598, 0.09500211311304568929075565) +
            TriQuadHelper<Function, Ret>::pointC(0.01623532928177478632639143, f, 0.04892232575299109018246637, 0.1497531073222761544791834) +
            TriQuadHelper<Function, Ret>::pointC(0.02560734092126235158453251, f, 0.06876874863252026073604032, 0.2869196124413362389800618) +
            TriQuadHelper<Function, Ret>::pointC(0.03308819553164532456390407, f, 0.1684044181247004319852044, 0.2818356680990855509099574);
    }
};

template <class Function, typename Ret>
struct TriQuad<85, Function, Ret> {
    static Ret eval(const Function &f) {
        return
            TriQuadHelper<Function, Ret>::pointA(0.02761042699769986125371772, f) +
            TriQuadHelper<Function, Ret>::pointB(0.001779029547325768172889825, f, 0.001500649324426812977145314) +
            TriQuadHelper<Function, Ret>::pointB(0.02011239811396189072589557, f, 0.09413975193895103237696369) +
            TriQuadHelper<Function, Ret>::pointB(0.02681784725933198398727393, f, 0.2044721240895240945603982) +
            TriQuadHelper<Function, Ret>::pointB(0.02452313380150304805205394, f, 0.4709995949344254874104249) +
            TriQuadHelper<Function, Ret>::pointB(0.01639457841069627151642705, f, 0.5779620718158562030002023) +
            TriQuadHelper<Function, Ret>::pointB(0.01479590739864941186032032, f, 0.7845287856574675544921337) +
            TriQuadHelper<Function, Ret>::pointB(0.004579282277704168009376194, f, 0.9218618243243983548394277) +
            TriQuadHelper<Function, Ret>::pointB(0.001651826515576191130411715, f, 0.9776512405413409077181257) +
            TriQuadHelper<Function, Ret>::pointC(0.002349170908575258254234700, f, 0.005349618187335713593377049, 0.06354966590835294846955548) +
            TriQuadHelper<Function, Ret>::pointC(0.004465925754181586182715169, f, 0.007954817066198130114914115, 0.1571069189407119764022366) +
            TriQuadHelper<Function, Ret>::pointC(0.006099566807907726153723562, f, 0.01042239828126326231388974, 0.3956421143643884175537572) +
            TriQuadHelper<Function, Ret>::pointC(0.006891081327188528176341289, f, 0.01096441479612343877257965, 0.2731675707129195946370256) +
            TriQuadHelper<Function, Ret>::pointC(0.007997475072477819733932925, f, 0.03856671208545827802302128, 0.1017853824850143085305542) +
            TriQuadHelper<Function, Ret>::pointC(0.007386134285336477839258295, f, 0.03558050781721864432404949, 0.4466585491764043316571042) +
            TriQuadHelper<Function, Ret>::pointC(0.01279933187864785016506198, f, 0.04967081636276171920276112, 0.1990107941494998267566266) +
            TriQuadHelper<Function, Ret>::pointC(0.01725807117569639752266613, f, 0.05851972508433202934528848, 0.3242611836922793191413611) +
            TriQuadHelper<Function, Ret>::pointC(0.01867294590293502311690672, f, 0.1214977870043898217132618, 0.2085313632101273550757239) +
            TriQuadHelper<Function, Ret>::pointC(0.02281822405839565591888201, f, 0.1407108449439385250919129, 0.3231705665362529318970738);
    }
};
