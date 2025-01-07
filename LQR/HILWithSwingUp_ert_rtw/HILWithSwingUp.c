/*
 * File: HILWithSwingUp.c
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
#include "HILWithSwingUp_types.h"
#include "rtwtypes.h"
#include "HILWithSwingUp_private.h"
#include <math.h>
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include <float.h>

/* Named constants for Chart: '<Root>/Chart1' */
#define HILWithSwingUp_IN_balance      (1U)
#define HILWithSwingUp_IN_swing        (2U)

/* Block signals (default storage) */
B_HILWithSwingUp_T HILWithSwingUp_B;

/* Block states (default storage) */
DW_HILWithSwingUp_T HILWithSwingUp_DW;

/* Real-time model */
static RT_MODEL_HILWithSwingUp_T HILWithSwingUp_M_;
RT_MODEL_HILWithSwingUp_T *const HILWithSwingUp_M = &HILWithSwingUp_M_;

/* Forward declaration for local functions */
static void HILWithSwing_SystemCore_release(codertarget_arduinobase_inter_T *obj);
real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  uint32_T cb;
  uint32_T u1i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void HILWithSwing_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  /* Start for MATLABSystem: '<Root>/Enable pin' */
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }

  /* End of Start for MATLABSystem: '<Root>/Enable pin' */
}

