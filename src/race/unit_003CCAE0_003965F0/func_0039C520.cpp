struct Sub {
    char pad0[0x28];
    int active;
};

struct Obj {
    int unk0;
    Sub sub;
};

extern "C" int func_003962C0(Obj *self);
extern "C" int func_003957C0(Sub *sub, int arg);

extern "C" int func_0039C520(Obj *self, int arg) {
    if (!func_003962C0(self))
        return 0;
    Sub *s = &self->sub;
    if (!s->active)
        return 0;
    return func_003957C0(s, arg);
}
