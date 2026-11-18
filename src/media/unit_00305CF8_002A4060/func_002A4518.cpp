/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct N { char pad0[4]; N *parent; N *left; N *right; u32 key; s32 val; };
struct It { N *n; char pad[12]; };
struct Pair { u32 k; s32 v; char pad[8]; };
struct Tree { char pad[4]; N *hdr; };
extern "C" N **func_0054BE40(N **, Tree *, u32 *);
extern "C" void func_0054BE88(void *, Tree *, It *, Pair *);
extern "C" void func_002BC0C8(void *, void *);
extern "C" void func_002BC0E0(void *, int);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_002A4318(void *, u32 *, s32 *) throw();

static inline int ne(It *a, It *b) { return a->n != b->n; }

extern "C" void func_002A4518(char *self, u32 *key, s32 *val) {
    Tree *tree = (Tree *)(self + 0x18);
    It it;
    It endIt;
    char out[0x10];
    It a;
    Pair pr;
    It b;
    func_0054BE40(&it.n, tree, key);
    N *cur = it.n;
    int found = 0;
    endIt.n = tree->hdr;
    if (cur != endIt.n)
        found = cur->key == *key;
    if (found) {
        s32 *s1 = &cur->val;
        if (s1 != val) {
            s32 s0 = *val;
            if (s0 != 0) func_002C0FE8(s0);
            if (*s1 != 0) func_002C1050(*s1);
            *s1 = s0;
        }
    } else {
        It *pa = &a;
        Pair *pp = &pr;
        s32 *pv = &pr.v;
        pa->n = cur;
        pp->k = *key;
        func_002BC0C8(pv, val);
        It *pb = &b;
        pb->n = pa->n;
        func_0054BE88(out, tree, pb, pp);
        func_002BC0E0(pv, 2);
    }
    func_002A4318(self, key, val);
}
