/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pack { char pad[0xC]; void *mgr; };
struct Obj { int unk0; Pack *pack; int unk8; int cells[6][4]; };
extern "C" int func_00385B30(void *);
extern "C" int func_00385BB8(void *);
extern "C" int func_00379820(int, int);
extern "C" void func_0055A8B8(void *, int, int (*)(int, int));
extern "C" int func_003799F0(Obj *o) {
    if (func_00385B30(o)) {
        if (o->pack->mgr) {
            for (int i = 0; i < 6; i++) {
                int *base = (int *)((char *)o + 0xC);
                int *p = (int *)(i * 16 + (int)base);
                for (int j = 0; j < 4; j++) {
                    if (*p) {
                        func_0055A8B8(o->pack->mgr, *p, func_00379820);
                        *p = 0;
                    }
                    p++;
                }
            }
        }
    }
    return func_00385BB8(o);
}
