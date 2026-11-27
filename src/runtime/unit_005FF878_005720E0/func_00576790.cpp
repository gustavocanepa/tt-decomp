/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x00576790.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct S {
    int flags;
    char pad4[0x18];
    int u1C;
    char pad20[0x30];
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
};
extern "C" int func_00576790(S *s) {
    int result = s->u1C;
    if (result != 0) result = 0;
    else {
        result = (s->flags >> 1) & 1;
        if (result != 0) result = 0;
        else result = s->v11();
    }
    return result;
}
