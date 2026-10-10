struct Array {
    int data[32];
    unsigned int count;
};

extern "C" void func_0055C740(Array *a, int *first, int *last);
extern "C" void func_0055C7E0(Array *a, int *pos, unsigned int n, const int &value);

extern "C" void func_0055C690(Array *a, unsigned int n, int value)
{
    unsigned int size = a->count;
    if (n == size)
        return;
    if (n < size)
        func_0055C740(a, a->data + n, a->data + size);
    else
        func_0055C7E0(a, a->data + size, n - size, value);
}
