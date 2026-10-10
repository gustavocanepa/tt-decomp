/* The element class has no known name: named after its constructor (func_003CA1C8) so that
   __13func_00409940 resolves. */
struct func_003CA1C8 {
    func_003CA1C8();
    char pad[0x50];
};

/* Named after its own constructor. The array member is built by the compiler's countdown loop. */
struct func_003CA210 {
    float a;
    float b;
    int c;
    func_003CA1C8 e[4];
    func_003CA210();
};

func_003CA210::func_003CA210() : a(1.0f), b(1.0f), c(0)
{
}
