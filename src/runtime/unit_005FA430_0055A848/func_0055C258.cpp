/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pt { float x, y; };
struct Node {
    char pad0[0x88];
    Pt *p1;
    Pt *p2;
    char pad1[0x18];
    Node *next;
};
struct IterData { void *owner; Node *n;
    IterData &operator++() { n=n->next; return *this; }
    bool operator!=(const IterData &other) const { return n!=other.n; }
    bool operator==(const IterData &other) const { return n==other.n; }
};
struct Iter {
    IterData d;
    Iter(const IterData &x) : d(x) {}
    Iter(const Iter &o) : d(o.d) {}
};
struct PtRef { const Pt *p[1]; };
struct Owner { char pad[0x358C]; Node *head; };

static inline const Pt *func_005AE2E8(const Pt *const &p) { return p; }
static inline float crossProduct(float bx, float py, float dy, float px) { return px*dy-py*bx; }
extern "C" Iter func_0055C258(Owner *self, const Pt *p) {
    IterData head;
    Node *h = self->head;
    head.n = h;
    IterData best;
    float bd = 0.0f;
    IterData cur;
    IterData *curPtr = &cur;
    IterData *bestPtr = &best;
    *bestPtr = head;
    cur.n = h->next;
    while (*curPtr != head) {
        Pt *a = cur.n->p1;
        float py = func_005AE2E8(p)->y;
        if (a->y <= py) {
            Pt *b = cur.n->p2;
            if (py <= b->y) {
                float dy = b->y - a->y;
                float cross = crossProduct(b->x - a->x, py - a->y, dy, func_005AE2E8(p)->x - a->x);
                if (cross >= 0.0f) {
                    float d = cross / dy;
                    if (best.n == head.n || d < bd) {
                        *bestPtr = *curPtr;
                        bd = d;
                    }
                }
            }
        }
        ++cur;
        curPtr = &cur;
    }
    return Iter(*bestPtr);
}
