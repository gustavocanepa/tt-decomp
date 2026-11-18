/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ring { char pad00[0x24]; int base; int pad28; int head; int skip; int bias; int lock; };
extern int D_00776D44;
extern int D_00776D4C;
extern int D_00776D58;
extern int D_00776D5C;
extern "C" void func_004FA840(int);
extern "C" void func_004FA860(int);
extern "C" void func_004BDDE8(Ring *r, int *addr, int *len1, int *addr2, int *len2) {
    func_004FA860(r->lock);
    int off = (((r->head + r->skip) << D_00776D4C) + r->bias) & D_00776D5C;
    int avail = (((D_00776D44 - r->skip) - 2) << D_00776D4C) - r->bias;
    if (D_00776D58 - off >= avail) {
        *addr = r->base + off;
        *len1 = avail;
        *addr2 = 0;
        *len2 = 0;
    } else {
        *addr = r->base + off;
        *len1 = D_00776D58 - off;
        *addr2 = r->base;
        *len2 = avail - (D_00776D58 - off);
    }
    func_004FA840(r->lock);
}
