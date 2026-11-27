/* compiler: ee-gcc2.96-no-strict-aliasing */
/* hThread::execute0(unsigned): the Adhoc interpreter's dispatch loop. The thread keeps the
   addresses of four labels of this function (pop one frame, unwind to a catching frame, finish,
   next instruction); each instruction's execute() leaves one of them in `target`. */
struct hThread;
struct Frame {
    virtual void destroy(int);
    virtual int isCatch();
    virtual void leave(hThread *);
};
struct Op {
    int pad;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void execute(hThread *);
};
struct FrameStack {
    int pad;
    Frame **start;
    Frame **finish;
    Frame **end_of_storage;
    Frame **begin() { return start; }
    Frame **end() { return finish; }
    unsigned size() { return end() - begin(); }
    Frame *back() { return *(end() - 1); }
    void pop_back() { --finish; }
};
struct RefCounter;
extern "C" void func_002C0FE8(RefCounter *);
extern "C" void func_002C1050(RefCounter *);
struct Ref {
    RefCounter *p;
    Ref &operator=(const Ref &o) {
        if (this != &o) {
            RefCounter *q = o.p;
            if (q) func_002C0FE8(q);
            if (p) func_002C1050(p);
            p = q;
        }
        return *this;
    }
};
struct ValueStack {
    char pad[0x8];
    Ref *base;
    char pad18[8];
    int sp;
    void push(const Ref &v) { base[sp] = v; ++sp; }
};
struct hThread {
    char pad[0x10];
    FrameStack frames;
    char pad20[8];
    Op **pc;
    ValueStack *values;
    Ref value;
    int state;
    void *labels[4];
    void *target;
    int execute0(unsigned depth) __asm__("func_002BA958");
    void popFrame() {
        Frame *f = frames.back();
        f->leave(this);
        f->destroy(3);
        frames.pop_back();
    }
};
int hThread::execute0(unsigned depth) {
    if (depth < frames.size()) {
        Op **p;
        Op *op;
        void *t;
        if (!target) {
            labels[0] = &&pop_one;
            labels[1] = &&pop_many;
            labels[2] = &&finish;
            labels[3] = &&next;
        }
        state = 3;
        void **resume = &labels[3];
        target = *resume;
        while (1) {
            p = pc;
            op = *p;
        next:
            pc = p + 1;
            op->execute(this);
            t = target;
            p = pc;
            op = *p;
            goto *t;
        pop_one:
            popFrame();
            if (!(depth < frames.size())) break;
            state = 3;
            target = *resume;
            continue;
        pop_many:
            {
                int c = frames.back()->isCatch();
                if (c) {
                    do {
                        popFrame();
                        if (!(depth < frames.size())) break;
                        c = frames.back()->isCatch();
                    } while (c);
                }
                if (!c) {
                    popFrame();
                    values->push(value);
                }
            }
            if (!(depth < frames.size())) break;
            state = 3;
            target = *resume;
        }
    }
finish:
    return state;
}
