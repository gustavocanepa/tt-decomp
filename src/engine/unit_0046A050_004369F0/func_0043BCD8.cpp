/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
extern Rep D_005A4C58;
extern "C" char *strobe__toUpper(Rep *);
extern "C" void *func_00443C60(void *);
struct Pair { int a,b; void init() { a=0; b=0; } };
struct Vec { int a,b,c; void init() { a=0; b=0; c=0; } };
struct Str { char *p; void init() { Rep *r=&D_005A4C58; char *d=(char *)(r+1); if(r->sel) d=strobe__toUpper(r); else r->ref++; p=d; } };
struct Self {
 int own; Self *prev,*next; int parent;
 int f10; union { int i; float f; } f14; int f18,f1c,f20,f24,f28,f2c;
 Pair p30,p38; char state[0x124]; int f164;
 Str s168; int f16c,f170,f174,f178; Str s17c;
 Vec v180; int f18c,f190; Pair p194;
};
extern "C" int func_0043BCD8(Self *s,int a,int b) {
 int spare[4];
 { volatile Self *v=s;
 v->parent=a; v->f18=1; v->own=0; v->prev=s; v->next=s;
 v->f10=0; v->f14.i=1; v->f1c=0; v->f20=0; v->f24=0; v->f28=0; v->f2c=0;
 }
 s->p30.init(); s->p38.init(); func_00443C60(s->state); s->f164=b;
 { Str *dst=&s->s168; Rep *r=&D_005A4C58; char *d=(char *)(r+1);
 if(r->sel) d=strobe__toUpper(r); else r->ref++; dst->p=d; }
 s->f174=1; s->f16c=0;
 { Str *dst=&s->s17c; Rep *r=&D_005A4C58; char *d=(char *)(r+1);
 if(r->sel) d=strobe__toUpper(r); else r->ref++; dst->p=d; }
 s->v180.init(); s->f18c=1; s->p194.init();
}
