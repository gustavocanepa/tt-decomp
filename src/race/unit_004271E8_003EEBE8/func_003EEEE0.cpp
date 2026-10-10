struct Entry { int m0; short x, y, z; short pad; int mC; };
struct Data { char pad[0x1C]; Entry *entries; };
struct Obj { int m0; Data *data; };
extern "C" int func_003F1860(Obj *);

extern "C" void func_003EEDA0(Obj *, int, int, int, float, int, float);

extern "C" void func_003EEEE0(Obj *o, int idx, float a, int arg, float b)
{
    if (!func_003F1860(o)) return;
    if (!o->data) return;
    func_003EEDA0(o, o->data->entries[idx].x, o->data->entries[idx].y, o->data->entries[idx].z, a, arg, b);
}
