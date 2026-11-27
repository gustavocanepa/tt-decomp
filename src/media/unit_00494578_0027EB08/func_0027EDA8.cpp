struct Obj;
extern "C" bool func_004AC5C0(Obj *o);

struct SelectBar {
    char pad[0x110];
    float unkEC;
};

extern "C" int func_0027EDA8(void *arg0) {
    SelectBar *self = (SelectBar *)arg0;
    int var_v1;

    if (func_004AC5C0((Obj *)((char *)arg0 + 0xE0))) {
        return 0;
    }
    var_v1 = 1;
    if (!(self->unkEC < 0.0f)) {
        var_v1 = 0;
    }
    return var_v1;
}
