struct Sub { int w; };
struct Item { char pad[0x54]; Sub sub; };
extern "C" char D_005F55F8[];
extern "C" void func_0035A078(Item *self, const char *name, float x, float y);
extern "C" void func_0035A188(Item *self, float a, float b);
extern "C" void func_0035EB60(Sub *s);

extern "C" void func_0035A128(Item *self)
{
    func_0035A078(self, D_005F55F8, 0.0f, 0.0f);
    func_0035A188(self, -1.0f, 0.0f);
    func_0035EB60(&self->sub);
}
