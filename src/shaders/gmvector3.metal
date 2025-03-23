#include <metal_stdlib>
using namespace metal;

struct Vec3 {
    float x, y, z;
};

kernel void gvec3Add(const device Vec3 v1 [[buffer(0)]], const device Vec3 v2 [[buffer(1)]],
                     const device Vec3 vo [[buffer(2)]], uint id [[thread_position_in_grid]]) {
    vo[id].x = v1[id].x + v2[id].x;
    vo[id].y = v1[id].y + v2[id].y;
    vo[id].z = v1[id].z + v2[id].z;
}

kernel void gvec3Sub(const device Vec3 v1 [[buffer(0)]], const device Vec3 v2 [[buffer(1)]],
                     const device Vec3 vo [[buffer(2)]], uint id [[thread_position_in_grid]]) {
    vo[id].x = v1[id].x - v2[id].x;
    vo[id].y = v1[id].y - v2[id].y;
    vo[id].z = v1[id].z - v2[id].z;
}