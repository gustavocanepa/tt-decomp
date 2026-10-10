struct Obj { char pad[0x3C]; int slots[8]; };
extern "C" int func_003962C0(Obj *self, int i);
extern "C" int func_0039C5D8(Obj *self, int i);

extern "C" int func_0039C580(Obj *self, int i)
{
    if (!func_003962C0(self, i)) return 0; if (!func_0039C5D8(self, i)) return 0; return self->slots[i] == 0;
}
