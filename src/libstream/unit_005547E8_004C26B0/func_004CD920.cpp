extern "C" int D_005A07E0;
extern "C" int D_005A07E4;
extern "C" int D_005A07E8;
extern "C" int D_005A07EC;
extern "C" int D_005A0810;

extern "C" void func_004CD920(void) {
    if (D_005A0810 == 3) {
        D_005A07EC = D_005A07E8;
    } else {
        int t = D_005A07E4;
        D_005A07E4 = D_005A07E0;
        D_005A07E0 = t;
        D_005A07EC = t;
    }
}
