struct Font { char pad[0x5C]; unsigned int color; };
extern Font *D_00586EF4;
extern "C" void func_0045EF78(Font *,float,float,float,float);
static inline float maxf(float a,float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a,float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" void func_00415B10(void *self, unsigned int color) {
 unsigned int a=(color >>24)&255;
 D_00586EF4->color=color;
 float alpha=(float)a*0x1p-7f;
 func_0045EF78(D_00586EF4,0.0f,0.0f,0.0f,minf(maxf((alpha-0.25f)*0x1.555554p+0f,0.0f),1.0f));
}
