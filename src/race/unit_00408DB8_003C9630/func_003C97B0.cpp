extern "C" void func_003C88E8(void *self, int axis, float v);

extern "C" void func_003C97B0(void *self, float v)
{
    func_003C88E8(self, 0, v);
    func_003C88E8(self, 1, v);
    func_003C88E8(self, 2, v);
}
