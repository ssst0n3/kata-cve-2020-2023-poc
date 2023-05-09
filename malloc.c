#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define PAGE_SIZE 512000

int main() {
    void *addr;
    size_t map_size;
    size_t num_chunks = 10000000;

    map_size = num_chunks * PAGE_SIZE;
    // addr = mmap(NULL, map_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    // if (addr == MAP_FAILED) {
    //    perror("mmap");
    //    exit(1);
    // }

    for (int i=0; i<num_chunks; i++) {
        char *buf = (char *) malloc(PAGE_SIZE);
	    memset(buf, i % 256, PAGE_SIZE);
	    // memcpy((char *) addr + i * PAGE_SIZE, buf, PAGE_SIZE);
	    // free(buf);
    }

    // if (madvise(addr, map_size, MADV_DONTNEED) < 0) {
     //   perror("madvise");
     //   exit(1);
    // }

    // if (munmap(addr, map_size) < 0){
       // perror("munmap");
       // exit(1);
    // }

    return 0;
}
