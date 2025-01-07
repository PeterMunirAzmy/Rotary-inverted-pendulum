#include <Arduino.h>
#include "DualEncoder.h"
#include "ESP32Encoder.h"

// Enc0A_Pin int8 [1,1] Non tunable
// Enc0B_Pin int8 [1,1] Non tunable
// Enc1A_Pin int8 [1,1] Non tunable
// Enc1B_Pin int8 [1,1] Non tunable

ESP32Encoder encoder[2]; 


void setupFunctionDualEncoder(int8_T  Enc0A_Pin,int size_vector__1,int8_T  Enc0B_Pin,int size_vector__2,int8_T  Enc1A_Pin,int size_vector__3,int8_T  Enc1B_Pin,int size_vector__4){
    encoder[0].attachFullQuad(Enc0A_Pin, Enc0B_Pin);
    encoder[1].attachFullQuad(Enc1A_Pin, Enc1B_Pin);
    encoder[1].setCount(1200);
}

// Enc0_Count int64 [1,1]
// Enc1_Count int64 [1,1]
// Reset_Enc0 int8 [1,1]
// Reset_Enc1 int8 [1,1]

void stepFunctionDualEncoder(long long * Enc0_Count,int size_vector_1,long long *  Enc1_Count,int size_vector_2,int8_T Reset_Enc0,int size_vector_a,int8_T Reset_Enc1,int size_vector_b){
    if (Reset_Enc0 > 0) encoder[0].setCount(0);
    if (Reset_Enc1 > 0) encoder[1].setCount(1200);
    *Enc0_Count = encoder[0].getCount();
    *Enc1_Count = encoder[1].getCount();
}