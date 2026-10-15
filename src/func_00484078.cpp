/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
struct State { char pad[0x10]; s32 cursor; u16 *text; };
static inline s32 flag(u16 *q) { unsigned int v=*q; v>>=7; return v&1; }
extern "C" s32 func_00484078(State *s, s32 direction) {
    s32 index=s->cursor;
    if(direction==-1) {
        if(index<=0) return index;
        s32 n=0;
        u16 *q=(u16 *)(index*2+(s32)s->text);
        do { --q; n+=(*q>>7)&1; --index; } while(n<=0);
        return index;
    }
    if(direction==1) {
    u16 *text=s->text;
    s32 len=0;
    if(*text) {
        u16 *q=text;
        do { ++q; ++len; } while(*q);
    }
    if(index>=len) return index;
    s32 n=0;
    u16 *q=(u16 *)(index*2+(s32)text);
    do { ++index; ++q; if(index>=len || flag(q)) --n; } while(n>=0);
    }
    return index;
}
