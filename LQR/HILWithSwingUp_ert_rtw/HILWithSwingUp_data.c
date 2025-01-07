/*
 * File: HILWithSwingUp_data.c
 *
 * Code generated for Simulink model 'HILWithSwingUp'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jan  2 04:50:25 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HILWithSwingUp.h"

/* Block parameters (default storage) */
P_HILWithSwingUp_T HILWithSwingUp_P = {
  /* Variable: PWMBias
   * Referenced by: '<Root>/Constant10'
   */
  35.0,

  /* Variable: PWMSat
   * Referenced by: '<Root>/Saturation'
   */
  255.0,

  /* Variable: k
   * Referenced by: '<Root>/Gain8'
   */
  { -0.31622776601678065, 614.60305316403912, -26.509267699657631,
    65.153242446752785 },

  /* Mask Parameter: DiscreteDerivative3_ICPrevScale
   * Referenced by: '<S3>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative2_ICPrevScale
   * Referenced by: '<S2>/UD'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/MATLAB System'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Constant1'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant7'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant9'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<Root>/Constant8'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant11'
   */
  0.0,

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

  /* Expression: 2*pi
   * Referenced by: '<S5>/Constant1'
   */
  6.2831853071795862,

  /* Expression: pi
   * Referenced by: '<S5>/Bias'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S5>/Bias1'
   */
  -3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S5>/Constant2'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S5>/Bias2'
   */
  -3.1415926535897931,

  /* Expression: pi
   * Referenced by: '<S5>/Bias3'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<Root>/Gain3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Switch'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<Root>/Constant3'
   */
  3.1415926535897931,

  /* Expression: 2*pi/2400
   * Referenced by: '<Root>/Gain2'
   */
  0.0026179938779914941,

  /* Expression: pi
   * Referenced by: '<S4>/Bias'
   */
  3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S4>/Constant1'
   */
  6.2831853071795862,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S3>/TSamp'
   */
  200.0,

  /* Computed Parameter: TSamp_WtEt_b
   * Referenced by: '<S2>/TSamp'
   */
  200.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch4'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant2'
   */
  100.0,

  /* Expression: pi/180
   * Referenced by: '<Root>/Gain'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<Root>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gain7'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain6'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain9'
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
