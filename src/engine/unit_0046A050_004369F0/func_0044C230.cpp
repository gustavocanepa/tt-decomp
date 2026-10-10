extern "C" void *func_00473980(int);

struct Pool {
    int a;
    int count;
    void *head;
    void *base;
    Pool(int a, int count) __asm__("func_0044C230");
};

Pool::Pool(int a_, int count_) {
    a = a_;
    count = count_;
    head = func_00473980((count_ * 24 + 15) >> 4);
    base = head;
}
