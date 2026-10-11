struct Obj { char pad[0x74]; void *target; };
extern "C" void func_0034D928(void *, int, int);

extern "C" void func_0034D0A0(Obj *o, int x, const unsigned short *list)
{
    void *t = o->target;
    if (list) {
        int n = *list++;
        for (int i = 0; i < n; i++) func_0034D928(t, x, list[i]);
    } else {
        func_0034D928(t, x, -1);
    }
}
