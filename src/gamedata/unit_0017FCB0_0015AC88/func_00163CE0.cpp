typedef int s32;

struct Big {
    s32 d[0x96];
};

struct Inner {
    char pad[0x10];
    s32 p10;
};

struct Handle {
    Inner *p;
    char pad[0xC];
};

struct Src {
    char pad[0x10];
    Big b;
};

struct SrcHandle {
    Src *p;
    char pad[0xC];
};

static inline Inner *get(Handle *h) {
    return h->p;
}

extern "C" void func_0015A690(void *arg0, int arg1);
extern "C" void *func_0015A6E8(void *arg0, void *arg1);
extern "C" void func_001D3548(void *arg0, int arg1);
extern "C" void func_001D35A0(void *arg0, void *arg1);
extern "C" void func_001D3938(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(void *p);
extern "C" void func_002C1050(void *p);

extern "C" void func_00163CE0(void **arg0, void *arg1, s32 arg2, void *arg3) {
    Handle buf;
    if (arg2 > 0) {
        SrcHandle h;
        SrcHandle *ph;
        func_0015A6E8(&buf, arg1);
        ph = &h;
        func_001D35A0(ph, arg3);
        *(Big *)(buf.p->p10 + 0x1460) = ph->p->b;
        func_001D3548(ph, 2);
        func_0015A690(&buf, 2);
    } else {
        Handle h;
        Handle *ph;
        func_0015A6E8(&buf, arg1);
        ph = &h;
        func_001D3938(ph, get(&buf)->p10 + 0x1460);
        if ((void *)arg0 != (void *)ph) {
            void *p = ph->p;
            if (p != 0) {
                func_002C0FE8(p);
            }
            if (*arg0 != 0) {
                func_002C1050(*arg0);
            }
            *arg0 = p;
        }
        func_001D3548(ph, 2);
        func_0015A690(&buf, 2);
    }
}
