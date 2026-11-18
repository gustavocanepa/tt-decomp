/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Server;
struct Request;
struct Handler { s32 (*fn)(void *, struct Request *); void *arg; };
struct Request {
    s32 type;
    char pad4[0xC0 - 4];
    s32 done;
    s32 replied;
    char padC8[4];
    struct Request *next;
};
struct Server {
    char pad0[0x64];
    s32 ready;
    s32 started;
    struct Handler reply[7];
    struct Handler handle[7];
    struct Request *head;
    struct Request **tail;
    char padE4[0x2200 - 0xE4];
    char lock[0x30];
    char sema[1];
};

void func_004AEAF8(void *);
void func_004AEB30(void *);
void func_004A4D68(void *);
void func_004A4DD8(void *);
void func_004C1EF0(struct Server *, struct Request *);
s32 func_004C1BF0(struct Server *, s32, s32, s32);
extern struct Server *D_00598C0C;

void func_004C1A68(struct Server *self) {
    struct Request *r;
    struct Request *next;
    struct Handler *h;
    s32 type;

    for (;;) {
        do {
            func_004AEAF8(self->sema);
        } while (self->ready == 0 || self->started == 0);
        func_004A4D68(self->lock);
        r = self->head;
        while (r != 0) {
            func_004A4DD8(self->lock);
            type = r->type;
            if (r->replied == 0) {
                h = &self->handle[type];
                if (h->fn(h->arg, r) == 0) r->replied = 1;
            }
            if (r->done == 0) {
                h = &self->reply[type];
                if (h->fn == 0 || h->fn(h->arg, r) == 0) r->done = 1;
            }
            func_004A4D68(self->lock);
            next = r->next;
            self->head = next;
            if (next == 0) self->tail = &self->head;
            if (r->done != 0 && r->replied != 0) {
                func_004C1EF0(self, r);
            } else {
                r->next = 0;
                *self->tail = r;
                self->tail = &r->next;
                func_004AEB30(self->sema);
            }
            r = self->head;
        }
        func_004A4DD8(self->lock);
    }
}

s32 func_00553D80(s32 a, s32 b, s32 c) {
    return func_004C1BF0(D_00598C0C, a, b, c);
}
