struct Obj { char pad[0xB4]; int count[8]; };
extern "C" int func_003962C0(Obj *self, int i);
extern "C" int func_0039C520(Obj *self, int i);

extern "C" int func_0039C5D8(Obj *self, int i)
{
    if (!func_003962C0(self, i))
        return 0;
    if (!func_0039C520(self, i))
        return 0;
    int *c = self->count; if (c[i] < 5) return 0; return 1;
}
