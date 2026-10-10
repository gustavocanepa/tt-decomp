extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);
extern "C" void func_004C4B28(int *obj, int arg);
extern "C" char D_005A0B88[];

extern "C" void func_004C4CB0(int *obj, int arg)
{
    func_004A4930(D_005A0B88);
    func_004C4B28(obj, arg);
    *obj = 0;
    func_004A4970(D_005A0B88);
}
