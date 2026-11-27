struct S { char pad[0x1220]; int v[1]; };
int func_00559CE0(struct S *s, int i) { int *e = s->v + i; return *e; }
