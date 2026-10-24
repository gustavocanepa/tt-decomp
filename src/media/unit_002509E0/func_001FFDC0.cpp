struct Obj {char pad[0x114];unsigned frames;};
extern "C" void func_001FFDC0(struct Obj *p,float seconds) {p->frames=(unsigned)(seconds*60.0f);}
