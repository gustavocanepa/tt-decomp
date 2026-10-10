typedef int s32;

struct Reader {
    char pad[0x4C];
    void *vtbl;
};

extern char D_005AD0C8[];
extern "C" void func_0019CE28(Reader *);
extern "C" s32 func_0019D380(Reader *, void *);
extern "C" void func_0019B480(Reader *, s32);

/* A local object built, used and destroyed: the inlined destructor restores the class's vtable
   pointer and calls the base destructor (in_chrg 0). */
extern "C" s32 func_0019AF18(void *src) {
    Reader r;
    func_0019CE28(&r);
    s32 ok = func_0019D380(&r, src);
    r.vtbl = D_005AD0C8;
    func_0019B480(&r, 0);
    return ok;
}
