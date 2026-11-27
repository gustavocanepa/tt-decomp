/* compiler: ee-gcc2.96-nogcse */
// Provisional layout: each of the six entries holds a value and two slot IDs.
struct Entry { int value; int slots[2]; };

static inline int remove(int *p, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (p[i] == value) {
            p[i] = 0;
            return 1;
        }
    }
    return 0;
}

static inline int empty(int *p, int i, int n) {
    for (; i < n; i++) {
        if (p[i] != 0) return 0;
    }
    return 1;
}

// Clear the requested slot ID. Release an entry's value only when both slots
// have become empty; a partial removal permits the search to continue.
extern "C" int func_00388D68(Entry *p, int value) {
    int *slots = p->slots;
    for (int i = 0; i < 6; slots += 3, i++) {
        if (remove(slots, 2, value)) {
            if (empty(slots, 0, 2)) {
                slots[0] = 0;
                slots[1] = 0;
                int v = p[i].value;
                p[i].value = 0;
                return v;
            }
        }
    }
    return 0;
}
