extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);
extern "C" char D_005A0B88[];

/* test-and-set under the global lock */
extern "C" int func_004C4270(int *flag)
{
    func_004A4930(D_005A0B88);
    int ok = *flag == 0;
    if (ok)
        *flag = 1;
    func_004A4970(D_005A0B88);
    return ok;
}
