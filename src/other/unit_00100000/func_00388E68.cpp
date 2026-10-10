extern "C" int D_00584774;
extern "C" void *func_004AE6D8(int addr);
extern "C" void func_00388BD8(void *p, int addr);

extern "C" void func_00388E68(int slot) {
    int addr = slot * 0x96000 + 0x100;
    D_00584774 = slot;
    func_00388BD8(func_004AE6D8(addr), addr);
}
