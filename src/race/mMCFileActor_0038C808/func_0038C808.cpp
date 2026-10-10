extern "C" void *func_0034F6E8(void *arg0);
extern "C" void *RaceTimeDisplay__structor_0(char *arg0);
extern "C" char D_005D5958[];

struct func_0038C808_s0 {
    void *unk0;
};

extern "C" void *func_0038C808(void *arg0)
{
    void *s0 = arg0;
    func_0034F6E8(s0);
    ((struct func_0038C808_s0 *)s0)->unk0 = D_005D5958;
    return RaceTimeDisplay__structor_0((char *)s0 + 0x54BC);
}
