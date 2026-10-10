extern int D_00776D40;
extern int D_00776D44;
extern int D_00776D48;
extern int D_00776D4C;
extern int D_00776D50;
extern int D_00776D54;
extern int D_00776D58;
extern int D_00776D5C;

extern "C" void func_004BD8E8(int xbits, int ybits) {
    D_00776D40 = xbits;
    D_00776D4C = ybits;
    D_00776D44 = 1 << xbits;
    D_00776D48 = (1 << xbits) - 1;
    D_00776D50 = 1 << ybits;
    D_00776D54 = (1 << ybits) - 1;
    D_00776D58 = 1 << (ybits + xbits);
    D_00776D5C = (1 << (ybits + xbits)) - 1;
}
