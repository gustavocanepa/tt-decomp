/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; void (*fn)(void *, int); };
struct Obj { char pad[0x48]; char *vtbl; };
extern "C" void func_00104C58(void *);
extern "C" void func_00104C88(void *);
extern "C" void *func_001050C0(void *, void *, int, int);
extern "C" float func_001CDA38(Obj *);
extern "C" void func_00470450(int);
extern "C" void func_00470478(int);
extern "C" void func_00470728(int, int, float);
extern "C" void func_00470B48(int);
extern "C" void func_00470E60(int);
extern "C" void func_004716B0(int, float);
extern "C" void func_00472268(int, int);
extern "C" void func_00478C98(int);
extern "C" void func_001C8BA8(int unused, Obj *a, void *b, void *c, void *d, int n, int flag, Obj *e, int mode) {
    long long tmp;
    int i;
    if (n <= 0) n = 1;
    i = 0;
    func_00478C98(5);
    tmp = 0x80000000;
    func_00104C58(d);
    {
        for (; i < n; i++) {
            int v = 0;
            func_00104C88(b);
            if (flag == 0 || mode != 0) v = 1;
            func_001050C0(b, c, 0, 0);
            func_00470B48(tmp);
            func_00470478(1);
            if (v != 0) func_00470450(0xFF000000);
            if (mode != 0) func_00470E60(1); else func_00470E60(3);
            func_00470450(-1);
            func_00472268(1, 0);
            func_00470728(n, i, 0.7f);
            Entry *en = (Entry *)(a->vtbl + 0x28);
            en->fn((char *)a + en->delta, flag);
            if (e != 0) {
                Entry *en2 = (Entry *)(e->vtbl + 0x28);
                en2->fn((char *)e + en2->delta, flag);
            }
            func_00104C88(b);
            func_00104C58(d);
            float f = mode != 0 ? func_001CDA38(a) : 1.0f / (float)(i + 1);
            func_004716B0(6, f);
        }
    }
}
