#include "mat3.h"
#include <string.h>

Mat3 mat3(const float arr[9]) 
{
    Mat3 mat;
    memcpy(mat.m, arr, 9*sizeof(float));
    return mat;
}

Mat3 mat3_zro() 
{
    return (Mat3){0};
}

Mat3 mat3_ity() 
{
    return (Mat3) {{
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    }};
}

Mat3 mat3_add(const Mat3* m1, const Mat3* m2) 
{
    Mat3 mat;
    
    for(int i = 0; i<9; i++) {
        mat.m[i] = m1->m[i] + m2->m[i];
    }

    return mat;
}

Mat3 mat3_sub(const Mat3* m1, const Mat3* m2) 
{
    Mat3 mat;

    for(int i = 0; i<9; i++) {
        mat.m[i] = m1->m[i] - m2->m[i];
    }

    return mat;
}

Mat3 mat3_scl(const Mat3* m, float scalar) 
{
    Mat3 mat;

    for(int i = 0; i<9; i++) {
        mat.m[i] = m->m[i] * scalar;
    }

    return mat;
}

Mat3 mat3_mul(const Mat3* m1, const Mat3* m2) 
{
    Mat3 mat; 

    for(int i = 0; i<3; i++) {
        int i3 = i * 3;
        for (int j = 0; j < 3; j++) {
            float sum = 0;
            
            for (int k = 0; k < 3; k++) {
                sum += m1->m[i3 + k] * m2->m[k*3 + j];    
            }

            mat.m[i3 + j] = sum;
        }
    }

    return mat;
}

Mat3 mat3_tpo(const Mat3* m) 
{
    Mat3 mat;

    for(int i = 0; i<3; i++) {
        int i3 = i * 3;
        
        for (int j = 0; j < 3; j++) {
            mat.m[i3 + j] = m->m[j*3 + i];
        }
    }

    return mat;
}

float mat3_Det(const Mat3* m) 
{
    return m->m[0] * (m->m[4] * m->m[8] - m->m[5] * m->m[7]) -
           m->m[1] * (m->m[3] * m->m[8] - m->m[5] * m->m[6]) +
           m->m[2] * (m->m[3] * m->m[7] - m->m[4] * m->m[6]);
}

Mat3 mat3_inv(const Mat3* m) {
    Mat3 inv;
    float det = mat3_det(m);
    if (det == 0) return mat3_ity();

    float invDet = 1.0f / det;

    // ???
    inv.m[0] =  (m->m[4] * m->m[8] - m->m[5] * m->m[7]) * invDet;
    inv.m[1] = -(m->m[1] * m->m[8] - m->m[2] * m->m[7]) * invDet;
    inv.m[2] =  (m->m[1] * m->m[5] - m->m[2] * m->m[4]) * invDet;
    inv.m[3] = -(m->m[3] * m->m[8] - m->m[5] * m->m[6]) * invDet;
    inv.m[4] =  (m->m[0] * m->m[8] - m->m[2] * m->m[6]) * invDet;
    inv.m[5] = -(m->m[0] * m->m[5] - m->m[2] * m->m[3]) * invDet;
    inv.m[6] =  (m->m[3] * m->m[7] - m->m[4] * m->m[6]) * invDet;
    inv.m[7] = -(m->m[0] * m->m[7] - m->m[1] * m->m[6]) * invDet;
    inv.m[8] =  (m->m[0] * m->m[4] - m->m[1] * m->m[3]) * invDet;

    return inv;
}