/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Range { unsigned short mask; short base; };
struct Table { char *first; Range *second; Range *third; unsigned short *codes; };
extern "C" unsigned short func_004B4CE0(Table *t, int code) {
    Range *r = (Range *)(t->first + ((code >> 10) & 0x3C));
    int hi = (code >> 8) & 15;
    int mid = (code >> 4) & 15;
    int lo = code & 15;
    int m1 = 1 << hi;
    int m2 = 1 << mid;
    int m3 = 1 << lo;
    
    int base = r->base;
    if (r->mask & m1) {
        Range *s = t->second + (hi + base);
        
        int base = s->base;
        if (s->mask & m2) {
            Range *u = t->third + (mid + base);
            
            int base = u->base;
            if (u->mask & m3) return t->codes[lo + base];
        }
    }
    return 0;
}
