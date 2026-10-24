/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct N { int mode; N *f4; };
extern char D_00601538[];
extern "C" void *func_0043D3E0(void *, void *) throw();
extern "C" int func_004415A8(void *);
extern "C" int func_00442358(void *, void *, void *, int);
extern "C" int func_00443688(void *, void *, void *, int);
extern "C" void *func_00447FB0(void *, void *);
extern "C" void *func_00448048(void *, void *);
extern "C" int func_004A8368(const char *) throw();
extern "C" int func_005507D8(void *, const char *, u32, u32);

extern "C" int func_0043E388(N *n, void *a1, void *a2, int flag) {
    switch (n->mode) {
    case 7: {
        void *v;
        if (flag) {
            v = func_00448048((char *)n->f4 + 4, a1);
            func_0043D3E0(v, a2);
            return 1;
        } else {
            v = func_00447FB0((char *)n->f4 + 4, a1);
            if (!v) return 0;
        }
        func_0043D3E0(v, a2);
        return 1;
    }
    case 13: {
        if (func_005507D8(a1, D_00601538, 0, func_004A8368(D_00601538)) != 0) return 0;
        void *v = (void *)func_004415A8(n->f4);
        func_0043D3E0(v, a2);
        return 1;
    }
    case 10:
        return func_00442358((char *)n + 4, a1, a2, flag);
    case 11:
        return func_00443688((char *)n + 4, a1, a2, flag);
    default:
        return 0;
    }
}
