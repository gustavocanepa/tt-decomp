extern "C" void func_0034D2F0(void *self, int n, float x);
extern "C" void func_0034D5A0(void *self, int n);

extern "C" void func_0034D1E8(void *self, float x)
{
    func_0034D2F0(self, 1, 100.0f);
    func_0034D5A0(self, 1);
    func_0034D2F0(self, 1, -x);
    func_0034D5A0(self, 1);
}
