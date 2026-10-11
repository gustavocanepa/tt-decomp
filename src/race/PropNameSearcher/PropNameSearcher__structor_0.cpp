class ResultBase {
public:
    virtual void v1();
};

class D_005D5D70 : public ResultBase {
public:
    int value;
    D_005D5D70() : value(0) {}
};

struct Key {
    int a;
    int b;
    int c;
    int d;
};

struct Slot {
    char pad0[0x38C4];
    int id;
    char pad1[0x4360 - 0x38C4 - 4];
    int result;
};

struct Owner {
    char pad[0x38C4];
    Slot slots[6];
};

extern "C" void func_003EEC90(Key *k);
extern "C" void func_003EECA0(Key *k, int a, int b);
extern "C" int func_003963F8(Owner *o);
extern "C" int func_00396318(Owner *o);
extern "C" int func_003F0C80(Key *k, int id, D_005D5D70 *out);

extern "C" void PropNameSearcher__structor_0(Owner *o)
{
    Key k;
    func_003EEC90(&k);
    int a = func_003963F8(o);
    func_003EECA0(&k, a, func_00396318(o));
    Slot *sl = (Slot *)o;
    for (int i = 0; i < 6; i++, sl = (Slot *)((char *)sl + 0xAA4)) {
        D_005D5D70 r;
        func_003F0C80(&k, sl->id, &r);
        sl->result = r.value;
    }
}
