/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Packet {u8 a,b; signed char c,count; short d; u8 pad,e; short f,g,h,i; u8 data[16];};
struct Obj {unsigned start,end; char pad[0x14-8]; int steer; Packet prev;};
extern "C" void AutomobileControlRecord__Recorder__steer_update(Obj *o) {
    short s = o->prev.d;
    int last = o->steer;
    o->steer = s;
    if ((s >= 0 ? s : -s) >= 16) {
        int d = s * 2 - last;
        if (d > 0x1000) d = 0x1000;
        else if (d < -0x1000) d = -0x1000;
        o->prev.d = d;
    }
}
