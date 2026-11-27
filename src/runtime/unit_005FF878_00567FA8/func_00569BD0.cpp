/* compiler: ee-gcc2.96-stl */
/* func_00569BD0: vector<char>::insert(pos, n, x) (SGI STL stl_vector.h) with the default pool allocator */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
typedef vector<char> ByteVector;
template void ByteVector::insert(char *position, size_t n, const char &x);
