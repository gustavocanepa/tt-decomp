struct Lock;
extern Lock D_005A0B88;
extern "C" void func_004A4930(Lock *l);
extern "C" void func_004A4970(Lock *l);

struct Obj {
    char pad[0xA0];
    int counter;
};

extern "C" int func_004C6F78(Obj *o)
{
    func_004A4930(&D_005A0B88);
    int id = o->counter;
    o->counter = id + 1;
    if (id == 0x7FFFFFFF)
        id = 0;
    func_004A4970(&D_005A0B88);
    return id;
}
