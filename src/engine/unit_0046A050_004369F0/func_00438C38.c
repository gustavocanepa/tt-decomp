struct S { char pad[0xC]; short h; };
int func_00438C38(struct S *s, int a) {
    if (s->h == 0) return 0;
    return 8 - a;
}
