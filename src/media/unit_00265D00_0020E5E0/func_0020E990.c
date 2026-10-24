struct S { char pad[0xAC]; unsigned char f; };
int func_0020E990(struct S *p, unsigned long long m) { return ((p->f >> 4) & m) != 0; }
