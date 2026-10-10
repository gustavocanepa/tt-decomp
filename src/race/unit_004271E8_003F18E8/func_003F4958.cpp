struct Obj {
    char pad[0xC];
    int slots[8];
    int busy;
};

extern "C" int func_003F4538(unsigned char id);
extern "C" void func_00478C98(int h);

extern "C" void func_003F4958(Obj *o)
{
    if (o->busy == 0) {
        for (int i = 0; i < 8; i++) {
            if (o->slots[i] == 0)
                func_00478C98(func_003F4538(i));
        }
    }
}
