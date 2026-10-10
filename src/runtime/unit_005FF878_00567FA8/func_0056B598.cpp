struct Vec {
    int items[0x30];
    unsigned int size;
    void erase(int *first, int *last) __asm__("func_0056B648");
    void insert(int *pos, unsigned int n, const int &x) __asm__("func_0056B6E8");
    void resize(unsigned int n, int x) __asm__("func_0056B598");
};

void Vec::resize(unsigned int n, int x) {
    if (n == size)
        return;
    if (n < size)
        erase(&items[n], &items[size]);
    else
        insert(&items[size], n - size, x);
}
