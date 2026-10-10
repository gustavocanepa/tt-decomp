/* compiler: ee-gcc2.96-nosib */
/* The engine's allocation entry (440 callers): 4-byte aligned blocks go to the engine heap,
 * func_002BD840, which takes only the size (align and name stay in $a1/$a2 untouched); any
 * other alignment goes to memalign (func_004AE750). */
void *func_002BD840(unsigned int size);
void *func_004AE750(int align, unsigned int size);

void *func_002BDA28(unsigned int size, int align, const char *name)
{
    if (size == 0)
        return 0;
    if (align == 4)
        return func_002BD840(size);
    return func_004AE750(align, size);
}
