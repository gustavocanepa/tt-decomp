/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E { short d; short pad; s32 (*fn)(void *); };
struct VObj { char pad[4]; char *vt; };
struct H { VObj *p; char pad[0xC]; };
struct Ev { char pad[0x20]; s32 key; };
struct M { char pad[0x118]; s32 fc; };
extern "C" s32 func_001E4EA0(char *);
extern "C" void *func_001E94D8(char *);
extern "C" s32 func_0020B6A0(void *, void *, void *);
extern "C" void func_00216BB0(void *, int);
extern "C" void func_00216FD8(void *, void *, void *);
extern "C" void func_0021EEF0(void *, int);
extern "C" void func_0021F318(void *, void *, void *);
extern "C" void func_0026B750(void *, void *) throw();
extern "C" s32 func_0026C2A8(void *, int);
extern "C" s32 func_0026BFA8(M *self, char *arg1, Ev *ev) {
    s32 key = ev->key;
    if (self->fc != 0) {
        s32 r = 0;
        if (key == 0xFF52 || key == 0xFF97)
            r = func_0026C2A8(self, -1);
        else if (key == 0xFF54 || key == 0xFF99)
            r = func_0026C2A8(self, 1);
        if (r != 0)
            func_0026B750(self, arg1);
        s32 w = func_001E4EA0(arg1);
        if (w != 0) {
            if (key == 0xFF0D) {
                H h;
                func_00216FD8(&h, arg1, func_001E94D8((char *)w));
                E *e = (E *)(h.p->vt + 0x1B0);
                e->fn((char *)h.p + e->d);
                func_00216BB0(&h, 2);
            } else if (key == 0xFF1B) {
                H h;
                func_0021F318(&h, arg1, func_001E94D8((char *)w));
                E *e = (E *)(h.p->vt + 0x1B0);
                e->fn((char *)h.p + e->d);
                func_0021EEF0(&h, 2);
            }
        }
        return 2;
    }
    return func_0020B6A0(self, arg1, ev);
}
