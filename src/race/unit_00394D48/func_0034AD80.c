struct A { char pad[0x18]; void *res; };
extern void func_004A45D0(void *);
void func_0034AD80(struct A *a)
{
    func_004A45D0(a->res);
    a->res = 0;
}
