struct func_00485E68_arg0 {
    char pad0[0x85C];
    int unk858;
    int unk85C;
};

extern "C" short func_00485E68(void *arg0) {
    struct func_00485E68_arg0 *s = (struct func_00485E68_arg0 *)arg0;
    int idx = s->unk858;
    char *e = (char *)arg0 + idx * 0x41C;
    e = e + s->unk85C * 8;
    return *(short *)(e + 0x23E);
}
