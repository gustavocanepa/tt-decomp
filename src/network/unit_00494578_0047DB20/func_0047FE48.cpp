/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { char pad[0x14]; int flag; };
struct Obj { char pad[0x1A88]; Sub *sub; char pad329c[0x14]; int value; };
extern "C" void func_004AEAF8(void *);
extern "C" int func_004F76D0(void *,int) __attribute__((noreturn));
extern "C" void func_0047FE48(Obj *self,int flag) {
    func_004AEAF8((char *)self + 0x19F0);
    if (flag != 0) return;
    if (self->value >= 0) return;
    func_004AEAF8((char *)self + 0x1A50);
    self->sub->flag = 1;
    func_004F76D0((char *)self + 0x1890,1);
}
