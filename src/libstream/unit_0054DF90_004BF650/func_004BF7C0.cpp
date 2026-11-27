/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
void func_004A59F0();
void func_004A5668(int);
int func_004DD030();
int func_004DD1A0(int);
}
struct Flag { int v; };
extern volatile Flag D_00598670, D_00598674;
extern int D_007772D8;
extern char D_00777200[];
extern "C" void func_004BF7C0() {
    if (D_00598670.v) {
        D_00598670.v = 0;
        D_00598674.v = 0;
        func_004A5668(D_007772D8);
        int i = 0;
        int ready = 1;
        int off = 0;
        do {
            int *p = (int *)(D_00777200 + off);
            while (func_004DD1A0(*p) != ready) func_004A59F0();
            i++;
            off += 0x6C;
        } while (i < 2);
        while (func_004DD030() != 1) func_004A59F0();
    }
}
