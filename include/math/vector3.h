#ifndef VEC3_H
#define VEC3_H

typedef struct {
    float x, y, z;
} Vec3;

/**
 * @brief   Creates a new 3D vector.
 * @param   x   X-axis coordinate.
 * @param   y   Y-axis coordinate.
 * @param   z   Z-axis coordinate.
 * @return  A 3D vector with the specified coordinates.
 */
Vec3 vec3(float x, float y, float z);

#ifdef __APPLE__

Vec3 gvec3Add(Vec3 v1, Vec3 v2);

#endif

/**
 * @brief   Adds two 3D vectors and returns a new 3D vector.
 * @param   v1 First vector.
 * @param   v2 Second vector.
 * @return  A 3D vector representing the sum of v1 and v2.
 */
Vec3 vec3Add(Vec3 v1, Vec3 v2);

/**
 * @brief   Subtracts two 3D vectors and returns a new 3D vector.
 * @param   v1 First vector.
 * @param   v2 Second vector.
 * @return  A 3D vector representing the result of v1 minus v2.
 */
Vec3 vec3Sub(Vec3 v1, Vec3 v2);

/**
 * @brief   Scales a 3D vector by a constant scalar and returns a new 3D vector.
 * @param   v      3D vector.
 * @param   scalar Scalar value.
 * @return  A 3D vector representing the multiplication of v by the scalar.
 */
Vec3 vec3Scale(Vec3 v, float scalar);

/**
 * @brief   Computes the dot product of two 3D vectors.
 * @param   a First vector.
 * @param   b Second vector.
 * @return  A scalar value representing the dot product of a and b.
 *          - scalar > 0: Both vectors have the same orientation (the angle between them is acute).
 *          - scalar = 0: Vectors are orthogonal (the angle between them is 90 degrees).
 *          - scalar < 0: Vectors have opposite orientations (the angle between them is obtuse).
 */
float vec3Dot(Vec3 a, Vec3 b);

/**
 * @brief   Computes the length (magnitude) of a 3D vector.
 * @param   v 3D vector.
 * @return  A scalar value representing the length (magnitude) of the vector v.
 */
float vec3Len(Vec3 v);

/**
 * @brief   Normalizes a 3D vector (scales it to unit length).
 * @param   v 3D vector.
 * @return  A 3D vector representing the normalized version of v.
 *          Returns a zero vector (0, 0, 0) if the input vector is a zero vector.
 */
Vec3 vec3Norm(Vec3 v);

/**
 * @brief   Performs linear interpolation between two 3D vectors.
 * @param   a Start vector.
 * @param   b End vector.
 * @param   t Interpolation factor (0.0 to 1.0).
 *             - t = 0 returns the vector a.
 *             - t = 1 returns the vector b.
 *             - t between 0 and 1 returns a point between a and b.
 * @return  A 3D vector representing the interpolated result between a and b.
 */
Vec3 vec3Lerp(Vec3 a, Vec3 b, float t);

/**
 * @brief   Computes the cross product of two 3D vectors.
 *          The cross product produces a new vector that is orthogonal (perpendicular) to both input vectors.
 *          The direction of the resulting vector follows the right-hand rule.
 * @param   a First vector.
 * @param   b Second vector.
 * @return  A 3D vector representing the cross product of vectors a and b.
 */
Vec3 vec3Cross(Vec3 a, Vec3 b);

/**
 * @brief   Computes the angle between two 3D vectors.
 * @param   a First vector.
 * @param   b Second vector.
 * @return  The angle between vectors a and b in radians.
 */
float vec3Angle(Vec3 a, Vec3 b);

/**
 * @brief   Computes the projection of vector a onto vector b.
 * @param   a The vector to be projected.
 * @param   b The vector onto which a is projected.
 * @return  A 3D vector representing the projection of a onto b.
 */
Vec3 vec3Proj(Vec3 a, Vec3 b);

/**
 * @brief   Computes the reflection of a vector v against a normal.
 * @param   v The incident vector.
 * @param   normal The normal vector of the surface.
 * @return  A 3D vector representing the reflection of v across normal.
 */
Vec3 vec3Refl(Vec3 v, Vec3 normal);

/**
 * @brief   Computes the Euclidean distance between two 3D vectors.
 * @param   a The first vector.
 * @param   b The second vector.
 * @return  The scalar distance between a and b.
 */
float vec3Dist(Vec3 a, Vec3 b);

/**
 * @brief   Rotates a 3D vector around a given axis by a specified angle.
 * @param   v The vector to rotate.
 * @param   axis The rotation axis (must be normalized).
 * @param   angle Rotation angle in radians.
 * @return  A 3D vector representing the rotated vector.
 */
Vec3 vec3Rotate(Vec3 v, Vec3 axis, float angle);

#endif // VEC3_H