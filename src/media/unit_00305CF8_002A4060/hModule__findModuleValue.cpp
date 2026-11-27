/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct N { char pad0[4]; N *parent; N *left; N *right; u32 key; s32 val; };
struct It { N *n; char pad[12]; };
struct Tree { char pad[4]; N *hdr; s32 size; };
static inline bool empty(Tree *t) { return t->size == 0; }
extern char D_0057CA00[];
extern "C" void func_002BC0E0(void *, int);
extern "C" s32 hValue__isValid(s32);
extern "C" void func_002BC270(void *);
extern "C" s32 func_002BFDD0(char *, s32 *, void *, u32 *);
extern "C" void func_002BFEA8(char *, void *, u32 *, s32 *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" N *func_0054BC38(Tree *, u32 *);

static inline void assign(s32 *d, s32 *s) {
    if (d != s) {
        s32 v = *s;
        if (v != 0) func_002C0FE8(v);
        if (*d != 0) func_002C1050(*d);
        *d = v;
    }
}

extern "C" void hModule__findModuleValue(char *self, s32 *out, u32 *key) {
    if (func_002BFDD0(D_0057CA00, out, self, key) != 0) return;
    s32 buf[4];
    func_002BC270(buf);
    assign(out, buf);
    func_002BC0E0(buf, 2);
    Tree *t = (Tree *)(self + 0x18);
    if (!empty(t)) {
        It it;
        it.n = func_0054BC38(t, key);
        It *pit = &it;
        int found = 0;
        if (pit->n != t->hdr)
            found = hValue__isValid(pit->n->val) != 0;
        if (found)
            assign(out, &pit->n->val);
    }
    func_002BFEA8(D_0057CA00, self, key, out);
}
