struct S { char pad[0x10]; int unk10; };
extern void func_003FDA50(int);

void func_0051B428(S *arg0)
{
    func_003FDA50(arg0->unk10);
}
