struct Item { char pad0[0x10]; int handle; char pad14[0x20 - 0x14]; short anim; char pad22[0xA0 - 0x22]; };
extern "C" Item *D_0061B704;
extern "C" void func_00420B38(int handle, int anim, int arg);
extern "C" void func_002E0F10(int idx, int alt) {
    Item *items = D_0061B704;
    Item *it = &items[idx];
    int anim = it->anim * 2;
    if (alt) anim++;
    func_00420B38(items->handle, anim, 0);
}
