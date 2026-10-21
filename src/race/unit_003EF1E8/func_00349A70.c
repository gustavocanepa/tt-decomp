struct S { char pad[0x178]; int a; int b; };
int func_00349A70(struct S *p) { int lt = p->a < p->b; if (lt == 0) return 1; return 0; }
