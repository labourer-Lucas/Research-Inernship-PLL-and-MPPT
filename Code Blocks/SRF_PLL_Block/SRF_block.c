/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SRF_block.c
 *
 * Code generated for Simulink model 'SRF_block'.
 *
 * Model version                  : 2.8
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Sun Oct 12 18:48:18 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SRF_block.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>

/* Block signals (default storage) */
B_SRF_block_T SRF_block_B;

/* Block states (default storage) */
DW_SRF_block_T SRF_block_DW;

/* External inputs (root inport signals with default storage) */
ExtU_SRF_block_T SRF_block_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_SRF_block_T SRF_block_Y;

/* Real-time model */
static RT_MODEL_SRF_block_T SRF_block_M_;
RT_MODEL_SRF_block_T *const SRF_block_M = &SRF_block_M_;

/* Model step function */
void SRF_block_step(void)
{
  int32_T i;
  real32_T tmp[3];
  real32_T IC;
  real32_T Vabc_hat;
  real32_T Vabc_hat_0;
  real32_T rtb_Cos;
  real32_T rtb_Gain1_idx_0;
  real32_T rtb_Gain1_idx_1;
  real32_T rtb_Sin;
  real32_T rtb_Sqrt;
  real32_T u0;

  /* Gain: '<S6>/Gain3' incorporates:
   *  Inport: '<Root>/vabc'
   */
  rtb_Gain1_idx_0 = 0.0F;
  IC = 0.0F;
  for (i = 0; i < 3; i++) {
    rtb_Sin = SRF_block_U.vabc[i];
    rtb_Gain1_idx_0 += SRF_block_ConstP.Gain3_Gain[3 * i] * rtb_Sin;
    IC += SRF_block_ConstP.Gain3_Gain[3 * i + 1] * rtb_Sin;
  }

  /* End of Gain: '<S6>/Gain3' */

  /* Gain: '<S6>/Gain1' */
  rtb_Gain1_idx_0 *= 0.666666687F;
  rtb_Gain1_idx_1 = 0.666666687F * IC;

  /* InitialCondition: '<S3>/IC' */
  if (SRF_block_DW.IC_FirstOutputTime) {
    SRF_block_DW.IC_FirstOutputTime = false;

    /* InitialCondition: '<S3>/IC' */
    IC = 0.0F;
  } else {
    /* InitialCondition: '<S3>/IC' incorporates:
     *  Gain: '<S3>/Gain'
     *  Gain: '<S3>/Gain1'
     *  Rounding: '<S3>/Rounding Function'
     *  Sum: '<S3>/Sum1'
     */
    IC = SRF_block_DW.DiscreteTimeIntegrator_DSTATE - (real32_T)floor
      (0.159154937F * SRF_block_DW.DiscreteTimeIntegrator_DSTATE) * 6.28318548F;
  }

  /* End of InitialCondition: '<S3>/IC' */

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Logic: '<S3>/Logical Operator'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   */
  if ((SRF_block_DW.DiscreteTimeIntegrator_DSTATE < 0.0F) ||
      (SRF_block_DW.DiscreteTimeIntegrator_DSTATE >= 6.28318548F)) {
    SRF_block_DW.DiscreteTimeIntegrator_DSTATE = IC;
  }

  /* Trigonometry: '<S1>/Sin' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  rtb_Sin = (real32_T)sin(SRF_block_DW.DiscreteTimeIntegrator_DSTATE);

  /* Trigonometry: '<S1>/Cos' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  rtb_Cos = (real32_T)cos(SRF_block_DW.DiscreteTimeIntegrator_DSTATE);

  /* Outputs for Atomic SubSystem: '<S15>/Two inputs CRL' */
  /* Switch: '<S17>/Switch' incorporates:
   *  Product: '<S16>/acos'
   *  Product: '<S16>/asin'
   *  Product: '<S16>/bcos'
   *  Product: '<S16>/bsin'
   *  Sum: '<S16>/sum_Ds'
   *  Sum: '<S16>/sum_Qs'
   *  UnaryMinus: '<S17>/Unary_Minus'
   */
  IC = -(rtb_Gain1_idx_1 * rtb_Cos - rtb_Gain1_idx_0 * rtb_Sin);
  rtb_Gain1_idx_0 = rtb_Gain1_idx_0 * rtb_Cos + rtb_Gain1_idx_1 * rtb_Sin;

  /* Sqrt: '<S5>/Sqrt' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S16>/a16'
   *  Math: '<S5>/Square'
   *  Math: '<S5>/Square1'
   *  Sum: '<S5>/Add'
   */
  rtb_Sqrt = (real32_T)sqrt(IC * IC + rtb_Gain1_idx_0 * rtb_Gain1_idx_0);

  /* End of Outputs for SubSystem: '<S15>/Two inputs CRL' */

  /* DiscreteFilter: '<S1>/LPF1' */
  rtb_Gain1_idx_1 = rtb_Sqrt - -0.98429203F * SRF_block_DW.LPF1_states;

  /* Outport: '<Root>/Line_RMS' incorporates:
   *  DiscreteFilter: '<S1>/LPF1'
   */
  SRF_block_Y.Line_RMS = 0.0F * rtb_Gain1_idx_1 + 0.0157079641F *
    SRF_block_DW.LPF1_states;

  /* Outputs for Atomic SubSystem: '<S15>/Two inputs CRL' */
  /* Product: '<S1>/Normalize1' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S16>/a16'
   *  Constant: '<S1>/Constant3'
   *  Sum: '<S1>/Add2'
   */
  rtb_Sqrt = rtb_Gain1_idx_0 / (rtb_Sqrt + 1.0E-6F);

  /* End of Outputs for SubSystem: '<S15>/Two inputs CRL' */

  /* DiscreteIntegrator: '<S10>/Integrator' */
  if (SRF_block_DW.Integrator_IC_LOADING != 0) {
    SRF_block_DW.Integrator_DSTATE = SRF_block_ConstB.Conversion;
    if (SRF_block_DW.Integrator_DSTATE > 150000.0F) {
      SRF_block_DW.Integrator_DSTATE = 150000.0F;
    } else if (SRF_block_DW.Integrator_DSTATE < -150000.0F) {
      SRF_block_DW.Integrator_DSTATE = -150000.0F;
    }
  }

  /* DiscreteIntegrator: '<S10>/Integrator' incorporates:
   *  Gain: '<S2>/Ki'
   */
  SRF_block_DW.Integrator_DSTATE += 35530.5742F * rtb_Sqrt * 0.0001F;

  /* DiscreteIntegrator: '<S10>/Integrator' */
  if (SRF_block_DW.Integrator_DSTATE > 150000.0F) {
    /* DiscreteIntegrator: '<S10>/Integrator' */
    SRF_block_DW.Integrator_DSTATE = 150000.0F;
  } else if (SRF_block_DW.Integrator_DSTATE < -150000.0F) {
    /* DiscreteIntegrator: '<S10>/Integrator' */
    SRF_block_DW.Integrator_DSTATE = -150000.0F;
  }

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Kp'
   */
  u0 = 266.572968F * rtb_Sqrt + SRF_block_DW.Integrator_DSTATE;

  /* Saturate: '<S2>/[A,B]' */
  if (u0 > 150000.0F) {
    u0 = 150000.0F;
  } else if (u0 < -150000.0F) {
    u0 = -150000.0F;
  }

  /* End of Saturate: '<S2>/[A,B]' */

  /* DiscreteFilter: '<S1>/LPF3' incorporates:
   *  Constant: '<S1>/initial Value of ¦Ø2'
   *  Sum: '<S1>/Add1'
   */
  rtb_Sqrt = (u0 + 314.159271F) - -0.990575194F * SRF_block_DW.LPF3_states;

  /* Outport: '<Root>/freq' incorporates:
   *  DiscreteFilter: '<S1>/LPF3'
   */
  SRF_block_Y.freq = 0.0F * rtb_Sqrt + 0.0094247777F * SRF_block_DW.LPF3_states;

  /* Outport: '<Root>/theta' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  SRF_block_Y.theta = SRF_block_DW.DiscreteTimeIntegrator_DSTATE;

  /* Outputs for Enabled SubSystem: '<S19>/Subsystem1' incorporates:
   *  EnablePort: '<S23>/Enable'
   */
  if (SRF_block_ConstB.Compare > 0) {
    /* Outputs for Atomic SubSystem: '<S15>/Two inputs CRL' */
    /* Fcn: '<S23>/Fcn' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S16>/a16'
     */
    SRF_block_B.Fcn = IC * rtb_Cos - rtb_Gain1_idx_0 * rtb_Sin;

    /* Fcn: '<S23>/Fcn1' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S16>/a16'
     *  Fcn: '<S23>/Fcn'
     */
    SRF_block_B.Fcn1 = IC * rtb_Sin + rtb_Gain1_idx_0 * rtb_Cos;

    /* End of Outputs for SubSystem: '<S15>/Two inputs CRL' */
  }

  /* End of Outputs for SubSystem: '<S19>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S19>/Subsystem - pi//2 delay' incorporates:
   *  EnablePort: '<S22>/Enable'
   */
  if (SRF_block_ConstB.Compare_o > 0) {
    /* Outputs for Atomic SubSystem: '<S15>/Two inputs CRL' */
    /* Fcn: '<S22>/Fcn' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S16>/a16'
     */
    SRF_block_B.Fcn_d = IC * rtb_Sin + rtb_Gain1_idx_0 * rtb_Cos;

    /* Fcn: '<S22>/Fcn1' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S16>/a16'
     *  Fcn: '<S22>/Fcn'
     */
    SRF_block_B.Fcn1_j = -IC * rtb_Cos + rtb_Gain1_idx_0 * rtb_Sin;

    /* End of Outputs for SubSystem: '<S15>/Two inputs CRL' */
  }

  /* End of Outputs for SubSystem: '<S19>/Subsystem - pi//2 delay' */

  /* Switch: '<S19>/Switch' */
  if (SRF_block_ConstB.Compare != 0) {
    /* SignalConversion generated from: '<S18>/Gain3' */
    tmp[0] = SRF_block_B.Fcn;
    tmp[1] = SRF_block_B.Fcn1;
  } else {
    /* SignalConversion generated from: '<S18>/Gain3' */
    tmp[0] = SRF_block_B.Fcn_d;
    tmp[1] = SRF_block_B.Fcn1_j;
  }

  /* End of Switch: '<S19>/Switch' */

  /* SignalConversion generated from: '<S18>/Gain3' incorporates:
   *  Constant: '<S1>/Zero'
   */
  tmp[2] = 0.0F;

  /* Gain: '<S18>/Gain3' incorporates:
   *  Outport: '<Root>/Vabc_hat'
   */
  rtb_Cos = 0.0F;
  Vabc_hat = 0.0F;
  Vabc_hat_0 = 0.0F;
  for (i = 0; i < 3; i++) {
    rtb_Sin = tmp[i];
    rtb_Cos += SRF_block_ConstP.Gain3_Gain_l[3 * i] * rtb_Sin;
    Vabc_hat += SRF_block_ConstP.Gain3_Gain_l[3 * i + 1] * rtb_Sin;
    Vabc_hat_0 += SRF_block_ConstP.Gain3_Gain_l[3 * i + 2] * rtb_Sin;
  }

  SRF_block_Y.Vabc_hat[2] = Vabc_hat_0;
  SRF_block_Y.Vabc_hat[1] = Vabc_hat;
  SRF_block_Y.Vabc_hat[0] = rtb_Cos;

  /* End of Gain: '<S18>/Gain3' */

  /* Outputs for Atomic SubSystem: '<S15>/Two inputs CRL' */
  /* Outport: '<Root>/dq' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S16>/a16'
   */
  SRF_block_Y.dq[0] = IC;
  SRF_block_Y.dq[1] = rtb_Gain1_idx_0;

  /* End of Outputs for SubSystem: '<S15>/Two inputs CRL' */

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/initial Value of ¦Ø2'
   *  Sum: '<S1>/Add1'
   */
  SRF_block_DW.DiscreteTimeIntegrator_DSTATE += (u0 + 314.159271F) * 0.0001F;

  /* Update for DiscreteFilter: '<S1>/LPF1' */
  SRF_block_DW.LPF1_states = rtb_Gain1_idx_1;

  /* Update for DiscreteIntegrator: '<S10>/Integrator' */
  SRF_block_DW.Integrator_IC_LOADING = 0U;
  SRF_block_DW.Integrator_PrevResetState = 0;

  /* Update for DiscreteFilter: '<S1>/LPF3' */
  SRF_block_DW.LPF3_states = rtb_Sqrt;
}

/* Model initialize function */
void SRF_block_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SRF_block_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &SRF_block_B), 0,
                sizeof(B_SRF_block_T));

  /* states (dwork) */
  (void) memset((void *)&SRF_block_DW, 0,
                sizeof(DW_SRF_block_T));

  /* Start for InitialCondition: '<S3>/IC' */
  SRF_block_DW.IC_FirstOutputTime = true;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  SRF_block_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S1>/LPF1' */
  SRF_block_DW.LPF1_states = 14005.6338F;

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Integrator' */
  SRF_block_DW.Integrator_PrevResetState = 2;
  SRF_block_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteFilter: '<S1>/LPF3' */
  SRF_block_DW.LPF3_states = 33333.332F;
}

/* Model terminate function */
void SRF_block_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
