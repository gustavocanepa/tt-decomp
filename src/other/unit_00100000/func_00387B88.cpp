struct Reader { int w[4]; };
struct Obj { char pad[0xD0]; void *data; };
extern "C" void func_003EEC90(Reader *r);
extern "C" void func_003EECA0(Reader *r, int pos, void *data);
extern "C" int func_003F1710(Reader *r, int key);

extern "C" int func_00387B88(Obj *self, int key)
{
    if (!self->data)
        return -1;
    Reader r;
    func_003EEC90(&r);
    func_003EECA0(&r, 0, self->data);
    return func_003F1710(&r, key);
}
