struct Lock { int sema; int depth; int owner; int waiting; };
extern "C" void func_00178360(Lock *l);
extern "C" void func_00178380(Lock *l);
extern "C" void func_004A4F00(int sema);

extern "C" void func_001782B0(Lock *l)
{
    if (l->depth) {
        l->depth--;
    } else {
        l->owner = 0;
        func_00178360(l);
        if (l->waiting) {
            l->waiting = 0;
            func_004A4F00(l->sema);
        }
        func_00178380(l);
    }
}
