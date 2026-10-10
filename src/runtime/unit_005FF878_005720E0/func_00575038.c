struct S { short pad; unsigned short v; };
int func_00575038(struct S *p) { int x = p->v; return (x >> 4) & 0xf; }
