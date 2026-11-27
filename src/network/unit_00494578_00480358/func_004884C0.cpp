/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Date { unsigned short year; unsigned char month, day; };
struct Time { unsigned char hour, minute, second, spare; };
struct DateTime { Date date; Time time; };
extern "C" long func_004B6658(void);
extern "C" DateTime *func_004AF960(DateTime *, long);
struct U16 { unsigned short v; } __attribute__((packed));
static inline void put16(signed char *p, int v) { ((U16 *)p)->v = v; }
extern "C" void func_004884C0(signed char *p) {
    DateTime dt;
    func_004AF960(&dt, func_004B6658());
    Date date = dt.date;
    Time time = dt.time;
    int d = (date.day & 31) | ((date.month & 15) << 5) | ((((int)date.year - 1980) & 127) << 9);
    int t = (((int)time.second >> 1) & 31) | ((time.minute & 63) << 5) | ((time.hour & 31) << 11);
    put16(p + 0x18, d);
    put16(p + 0x16, t);
}
