#import <Metal/Metal.h>
#include <stdlib.h>
#include <stdio.h>
#import <Foundation/Foundation.h>

#include "setup.h"

#define prtErr(X) { fprintf(stderr, "ERROR: %s\n", X); exit(1); }

id<MTLDevice> device;
id<MTLCommandQueue> commandQueue;
id<MTLLibrary> library;

void gsetup() {
    device = MTLCreateSystemDefaultDevice();
    if (!device) prtErr("No compatile GPU for Metal found.");

    commandQueue = [device newCommandQueue];
    if (!commandQueue) prtErr("Failed to create command queue.");

    library = [device newDefaultLibrary];
    if (!library) prtErr("Failed to load Metal library.");
}