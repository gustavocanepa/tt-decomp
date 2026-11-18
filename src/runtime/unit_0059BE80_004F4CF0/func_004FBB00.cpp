/* compiler: ee-gcc2.9-991111 */
/* Byte ring buffer header (data follows at +0x10), see func_005AEFA8. */
struct RingBuffer {
	int capacity;
	int count;
	char *readPos;
	char *writePos;
	char data[1];
};

extern "C" RingBuffer D_0078BD40;

extern "C" RingBuffer *func_004FBB00(int capacity)
{
	RingBuffer *rb = &D_0078BD40;
	rb->capacity = capacity;
	rb->count = 0;
	rb->writePos = rb->data;
	rb->readPos = rb->data;
	return rb;
}
