#include <math.h>
#include <float.h>

#include "math/vector3.h"

Vec3 vec3(float x, float y, float z) 
{
    return (Vec3) {x, y, z};
}

Vec3 vec3Add(Vec3 v1, Vec3 v2)
{
    return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vec3 vec3Sub(Vec3 v1, Vec3 v2)
{
    return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3 vec3Scale(Vec3 v, float scalar)
{
    return vec3(v.x * scalar, v.y * scalar, v.z * scalar);
}

float vec3Dot(Vec3 a, Vec3 b) 
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float vec3Len(Vec3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vec3 vec3Norm(Vec3 v)
{

    float length = vec3Len(v);
    if (length == 0.f) return vec3(0, 0, 0);

    return vec3Scale(v, 1.f / length);
}

Vec3 vec3Lerp(Vec3 a, Vec3 b, float t)
{
    t = fmaxf(0.f, fminf(t, 1.f));
    return vec3(
        a.x + t * (b.x - a.x),
        a.y + t * (b.y - a.y),
        a.z + t * (b.z - a.z)
    );
}

Vec3 vec3Cross(Vec3 a, Vec3 b) 
{
    return vec3(
        a.y * b.z - a.z * b.y, 
        a.z * b.x - a.x * b.z, 
        a.x * b.y - a.y * b.x
    );
}

float vec3Angle(Vec3 a, Vec3 b)
{
    float lenA = vec3Len(a);    
    float lenB = vec3Len(b);

    if (lenA < FLT_EPSILON || lenB < FLT_EPSILON) 
        return NAN;

    return acosf(fmaxf(-1.f, 
        fminf(vec3Dot(a, b) / (lenA * lenB), 1.f))); 
}

Vec3 vec3Proj(Vec3 a, Vec3 b)
{
    return vec3Scale(b, 
        vec3Dot(a, b) / vec3Dot(b, b));
}

Vec3 vec3Refl(Vec3 v, Vec3 normal)
{
    return vec3Sub(v, vec3Scale(vec3Proj(v, normal), 2.f)); 
}

float vec3Dist(Vec3 a, Vec3 b)
{
    return vec3Len(vec3Sub(a, b));;
}

Vec3 vec3Rotate(Vec3 v, Vec3 axis, float angle) 
{
    Vec3 normAxis = vec3Norm(axis);

    Vec3 rlt = vec3Add(
        vec3Add(
            vec3Scale(v, cosf(angle)), 
            vec3Scale(vec3Cross(normAxis, v), sinf(angle))
        ), 
        vec3Scale(normAxis, vec3Dot(normAxis, v) * (1 - cosf(angle)))
    );

    return rlt;
}   