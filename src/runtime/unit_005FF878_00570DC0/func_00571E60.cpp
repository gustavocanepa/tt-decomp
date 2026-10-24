/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
void *func_004B01B0(void *container, void *key, int *found);

/* Lookup with default: returns the entry when found, else `fallback`. */
void *func_00571E60(void *container, void *key, void *fallback)
{
    int found = 0;
    void *entry = func_004B01B0(container, key, &found);
    return found ? entry : fallback;
}
}
