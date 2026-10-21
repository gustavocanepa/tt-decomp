/* compiler: ee-gcc2.9-991111 */
typedef struct N { struct N *next; char pad[0x20]; unsigned start; unsigned a; unsigned b; unsigned c; } N;
extern N *D_0077A040;
int func_005038D8(void);
int func_00503928(void);

N *func_004D4630(unsigned addr) {
    int intr = func_005038D8();
    N *n;
    for (n = D_0077A040; n != 0; n = n->next) {
        unsigned s = n->start;
        if (addr >= s) {
            unsigned c = n->c;
            unsigned b = n->b;
            unsigned a = n->a;
            unsigned t = s + c;
            unsigned u = b + a;
            if (addr < t + u) {
                if (intr) func_00503928();
                return n;
            }
        }
    }
    if (intr) func_00503928();
    return 0;
}