/* Model step function */
void HILWithSwingUp_step(void)
{
  int64m_T b_varargout_1;
  int64m_T b_varargout_2;
  real_T rtb_Sum1;
  real_T rtb_theta0rad;
  real_T u0;
  uint8_T tmp;
  static const int64m_T tmp_0 = { { 0U, 0U }/* chunks */
  };

  /* MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Constant: '<Root>/reset encoders'
   */
  if (HILWithSwingUp_DW.obj.SampleTime !=
      HILWithSwingUp_P.MATLABSystem_SampleTime) {
    HILWithSwingUp_DW.obj.SampleTime = HILWithSwingUp_P.MATLABSystem_SampleTime;
  }

  /*         %% Define output properties */
  b_varargout_1 = tmp_0;
  b_varargout_2 = tmp_0;
  stepFunctionDualEncoder(&b_varargout_1, 1.0, &b_varargout_2, 1.0,
    HILWithSwingUp_P.resetencoders_Value, 1.0,
    HILWithSwingUp_P.resetencoders_Value, 1.0);

  /* End of MATLABSystem: '<Root>/MATLAB System' */

  /* Gain: '<Root>/Gain3' */
  rtb_theta0rad = HILWithSwingUp_P.Gain3_Gain * sMultiWord2Double
    (&b_varargout_1.chunks[0U], 2, 0);

  /* Switch: '<S5>/Switch' */
  if (rtb_theta0rad > HILWithSwingUp_P.Switch_Threshold) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Bias: '<S5>/Bias'
     *  Bias: '<S5>/Bias1'
     *  Constant: '<S5>/Constant1'
     *  Math: '<S5>/Rem'
     */
    HILWithSwingUp_B.Switch = rt_remd_snf(rtb_theta0rad +
      HILWithSwingUp_P.Bias_Bias, HILWithSwingUp_P.Constant1_Value_i) +
      HILWithSwingUp_P.Bias1_Bias_l;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  Bias: '<S5>/Bias2'
     *  Bias: '<S5>/Bias3'
     *  Constant: '<S5>/Constant2'
     *  Math: '<S5>/Rem1'
     */
    HILWithSwingUp_B.Switch = rt_remd_snf(rtb_theta0rad +
      HILWithSwingUp_P.Bias2_Bias_p, HILWithSwingUp_P.Constant2_Value_b) +
      HILWithSwingUp_P.Bias3_Bias_p;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Gain: '<Root>/Gain2'
   */
  rtb_Sum1 = HILWithSwingUp_P.Gain2_Gain * sMultiWord2Double
    (&b_varargout_2.chunks[0U], 2, 0) + HILWithSwingUp_P.Constant3_Value;

  /* Math: '<S4>/Rem' incorporates:
   *  Bias: '<S4>/Bias'
   *  Constant: '<S4>/Constant1'
   */
  HILWithSwingUp_B.Rem = rt_remd_snf(rtb_Sum1 + HILWithSwingUp_P.Bias_Bias_d,
    HILWithSwingUp_P.Constant1_Value_j);

  /* Switch: '<S4>/Switch' */
  if (rtb_Sum1 > HILWithSwingUp_P.Switch_Threshold_p) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Bias: '<S4>/Bias1'
     */
    HILWithSwingUp_B.Switch_e = HILWithSwingUp_B.Rem +
      HILWithSwingUp_P.Bias1_Bias;
  } else {
    /* Switch: '<S4>/Switch' incorporates:
     *  Bias: '<S4>/Bias2'
     *  Bias: '<S4>/Bias3'
     *  Constant: '<S4>/Constant2'
     *  Math: '<S4>/Rem1'
     */
    HILWithSwingUp_B.Switch_e = rt_remd_snf(rtb_Sum1 +
      HILWithSwingUp_P.Bias2_Bias, HILWithSwingUp_P.Constant2_Value) +
      HILWithSwingUp_P.Bias3_Bias;
  }

  /* End of Switch: '<S4>/Switch' */

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_theta0rad *= HILWithSwingUp_P.TSamp_WtEt;

  /* Sum: '<S3>/Diff' incorporates:
   *  UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  HILWithSwingUp_B.Diff = rtb_theta0rad - HILWithSwingUp_DW.UD_DSTATE;

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Sum1 *= HILWithSwingUp_P.TSamp_WtEt_b;

  /* Sum: '<S2>/Diff' incorporates:
   *  UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  HILWithSwingUp_B.Diff_f = rtb_Sum1 - HILWithSwingUp_DW.UD_DSTATE_a;

  /* Gain: '<Root>/Gain8' incorporates:
   *  SignalConversion generated from: '<Root>/Gain8'
   */
  HILWithSwingUp_B.Gain8 = ((-HILWithSwingUp_P.k[0] * HILWithSwingUp_B.Switch +
    -HILWithSwingUp_P.k[1] * HILWithSwingUp_B.Switch_e) + -HILWithSwingUp_P.k[2]
    * HILWithSwingUp_B.Diff) + -HILWithSwingUp_P.k[3] * HILWithSwingUp_B.Diff_f;

  /* Switch: '<Root>/Switch4' */
  if (HILWithSwingUp_B.Gain8 > HILWithSwingUp_P.Switch4_Threshold) {
    /* Switch: '<Root>/Switch4' incorporates:
     *  Constant: '<Root>/Constant'
     */
    HILWithSwingUp_B.controlaction = HILWithSwingUp_P.Constant_Value;
  } else {
    /* Switch: '<Root>/Switch4' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    HILWithSwingUp_B.controlaction = HILWithSwingUp_P.Constant1_Value;
  }

  /* End of Switch: '<Root>/Switch4' */

  /* Gain: '<Root>/Gain' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  HILWithSwingUp_B.Gain = HILWithSwingUp_P.Gain_Gain *
    HILWithSwingUp_P.Constant2_Value_c;

  /* Abs: '<Root>/Abs1' */
  HILWithSwingUp_B.Abs1 = fabs(HILWithSwingUp_B.Switch_e);

  /* Chart: '<Root>/Chart1' */
  if (HILWithSwingUp_DW.is_active_c1_HILWithSwingUp == 0U) {
    HILWithSwingUp_DW.is_active_c1_HILWithSwingUp = 1U;
    HILWithSwingUp_DW.is_c1_HILWithSwingUp = HILWithSwingUp_IN_swing;
    HILWithSwingUp_B.pwm = 255.0 * HILWithSwingUp_B.controlaction;
  } else if (HILWithSwingUp_DW.is_c1_HILWithSwingUp == HILWithSwingUp_IN_balance)
  {
    if (HILWithSwingUp_B.Abs1 > HILWithSwingUp_B.Gain) {
      HILWithSwingUp_DW.is_c1_HILWithSwingUp = HILWithSwingUp_IN_swing;
      HILWithSwingUp_B.pwm = 255.0 * HILWithSwingUp_B.controlaction;
    } else {
      HILWithSwingUp_B.pwm = HILWithSwingUp_B.Gain8;
    }

    /* case IN_swing: */
  } else if (HILWithSwingUp_B.Abs1 < HILWithSwingUp_B.Gain) {
    HILWithSwingUp_DW.is_c1_HILWithSwingUp = HILWithSwingUp_IN_balance;
    HILWithSwingUp_B.pwm = HILWithSwingUp_B.Gain8;
  } else if (HILWithSwingUp_B.Abs1 > HILWithSwingUp_B.Gain) {
    HILWithSwingUp_DW.is_c1_HILWithSwingUp = HILWithSwingUp_IN_swing;
    HILWithSwingUp_B.pwm = 255.0 * HILWithSwingUp_B.controlaction;
  } else {
    HILWithSwingUp_B.pwm = 255.0 * HILWithSwingUp_B.controlaction;
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Switch: '<Root>/Switch5' */
  if (HILWithSwingUp_B.pwm > HILWithSwingUp_P.Switch5_Threshold) {
    /* Switch: '<Root>/Switch5' incorporates:
     *  Constant: '<Root>/Constant7'
     */
    HILWithSwingUp_B.Switch5 = HILWithSwingUp_P.Constant7_Value;
  } else {
    /* Switch: '<Root>/Switch5' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    HILWithSwingUp_B.Switch5 = HILWithSwingUp_P.Constant6_Value;
  }

  /* End of Switch: '<Root>/Switch5' */

  /* MATLABSystem: '<Root>/Digital Output' */
  u0 = rt_roundd_snf(HILWithSwingUp_B.Switch5);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */
  /* Switch: '<Root>/Switch6' */
  if (HILWithSwingUp_B.pwm > HILWithSwingUp_P.Switch6_Threshold) {
    /* Switch: '<Root>/Switch6' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    HILWithSwingUp_B.Switch6 = HILWithSwingUp_P.Constant6_Value;
  } else {
    /* Switch: '<Root>/Switch6' incorporates:
     *  Constant: '<Root>/Constant9'
     */
    HILWithSwingUp_B.Switch6 = HILWithSwingUp_P.Constant9_Value;
  }

  /* End of Switch: '<Root>/Switch6' */

  /* MATLABSystem: '<Root>/Digital Output1' */
  u0 = rt_roundd_snf(HILWithSwingUp_B.Switch6);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(12, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output1' */
  /* Switch: '<Root>/Switch7' incorporates:
   *  Constant: '<Root>/Constant11'
   *  Constant: '<Root>/Constant8'
   */
  if (HILWithSwingUp_B.pwm > HILWithSwingUp_P.Switch7_Threshold) {
    u0 = HILWithSwingUp_P.Constant8_Value;
  } else {
    u0 = HILWithSwingUp_P.Constant11_Value;
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  Abs: '<Root>/Abs4'
   *  Constant: '<Root>/Constant10'
   *  Switch: '<Root>/Switch7'
   */
  HILWithSwingUp_B.Saturation = (u0 + HILWithSwingUp_P.PWMBias) + fabs
    (HILWithSwingUp_B.pwm);

  /* Saturate: '<Root>/Saturation' */
  if (HILWithSwingUp_B.Saturation > HILWithSwingUp_P.PWMSat) {
    /* Sum: '<Root>/Sum2' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    HILWithSwingUp_B.Saturation = HILWithSwingUp_P.PWMSat;
  } else if (HILWithSwingUp_B.Saturation < HILWithSwingUp_P.Saturation_LowerSat)
  {
    /* Sum: '<Root>/Sum2' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    HILWithSwingUp_B.Saturation = HILWithSwingUp_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain7' */
  u0 = HILWithSwingUp_P.Gain7_Gain * HILWithSwingUp_B.Saturation;

  /* Start for MATLABSystem: '<Root>/Enable pin' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  /* MATLABSystem: '<Root>/Enable pin' */
  HILWithSwingUp_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);

  /* Start for MATLABSystem: '<Root>/Enable pin' */
  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* MATLABSystem: '<Root>/Enable pin' */
  MW_PWM_SetDutyCycle(HILWithSwingUp_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, -(u0 *
    255.0 / 255.0));

  /* Gain: '<Root>/Gain6' */
  HILWithSwingUp_B.Gain6 = HILWithSwingUp_P.Gain6_Gain *
    HILWithSwingUp_B.Switch_e;

  /* Gain: '<Root>/Gain9' */
  HILWithSwingUp_B.Gain9 = HILWithSwingUp_P.Gain9_Gain * HILWithSwingUp_B.Switch;

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  HILWithSwingUp_DW.UD_DSTATE = rtb_theta0rad;

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  HILWithSwingUp_DW.UD_DSTATE_a = rtb_Sum1;

  {                                    /* Sample time: [0.005s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  HILWithSwingUp_M->Timing.taskTime0 =
    ((time_T)(++HILWithSwingUp_M->Timing.clockTick0)) *
    HILWithSwingUp_M->Timing.stepSize0;
}

/* Model initialize function */
void HILWithSwingUp_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(HILWithSwingUp_M, -1);
  HILWithSwingUp_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  HILWithSwingUp_M->Sizes.checksums[0] = (1589293002U);
  HILWithSwingUp_M->Sizes.checksums[1] = (190959474U);
  HILWithSwingUp_M->Sizes.checksums[2] = (2515612482U);
  HILWithSwingUp_M->Sizes.checksums[3] = (1621355825U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[16];
    HILWithSwingUp_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(HILWithSwingUp_M->extModeInfo,
      &HILWithSwingUp_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(HILWithSwingUp_M->extModeInfo,
                        HILWithSwingUp_M->Sizes.checksums);
    rteiSetTPtr(HILWithSwingUp_M->extModeInfo, rtmGetTPtr(HILWithSwingUp_M));
  }

  /* InitializeConditions for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  HILWithSwingUp_DW.UD_DSTATE = HILWithSwingUp_P.DiscreteDerivative3_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  HILWithSwingUp_DW.UD_DSTATE_a =
    HILWithSwingUp_P.DiscreteDerivative2_ICPrevScale;

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Constructor */
  HILWithSwingUp_DW.obj.matlabCodegenIsDeleted = false;
  HILWithSwingUp_DW.obj.SampleTime = HILWithSwingUp_P.MATLABSystem_SampleTime;
  HILWithSwingUp_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionDualEncoder(27.0, 1.0, 26.0, 1.0, 25.0, 1.0, 33.0, 1.0);
  HILWithSwingUp_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  HILWithSwingUp_DW.obj_p.matlabCodegenIsDeleted = false;
  HILWithSwingUp_DW.obj_p.isInitialized = 1;
  digitalIOSetup(13, 1);
  HILWithSwingUp_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  HILWithSwingUp_DW.obj_m.matlabCodegenIsDeleted = false;
  HILWithSwingUp_DW.obj_m.isInitialized = 1;
  digitalIOSetup(12, 1);
  HILWithSwingUp_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Enable pin' */
  HILWithSwingUp_DW.obj_l.matlabCodegenIsDeleted = false;
  HILWithSwingUp_DW.obj_l.isInitialized = 1;
  HILWithSwingUp_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(14U, 2000.0,
    255.0);
  HILWithSwingUp_DW.obj_l.isSetupComplete = true;
}

/* Model terminate function */
void HILWithSwingUp_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!HILWithSwingUp_DW.obj.matlabCodegenIsDeleted) {
    HILWithSwingUp_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!HILWithSwingUp_DW.obj_p.matlabCodegenIsDeleted) {
    HILWithSwingUp_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!HILWithSwingUp_DW.obj_m.matlabCodegenIsDeleted) {
    HILWithSwingUp_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
  /* Terminate for MATLABSystem: '<Root>/Enable pin' */
  if (!HILWithSwingUp_DW.obj_l.matlabCodegenIsDeleted) {
    HILWithSwingUp_DW.obj_l.matlabCodegenIsDeleted = true;
    HILWithSwing_SystemCore_release(&HILWithSwingUp_DW.obj_l);
  }

  /* End of Terminate for MATLABSystem: '<Root>/Enable pin' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
