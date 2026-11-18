/* Builds a context handle from arg1 (func_001DF250), opens its list (func_001E2A20), adds the object
   of each of the count names through a temporary handle (func_001E6480 / func_001E6428) and closes it.
   The explicit i < count guard puts the second &obj copy after the loop test, as in the original. */
extern "C" void func_001DF250(void *, void *);
extern "C" void func_001DF1F8(void *, int);
extern "C" void func_001E2A20(void *);
extern "C" void func_001E2BF8(void *, void *);
extern "C" void func_001E2CB0(void *);
extern "C" void func_001E6480(void *, void *);
extern "C" void func_001E6428(void *, int);

struct Handle {
    void *p;
    int pad[3];
};

static inline void *get(Handle *h) { return h->p; }

extern "C" void MRenderContext__startPage(void *arg0, void *arg1, int count, void **names)
{
    if (count > 0) {
        Handle ctx;
        int i;
        func_001DF250(&ctx, arg1);
        func_001E2A20(ctx.p);
        Handle obj;
        Handle *pobj;
        i = 0;
        if (i < count) {
            pobj = &obj;
            for (; i < count; i++) {
                void *list = ctx.p;
                func_001E6480(&obj, &names[i]);
                func_001E2BF8(list, get(&obj));
                func_001E6428(pobj, 2);
            }
        }
        func_001E2CB0(ctx.p);
        func_001DF1F8(&ctx, 2);
    }
}
