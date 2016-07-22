//
//  main.c
//  simd_c_test_02
//
//  Created by PARK JAICHANG on 7/21/16.
//  Copyright © 2016 JAICHANGPARK. All rights reserved.
//

#include <stdio.h>
#include <emmintrin.h>
#include <simd/simd.h>
#include <xmmintrin.h>
#include <immintrin.h>

int main(int argc, const char * argv[]) {
    
    /*
    
     #ps : p = pack  : 병렬 연산을 수행
            s = sigle precision floating point :  32비트 float형 실수 연산
     
     #ss : s = scalar : 128bit 데이터형 중에서 하위 32bit위치만 연산하는것을 의미
            s = sigle precision floating point :  32비트 float형 실수 연산
     
     1. set functuon.
     
      = 사용자가 원하는 값을 128bit메로리에 넣을 수 있다.
     
    short R[8] = {1,1,1,1,1,1,1,1};
    
    __m128i xmmR = _mm_setzero_si128(); // 0으로 초기화
    _mm_store_si128((__m128i*)R, xmmR); // 결과 출력
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    xmmR = _mm_set_epi16(8, 7, 6, 5, 4, 3, 2, 1); // 메모리에 순서대로 값 입력
    _mm_store_si128((__m128i*)R, xmmR); // 결과 출력
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    xmmR = _mm_set1_epi16(7);
    _mm_store_si128((__m128i*)R, xmmR); // 결과 출력
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    xmmR = _mm_setr_epi16(8, 7, 6, 5, 4, 3, 2, 1);
    _mm_store_si128((__m128i*)R, xmmR); // 결과 출력
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
     
    
    2. 논리 연산
    
    short A[8] = {1,0,1,0,1,0,1,0};
    short B[8] = {1,1,1,1,0,0,0,0};
    short Result[8] = {0};
    
    __m128i xmmA = _mm_load_si128((__m128i*)A);
    __m128i xmmB = _mm_load_si128((__m128i*)B);
    
    __m128i xmmR = _mm_and_si128(xmmA, xmmB);   // and 연산
    _mm_store_si128((__m128i*)Result, xmmR);
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
    
    xmmR = _mm_or_si128(xmmA, xmmB);        // or 연산
    _mm_store_si128((__m128i*)Result, xmmR);
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
    
    xmmR = _mm_xor_si128(xmmA, xmmB);       // xor 연산
    _mm_store_si128((__m128i*)Result, xmmR);
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
    
    xmmR = _mm_andnot_si128(xmmA, xmmB);    // not and 연산 (and + bubble)
    _mm_store_si128((__m128i*)Result, xmmR);
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
     
     3. 쉬프트 연산
    
    short A[8] = {1,2,3,4,5,6,7,8};
    short B[8] = {-1,-2,-3,-4,-5,-6,-7,-8};
    short Result[8] = {0};
    
    __m128i xmmA = _mm_load_si128((__m128i*)A); // 양수값 입력
    __m128i xmmB = _mm_load_si128((__m128i*)B); // 음수값 입력
    
    __m128i xmmR = _mm_slli_epi16(xmmA, 1); //양수 왼쪽 쉬프트 연산
    _mm_store_si128((__m128i*)Result, xmmR); // 연산된 결과 저장
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
    
    xmmR = _mm_slli_epi16(xmmB, 1);         // 음수 왼쪽 쉬프트 연산
    _mm_store_si128((__m128i*)Result, xmmR); // 연산된 결과 저장
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
    //왼쪽 쉬프트 연산에 대해서는 양수와 음수 모두 결과에 이상이 없다.
    
    
    xmmR = _mm_srai_epi16(xmmA, 1); // 양수 산술적 오른쪽 쉬프트 연산
    _mm_store_si128((__m128i*)Result, xmmR); // 연산된 결과 저장
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
    
    xmmR = _mm_srli_epi16(xmmA, 1); //양수 논리적 오른쪽 쉬프트 연산
    _mm_store_si128((__m128i*)Result, xmmR); // 연산된 결과 저장
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
    
    xmmR = _mm_srai_epi16(xmmB, 1); //음수 산술적 오른쪽 쉬프트 연산
    _mm_store_si128((__m128i*)Result, xmmR); // 연산된 결과 저장
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
    
    xmmR = _mm_srli_epi16(xmmB, 1); //음수 논리적 오른쪽 쉬프트 연산
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
    
    //양수일때 오른쪽 쉬프트 연산의 경우 산술적, 논리적연산은 문제 없다 .
    //음수일때 논리적 오른쪽 연산의 경우 오류가 발생 --> 음수 일때는 산술적 쉬프트 연산을 이용하자.
     
     
    
    4. 정수의 나눗셈 연산  !! 정수는 나눗셈을 지원하지 않는다.
     
    short nA = 149;
    short nB = 9;
    short nR = nA/nB;
    
    printf("C Div : %d / %d = %d\n",nA,nB,nR);
    short A[8] = {149,149,149,149,149,149,149,149};
    short R[8] = {0};
    
    __m128i xmmA = _mm_load_si128((__m128i*)A);
    __m128i xmmB = _mm_set1_epi16(256/9);
    
    xmmA = _mm_mullo_epi16(xmmA, xmmB); // 28[256/9] * 149
    __m128i xmmR = _mm_srai_epi16(xmmA, 8);
    
    _mm_store_si128((__m128i*)R, xmmR);
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    
    
    5. 비교 연산
     true = -1 or oxffff, false = 0 출력
    
    short A[8] = {1,0,1,0,1,0,1,0};
    short B[8] = {1,1,1,1,0,0,0,0};
    short R[8] = {0};
    
    __m128i xmmA = _mm_load_si128((__m128i*)A);
    __m128i xmmB = _mm_load_si128((__m128i*)B);
    
    __m128i xmmR = _mm_cmpeq_epi16(xmmA, xmmB); // 정수 상등 함수 a == b
    _mm_store_si128((__m128i*)R, xmmR);
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    xmmR = _mm_cmpgt_epi16(xmmA, xmmB); // 정수 상등 함수 a > b
    _mm_store_si128((__m128i*)R, xmmR);
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    xmmR = _mm_cmplt_epi16(xmmA, xmmB); // 정수 상등 함수 a < b
    _mm_store_si128((__m128i*)R, xmmR);
    printf("Result : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    */
    
    
    //6. 형변환 함수
    
    float FloatA[4] = {1.0,2.0,3.0,4.0};
    int IntR[4] = {0};
    
    int IntA[4] = {1,2,3,4};
    float FloatR[4] = {0};
    
    __m128 xmmA = _mm_load_ps(FloatA); // align 입력
    __m128 ixmmA = _mm_loadu_si128((__m128i*)IntA);
    
    __m128i ixmmR = _mm_cvtps_epi32(xmmA); // 실수형 pack --->> 정수형 pack
    _mm_store_si128((__m128i*)IntR, ixmmR);
    printf("Convert float to Integer : %d, %d, %d, %d \n ",IntR[3],IntR[2],IntR[1],IntR[0]);
    
    __m128 xmmR = _mm_cvtepi32_ps(ixmmA); // 정수형 pack  --- >> 실수형 pack 
    _mm_store_ps(FloatR, xmmR);
    printf("Convert integer to Float : %f, %.3f, %.3f, %.3f \n ",FloatR[3],FloatR[2],FloatR[1],FloatR[0]);
    
    
    
    return 0;
}
