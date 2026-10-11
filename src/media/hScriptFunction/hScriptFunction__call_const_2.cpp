struct Val { int w[4]; };
struct Ctx { void *vm; };
struct Obj { char pad[0xC]; char *h; };
extern "C" void func_002B1AB8(void *, char **);
extern "C" void func_002A7A30(Val *);
extern "C" void func_002BAD00(void *, char *, int, int, Val *);
extern "C" void func_002A75A8(Val *, int);

extern "C" void hScriptFunction__call_const_2(Obj *self, Ctx *c, int a, int b)
{
    func_002B1AB8(c->vm, &self->h);
    void *vm = c->vm;
    char *code = self->h + 0x10;
    Val v;
    func_002A7A30(&v);
    func_002BAD00(vm, code, a, b, &v);
    func_002A75A8(&v, 2);
}
