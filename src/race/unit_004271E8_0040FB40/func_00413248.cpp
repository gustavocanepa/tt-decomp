struct Rec {
    int value;
};

struct Table {
    int pad0;
    int count;
};

extern "C" Rec *func_004130E8(Table *t, int i) throw();

extern "C" int func_00413248(Table *t) {
    int best = 0x7FFFFFFF;
    int bestIdx = -1;
    for (int i = 0; i < t->count; i++) {
        Rec *r = func_004130E8(t, i);
        if (r->value < best) {
            best = r->value;
            bestIdx = i;
        }
        if (best == -1)
            break;
    }
    return bestIdx;
}
