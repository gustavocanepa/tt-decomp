struct Info {
    unsigned char pad;
    unsigned char count;
};

struct Obj {
    char pad[0x10];
    int id;
};

extern "C" Info *func_002FD378(int id);
extern "C" void func_0030A368(Obj *o, int i);

extern "C" void func_0030A4B8(Obj *o)
{
    Info *info = func_002FD378(o->id);
    for (int i = 0; i < info->count; i++)
        func_0030A368(o, i);
}
