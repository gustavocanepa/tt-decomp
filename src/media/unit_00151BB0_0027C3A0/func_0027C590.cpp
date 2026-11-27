#include "types.h"

struct Handle {
    void *p;
    char pad[0xC];
};

extern "C" void func_0027BE98(void *arg0, int arg1);
extern "C" void func_0027BEF0(void *arg0, void *arg1);
extern "C" void func_0027DF48(void *arg0, void *arg1, char *arg2);
extern "C" void func_001DF1F8(void *arg0, int arg1);
extern "C" void func_001DF250(void *arg0, void *arg1);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029CF48(void *arg0, void *arg1);
extern "C" char *func_0029E9F0(void *arg0);

extern "C" void func_0027C590(void *arg0, void *arg1, s32 n, void **args) {
    if (n >= 2) {
        Handle h0;
        Handle b;
        Handle c;
        Handle *pb;
        Handle *pc;
        func_0027BEF0(&h0, arg1);
        pb = &b;
        func_001DF250(pb, args);
        pc = &c;
        func_0029CF48(pc, args + 1);
        {
            void *bp = pb->p;
            void *hp = h0.p;
            func_0027DF48(hp, bp, func_0029E9F0(pc->p));
        }
        func_0029CEF0(pc, 2);
        func_001DF1F8(pb, 2);
        func_0027BE98(&h0, 2);
    }
}
