struct Slot {
    char data[0x34];
};

extern char D_005A0B88[];
extern "C" void func_004A4930(void *mutex);
extern "C" void func_004A4970(void *mutex);
extern "C" void func_004C4818(Slot *slot);

extern "C" void func_004C4DA0(Slot *slots)
{
    func_004A4930(D_005A0B88);
    for (int i = 0; i < 48; i++)
        func_004C4818(&slots[i]);
    func_004A4970(D_005A0B88);
}
