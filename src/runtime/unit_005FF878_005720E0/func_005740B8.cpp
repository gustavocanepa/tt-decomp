struct Voice {
    char data[0x70];
};

extern char D_005A0B88[];
extern "C" void func_004A4930(void *mutex);
extern "C" void func_004A4970(void *mutex);
extern "C" void func_004C5610(Voice *v);

extern "C" void func_005740B8(void *self, Voice *voices, int count)
{
    func_004A4930(D_005A0B88);
    for (int i = 0; i < count; i++)
        func_004C5610(voices++);
    func_004A4970(D_005A0B88);
}
