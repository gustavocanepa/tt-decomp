typedef int s32;
typedef unsigned int u32;

struct E00479958 {
    char pad0[24];
};

struct Sub00479958 {
    struct E00479958 *unk0;
    u32 unk4;
};

struct S00479958 {
    char pad0[0x10];
    char blockA[0x18];
    struct Sub00479958 sub;
};

struct T00479958 {
    char pad0[0x6E38];
    s32 unk6E38;
};

extern "C" void func_00473050(void);
extern "C" void func_00445118(void *arg0, void *arg1);
extern "C" void func_00475440(void *arg0);
extern "C" void func_004730A8(void);
extern "C" void func_00440708(struct E00479958 *arg0, struct T00479958 *arg1);

extern "C" void func_00440620(struct S00479958 *arg0, struct T00479958 *arg1) {
    char buf[0x40];
    struct Sub00479958 *s;
    struct E00479958 *base;
    struct E00479958 *end;
    struct E00479958 *p;

    arg1->unk6E38 = 1;
    func_00473050();
    func_00445118(arg0->blockA, buf);
    func_00475440(buf);
    func_00473050();
    s = &arg0->sub;
    base = s->unk0;
    end = base + s->unk4;
    p = base;
    if (p != end) {
        do {
            struct E00479958 *cur = p;
            p++;
            func_00440708(cur, arg1);
        } while (p != end);
    }
    func_004730A8();
    func_004730A8();
    arg1->unk6E38 = 0;
}
