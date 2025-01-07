/*
 * File: HIL_data.c
 *
 * Code generated for Simulink model 'HIL'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jan  2 10:55:06 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HIL.h"

/* Block parameters (default storage) */
P_HIL_T HIL_P = {
  /* Variable: PWMBias
   * Referenced by: '<Root>/Constant6'
   */
  35.0,

  /* Variable: PWMSat
   * Referenced by: '<Root>/Saturation'
   */
  255.0,

  /* Variable: k
   * Referenced by: '<Root>/Gain4'
   */
  { -1.7320508075683827, 629.27097082282512, -27.187279498519686,
    66.9409193057663 },

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S2>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/MATLAB System'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant5'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<Root>/Constant4'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant7'
   */
  0.0,

  /* Expression: -pi
   * Referenced by: '<S3>/Bias1'
   */
  -3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S3>/Constant2'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S3>/Bias2'
   */
  -3.1415926535897931,

  /* Expression: pi
   * Referenced by: '<S3>/Bias3'
   */
  3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S4>/Constant1'
   */
  6.2831853071795862,

  /* Expression: pi
   * Referenced by: '<S4>/Bias'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S4>/Bias1'
   */
  -3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S4>/Constant2'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S4>/Bias2'
   */
  -3.1415926535897931,

  /* Expression: pi
   * Referenced by: '<S4>/Bias3'
   */
  3.1415926535897931,

  /* Expression: pi
   * Referenced by: '<Root>/Constant'
   */
  3.1415926535897931,

  /* Expression: 2*pi/2400
   * Referenced by: '<Root>/Gain'
   */
  0.0026179938779914941,

  /* Expression: pi
   * Referenced by: '<S3>/Bias'
   */
  3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S3>/Constant1'
   */
  6.2831853071795862,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: 2*pi/2000
   * Referenced by: '<Root>/Gain1'
   */
  0.0031415926535897933,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S2>/TSamp'
   */
  200.0,

  /* Computed Parameter: TSamp_WtEt_e
   * Referenced by: '<S1>/TSamp'
   */
  200.0,

  /* Expression: 0.9
   * Referenced by: '<Root>/Switch1'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gain3'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain6'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain2'
   */
  57.295779513082323,

  /* Expression: int8(0)
   * Referenced by: '<Root>/reset encoders'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
