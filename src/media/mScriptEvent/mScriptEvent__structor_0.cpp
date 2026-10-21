/* compiler: ee-gcc2.96-no-strict-aliasing */
/* mScriptEvent constructor: mEvent base ctor (receives this, arg1, arg2 unchanged), vptr,
   string member copy-constructed (grab), then tail call to func_002931B0. */
typedef int s32;

extern "C" char *func_0050F0F0(void *rep);

struct Rep {
    s32 len;
    s32 res;
    s32 ref;
    s32 selfish;

    char *data() { return (char *)(this + 1); }
    char *clone() { return func_0050F0F0(this); }
    char *grab()
    {
        if (selfish)
            return clone();
        ++ref;
        return data();
    }
};

struct String {
    char *dat;
    Rep *rep() const { return ((Rep *)dat) - 1; }
};

static inline String *String_copy(String *self, const String &str)
{
    self->dat = str.rep()->grab();
    return self;
}

extern "C" void *mEvent__structor_0(void *self, s32 a1, s32 a2);
extern "C" s32 func_002931B0(void *p, s32 a);
extern "C" char D_005B2000[];

struct mScriptEvent {
    s32 pad0;
    void *vtbl;
    char pad8[0x18];
    String str;
};

extern "C" s32 mScriptEvent__structor_0(mScriptEvent *self, s32 arg1, s32 arg2, const String *s, s32 arg4)
{
    mEvent__structor_0(self, arg1, arg2);
    self->vtbl = D_005B2000;
    String_copy(&self->str, *s);
    return func_002931B0((char *)self + 0x24, arg4);
}
