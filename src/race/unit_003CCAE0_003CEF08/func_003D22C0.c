extern float *func_003BD8C0(int);
struct S { char pad[296]; int h; };
int func_003D22C0(struct S *s) { float *p = func_003BD8C0(s->h); if (0.0f < *p) return 0; return 1; }
