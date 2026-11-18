/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { int f0; char pad[0x60]; int f64; };
extern int D_0059836C;
extern Blk *D_0059834C;
extern volatile int D_00598354, D_00598358;
extern int D_00598364;
extern "C" void func_004A5668(int);
extern "C" void func_004AEB30(void *);
extern "C" void func_004AE9F0(void *, int);
extern "C" void func_0050E1A8(void *) throw();
extern "C" void func_004BA3A8(void) {
    if (D_0059836C != 0) {
        Blk *b = D_0059834C;
        if (b != 0) {
            D_00598354 = 0;
            (void)D_00598354;
            D_00598358 = 1;
            (void)D_00598358;
            func_004A5668(D_00598364);
            b->f64 = 1;
            func_004AEB30((char *)b + 4);
            func_004A5668(b->f0);
            Blk *d = D_0059834C;
            if (d != 0) {
                func_004AE9F0((char *)d + 0x34, 2);
                func_004AE9F0((char *)d + 4, 2);
                func_0050E1A8(d);
            }
            D_0059834C = 0;
        }
        D_0059836C = 0;
    }
}
