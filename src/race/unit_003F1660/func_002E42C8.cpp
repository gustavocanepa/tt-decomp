/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta,index; int (*fn)(void *); };
struct Sub { char pad[0x23980]; signed char entries[2]; };
struct Obj { char pad[4]; Sub sub; char pad2[0x844]; char *vt; };
extern "C" int func_002F04D8(Obj *, int);
extern "C" void func_002E3E80() throw();
extern "C" void func_002E3F80(Obj *, int) throw();
static inline int check(Obj *o) {
    VEntry *e = (VEntry *)(o->vt + 0x30);
    return e->fn((char *)o + e->delta);
}
static inline void request(Obj *o,int index,int command,int value) {
    int offset = index * 4;
    Sub *s = &o->sub;
    s->entries[offset] = command;
    s->entries[offset + 1] = value;
}
extern "C" int func_002E42C8(Obj *o, int command, int index, int value) {
    if ((unsigned)(command - 1) >= 10) return -1;
    if (command == 1) { func_002E3E80(); return 0; }
    if (command == 2) { func_002E3F80(o,index); return 0; }
    if (command == 3) return *((unsigned char *)o + 0x20A28) == 1;
    if (index < 0 || index >= *(int *)((char *)o + 0x23968)) return -1;
    int result = 0;
    char *car = (char *)func_002F04D8(o,index);
    char *state = car + 0x14;
    char *body = car + 0x104;
    switch(command) {
    case 4:
        if (value < 0) result = -1;
        else if (value >= 5) result = -1;
        else if (*(unsigned char *)(state+0x6d) != value) {
            request(o,index,command,value); result=1;
        }
        break;
    case 5:
        result = -1;
        if (check(o) == 0) { request(o,index,command,value); result=1; }
        break;
    case 6:
        if (*((unsigned char *)o + 0x20A28) != 1) result=-1;
        else if (check(o) != 0) result=-1;
        else {
            if (value != 0) {
                if (*(unsigned char *)(body+0x4D1)&8) break;
            } else {
                if ((*(unsigned char *)(body+0x4D1)&8) == 0) break;
            }
            request(o,index,command,value); result=1;
        }
        break;
    case 7: result = *(unsigned char *)(state+0x6d); break;
    case 8: result = *(unsigned char *)(state+0x6e); break;
    case 9: if (*(unsigned char *)(body+0x4D1)&8) result=1; break;
    case 10: request(o,index,command,value); result=1; break;
    }
    return result;
}
