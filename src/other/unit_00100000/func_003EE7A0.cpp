extern "C" void *func_00457C68(void *arg0);
extern "C" char D_005D7420[];

struct S001C7698 {
    char pad[0x11D0];
    void *unk11D0;
};

extern "C" void func_003EE7A0(S001C7698 *arg0)
{
    func_00457C68(arg0);
    arg0->unk11D0 = D_005D7420;
}
