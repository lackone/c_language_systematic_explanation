#include <stdio.h>
#include <memory.h>

int main() {
    // restrict 表示内存不重叠的

    //void * memcpy(void * dest, const void *src, size_t count)
    //void * memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _Size)

    //memmove没有restrict，表示内存允许重叠

    return 0;
}
