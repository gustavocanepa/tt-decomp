extern "C" int D_005865D0;
extern "C" unsigned int func_002E4630(const unsigned int *ticks) {
    unsigned int v = ticks[0] / (D_005865D0 != 1 ? 100u : 160u);
    return v < 1000000000 ? v : 999999999;
}
