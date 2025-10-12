/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SRF_PLL_Block.c
 *
 * Code generated for Simulink model 'SRF_PLL_Block'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Sun Oct 12 17:39:43 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SRF_PLL_Block.h"
#include <math.h>
#include "SRF_PLL_Block_private.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <float.h>

/* Block signals (default storage) */
B_SRF_PLL_Block_T SRF_PLL_Block_B;

/* Block states (default storage) */
DW_SRF_PLL_Block_T SRF_PLL_Block_DW;

/* External inputs (root inport signals with default storage) */
ExtU_SRF_PLL_Block_T SRF_PLL_Block_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_SRF_PLL_Block_T SRF_PLL_Block_Y;

/* Real-time model */
static RT_MODEL_SRF_PLL_Block_T SRF_PLL_Block_M_;
RT_MODEL_SRF_PLL_Block_T *const SRF_PLL_Block_M = &SRF_PLL_Block_M_;
real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = !(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void SRF_PLL_Block_step(void)
{
  real_T rtb_VqNormalized;
  int32_T i;
  real32_T tmp[3];
  real32_T Fcn_e_tmp;
  real32_T Fcn_e_tmp_0;
  real32_T rtb_Gain1_idx_0;
  real32_T rtb_Gain1_idx_1;
  real32_T rtb_Sqrt;

  /* Gain: '<S5>/Gain3' incorporates:
   *  Inport: '<Root>/Vabc'
   */
  rtb_Gain1_idx_0 = 0.0F;
  rtb_Gain1_idx_1 = 0.0F;
  rtb_Sqrt = 0.0F;
  for (i = 0; i < 3; i++) {
    rtb_Gain1_idx_0 += SRF_PLL_Block_ConstP.Gain3_Gain[3 * i] *
      SRF_PLL_Block_U.Vabc[i];
    rtb_Gain1_idx_1 += SRF_PLL_Block_ConstP.Gain3_Gain[3 * i + 1] *
      SRF_PLL_Block_U.Vabc[i];
    rtb_Sqrt += SRF_PLL_Block_ConstP.Gain3_Gain[3 * i + 2] *
      SRF_PLL_Block_U.Vabc[i];
  }

  /* End of Gain: '<S5>/Gain3' */

  /* Gain: '<S5>/Gain1' */
  rtb_Gain1_idx_0 *= 0.666666687F;
  rtb_Gain1_idx_1 *= 0.666666687F;

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (SRF_PLL_Block_ConstB.Compare > 0) {
    /* Fcn: '<S10>/Fcn' incorporates:
     *  Delay: '<S1>/Delay'
     *  Fcn: '<S10>/Fcn1'
     */
    Fcn_e_tmp = sinf(SRF_PLL_Block_DW.Delay_DSTATE);
    Fcn_e_tmp_0 = cosf(SRF_PLL_Block_DW.Delay_DSTATE);

    /* Fcn: '<S10>/Fcn' */
    SRF_PLL_Block_B.Fcn_e = rtb_Gain1_idx_0 * Fcn_e_tmp_0 + rtb_Gain1_idx_1 *
      Fcn_e_tmp;

    /* Fcn: '<S10>/Fcn1' */
    SRF_PLL_Block_B.Fcn1_d = -rtb_Gain1_idx_0 * Fcn_e_tmp + rtb_Gain1_idx_1 *
      Fcn_e_tmp_0;
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem - pi//2 delay' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (SRF_PLL_Block_ConstB.Compare_l > 0) {
    /* Fcn: '<S9>/Fcn' incorporates:
     *  Delay: '<S1>/Delay'
     *  Fcn: '<S9>/Fcn1'
     */
    Fcn_e_tmp = cosf(SRF_PLL_Block_DW.Delay_DSTATE);
    Fcn_e_tmp_0 = sinf(SRF_PLL_Block_DW.Delay_DSTATE);

    /* Fcn: '<S9>/Fcn' */
    SRF_PLL_Block_B.Fcn_b = rtb_Gain1_idx_0 * Fcn_e_tmp_0 - rtb_Gain1_idx_1 *
      Fcn_e_tmp;

    /* Fcn: '<S9>/Fcn1' */
    SRF_PLL_Block_B.Fcn1_k = rtb_Gain1_idx_0 * Fcn_e_tmp + rtb_Gain1_idx_1 *
      Fcn_e_tmp_0;
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem - pi//2 delay' */

  /* Switch: '<S2>/Switch' */
  if (SRF_PLL_Block_ConstB.Compare != 0) {
    rtb_Gain1_idx_1 = SRF_PLL_Block_B.Fcn_e;
    rtb_Gain1_idx_0 = SRF_PLL_Block_B.Fcn1_d;
  } else {
    rtb_Gain1_idx_1 = SRF_PLL_Block_B.Fcn_b;
    rtb_Gain1_idx_0 = SRF_PLL_Block_B.Fcn1_k;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Outputs for Enabled SubSystem: '<S64>/Subsystem1' incorporates:
   *  EnablePort: '<S68>/Enable'
   */
  if (SRF_PLL_Block_ConstB.Compare_g > 0) {
    /* Fcn: '<S68>/Fcn' incorporates:
     *  Delay: '<S1>/Delay1'
     *  Fcn: '<S68>/Fcn1'
     */
    Fcn_e_tmp = sinf(SRF_PLL_Block_DW.Delay1_DSTATE);
    Fcn_e_tmp_0 = cosf(SRF_PLL_Block_DW.Delay1_DSTATE);

    /* Fcn: '<S68>/Fcn' */
    SRF_PLL_Block_B.Fcn = rtb_Gain1_idx_1 * Fcn_e_tmp_0 - rtb_Gain1_idx_0 *
      Fcn_e_tmp;

    /* Fcn: '<S68>/Fcn1' */
    SRF_PLL_Block_B.Fcn1 = rtb_Gain1_idx_1 * Fcn_e_tmp + rtb_Gain1_idx_0 *
      Fcn_e_tmp_0;
  }

  /* End of Outputs for SubSystem: '<S64>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S64>/Subsystem - pi//2 delay' incorporates:
   *  EnablePort: '<S67>/Enable'
   */
  if (SRF_PLL_Block_ConstB.Compare_p > 0) {
    /* Fcn: '<S67>/Fcn' incorporates:
     *  Delay: '<S1>/Delay1'
     *  Fcn: '<S67>/Fcn1'
     */
    Fcn_e_tmp = cosf(SRF_PLL_Block_DW.Delay1_DSTATE);
    Fcn_e_tmp_0 = sinf(SRF_PLL_Block_DW.Delay1_DSTATE);

    /* Fcn: '<S67>/Fcn' */
    SRF_PLL_Block_B.Fcn_c = rtb_Gain1_idx_1 * Fcn_e_tmp_0 + rtb_Gain1_idx_0 *
      Fcn_e_tmp;

    /* Fcn: '<S67>/Fcn1' */
    SRF_PLL_Block_B.Fcn1_a = -rtb_Gain1_idx_1 * Fcn_e_tmp + rtb_Gain1_idx_0 *
      Fcn_e_tmp_0;
  }

  /* End of Outputs for SubSystem: '<S64>/Subsystem - pi//2 delay' */

  /* Switch: '<S64>/Switch' */
  if (SRF_PLL_Block_ConstB.Compare_g != 0) {
    /* SignalConversion generated from: '<S63>/Gain3' */
    tmp[0] = SRF_PLL_Block_B.Fcn;
    tmp[1] = SRF_PLL_Block_B.Fcn1;
  } else {
    /* SignalConversion generated from: '<S63>/Gain3' */
    tmp[0] = SRF_PLL_Block_B.Fcn_c;
    tmp[1] = SRF_PLL_Block_B.Fcn1_a;
  }

  /* End of Switch: '<S64>/Switch' */

  /* SignalConversion generated from: '<S63>/Gain3' incorporates:
   *  Gain: '<S5>/Gain1'
   */
  tmp[2] = 0.666666687F * rtb_Sqrt;

  /* Gain: '<S63>/Gain3' incorporates:
   *  Outport: '<Root>/Vabc_hat'
   */
  rtb_Sqrt = 0.0F;
  Fcn_e_tmp = 0.0F;
  Fcn_e_tmp_0 = 0.0F;
  for (i = 0; i < 3; i++) {
    rtb_Sqrt += SRF_PLL_Block_ConstP.Gain3_Gain_p[3 * i] * tmp[i];
    Fcn_e_tmp += SRF_PLL_Block_ConstP.Gain3_Gain_p[3 * i + 1] * tmp[i];
    Fcn_e_tmp_0 += SRF_PLL_Block_ConstP.Gain3_Gain_p[3 * i + 2] * tmp[i];
  }

  SRF_PLL_Block_Y.Vabc_hat[2] = Fcn_e_tmp_0;
  SRF_PLL_Block_Y.Vabc_hat[1] = Fcn_e_tmp;
  SRF_PLL_Block_Y.Vabc_hat[0] = rtb_Sqrt;

  /* End of Gain: '<S63>/Gain3' */

  /* Sqrt: '<S4>/Sqrt' incorporates:
   *  Math: '<S4>/Square'
   *  Math: '<S4>/Square1'
   *  Sum: '<S4>/Add'
   */
  rtb_Sqrt = sqrtf(rtb_Gain1_idx_1 * rtb_Gain1_idx_1 + rtb_Gain1_idx_0 *
                   rtb_Gain1_idx_0);

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  if (rtb_Sqrt >= 1.0E-6F) {
    rtb_VqNormalized = rtb_Sqrt;
  } else {
    rtb_VqNormalized = 1.0E-6;
  }

  /* Product: '<S1>/Normalize1' incorporates:
   *  Switch: '<S1>/Switch'
   */
  rtb_VqNormalized = rtb_Gain1_idx_0 / rtb_VqNormalized;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  DiscreteIntegrator: '<S45>/Integrator'
   *  Gain: '<S50>/Proportional Gain'
   *  Sum: '<S54>/Sum'
   */
  SRF_PLL_Block_Y.Freq = (266.57297628950192 * rtb_VqNormalized +
    SRF_PLL_Block_DW.Integrator_DSTATE) + 314.15926535897933;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S1>/Delay'
   */
  rtb_Sqrt = (real32_T)(5.0E-5 * SRF_PLL_Block_Y.Freq);
  SRF_PLL_Block_DW.Delay_DSTATE = rtb_Sqrt +
    SRF_PLL_Block_DW.DiscreteTimeIntegrator_DSTATE;

  /* Outport: '<Root>/theta' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Delay: '<S1>/Delay'
   *  Math: '<S1>/Mod'
   */
  SRF_PLL_Block_Y.theta = rt_modf_snf(SRF_PLL_Block_DW.Delay_DSTATE, 6.28318548F);

  /* Update for Delay: '<S1>/Delay1' incorporates:
   *  Delay: '<S1>/Delay'
   */
  SRF_PLL_Block_DW.Delay1_DSTATE = SRF_PLL_Block_DW.Delay_DSTATE;

  /* Update for DiscreteIntegrator: '<S45>/Integrator' incorporates:
   *  Gain: '<S42>/Integral Gain'
   */
  SRF_PLL_Block_DW.Integrator_DSTATE += 35530.575843921681 * rtb_VqNormalized *
    0.0001;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S1>/Delay'
   */
  SRF_PLL_Block_DW.DiscreteTimeIntegrator_DSTATE = rtb_Sqrt +
    SRF_PLL_Block_DW.Delay_DSTATE;
}

/* Model initialize function */
void SRF_PLL_Block_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void SRF_PLL_Block_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
