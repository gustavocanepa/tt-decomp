extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);
extern "C" void func_0042C4D8(int v);
extern "C" char D_0076A028[];
extern "C" int D_0076A008;

extern "C" void func_0042C6D0(int v)
{
    func_004A4D68(D_0076A028);
    if (v != D_0076A008)
        func_0042C4D8(v);
    func_004A4DD8(D_0076A028);
}
