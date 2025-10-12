/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DDSRF_PLL_block.c
 *
 * Code generated for Simulink model 'DDSRF_PLL_block'.
 *
 * Model version                  : 2.5
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Sun Oct 12 18:53:49 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DDSRF_PLL_block.h"
#include "rtwtypes.h"
#include "DDSRF_PLL_block_private.h"
#include <math.h>
#include <string.h>

/* Block signals (default storage) */
B_DDSRF_PLL_block_T DDSRF_PLL_block_B;

/* Block states (default storage) */
DW_DDSRF_PLL_block_T DDSRF_PLL_block_DW;

/* External inputs (root inport signals with default storage) */
ExtU_DDSRF_PLL_block_T DDSRF_PLL_block_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_DDSRF_PLL_block_T DDSRF_PLL_block_Y;

/* Real-time model */
static RT_MODEL_DDSRF_PLL_block_T DDSRF_PLL_block_M_;
RT_MODEL_DDSRF_PLL_block_T *const DDSRF_PLL_block_M = &DDSRF_PLL_block_M_;

/*
 * Output and update for atomic system:
 *    '<S18>/Two inputs CRL'
 *    '<S23>/Two inputs CRL'
 */
void DDSRF_PLL_block_TwoinputsCRL(real32_T rtu_Alpha, real32_T rtu_Beta,
  real32_T rtu_sine, real32_T rtu_cos, real32_T *rty_Ds, real32_T *rty_Qs)
{
  /* AlgorithmDescriptorDelegate generated from: '<S19>/a16' incorporates:
   *  Product: '<S19>/acos'
   *  Product: '<S19>/asin'
   *  Product: '<S19>/bcos'
   *  Product: '<S19>/bsin'
   *  Sum: '<S19>/sum_Ds'
   *  Sum: '<S19>/sum_Qs'
   *  UnaryMinus: '<S20>/Unary_Minus'
   */
  *rty_Ds = -(rtu_Beta * rtu_cos - rtu_Alpha * rtu_sine);
  *rty_Qs = rtu_Alpha * rtu_cos + rtu_Beta * rtu_sine;
}

/* Model step function */
void DDSRF_PLL_block_step(void)
{
  int32_T i;
  real32_T tmp[3];
  real32_T IC;
  real32_T rtb_Add2;
  real32_T rtb_Add3;
  real32_T rtb_Cos_h;
  real32_T rtb_Gain1_idx_0;
  real32_T rtb_Gain1_idx_1;
  real32_T rtb_Sin_e;
  real32_T rtb_Sqrt;
  real32_T rtb_algDD_o1;
  real32_T rtb_algDD_o2;
  real32_T u0;

  /* Gain: '<S9>/Gain3' incorporates:
   *  Inport: '<Root>/vabc'
   */
  rtb_Add2 = 0.0F;
  IC = 0.0F;
  for (i = 0; i < 3; i++) {
    rtb_algDD_o2 = DDSRF_PLL_block_U.vabc[i];
    rtb_Add2 += DDSRF_PLL_block_ConstP.Gain3_Gain[3 * i] * rtb_algDD_o2;
    IC += DDSRF_PLL_block_ConstP.Gain3_Gain[3 * i + 1] * rtb_algDD_o2;
  }

  /* End of Gain: '<S9>/Gain3' */

  /* Gain: '<S9>/Gain1' */
  rtb_Gain1_idx_0 = 0.666666687F * rtb_Add2;
  rtb_Gain1_idx_1 = 0.666666687F * IC;

  /* InitialCondition: '<S5>/IC' */
  if (DDSRF_PLL_block_DW.IC_FirstOutputTime) {
    DDSRF_PLL_block_DW.IC_FirstOutputTime = false;

    /* InitialCondition: '<S5>/IC' */
    IC = 0.0F;
  } else {
    /* InitialCondition: '<S5>/IC' incorporates:
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain1'
     *  Rounding: '<S5>/Rounding Function'
     *  Sum: '<S5>/Sum1'
     */
    IC = DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE - (real32_T)floor
      (0.159154937F * DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE) *
      6.28318548F;
  }

  /* End of InitialCondition: '<S5>/IC' */

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   */
  if ((DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE < 0.0F) ||
      (DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE >= 6.28318548F)) {
    DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE = IC;
  }

  /* Outputs for Atomic SubSystem: '<S23>/Two inputs CRL' */
  /* Trigonometry: '<S1>/Sin' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Trigonometry: '<S1>/Cos'
   */
  DDSRF_PLL_block_TwoinputsCRL(rtb_Gain1_idx_0, rtb_Gain1_idx_1, (real32_T)sin
    (DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE), (real32_T)cos
    (DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE), &rtb_algDD_o2,
    &rtb_algDD_o1);

  /* End of Outputs for SubSystem: '<S23>/Two inputs CRL' */

  /* Gain: '<S2>/Gain' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  rtb_Cos_h = 2.0F * DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE;

  /* Trigonometry: '<S2>/Cos' */
  rtb_Sin_e = (real32_T)cos(rtb_Cos_h);

  /* Trigonometry: '<S2>/Sin' */
  rtb_Cos_h = (real32_T)sin(rtb_Cos_h);

  /* Sum: '<S2>/Add2' incorporates:
   *  Delay: '<S1>/Delay One Step2'
   *  Delay: '<S1>/Delay One Step3'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product2'
   *  Sum: '<S2>/Add'
   */
  rtb_Add2 = (rtb_algDD_o2 - rtb_Sin_e * DDSRF_PLL_block_DW.DelayOneStep2_DSTATE)
    - rtb_Cos_h * DDSRF_PLL_block_DW.DelayOneStep3_DSTATE;

  /* Sum: '<S2>/Add3' incorporates:
   *  Delay: '<S1>/Delay One Step2'
   *  Delay: '<S1>/Delay One Step3'
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Add1'
   */
  rtb_Add3 = (DDSRF_PLL_block_DW.DelayOneStep2_DSTATE * rtb_Cos_h + rtb_algDD_o1)
    - DDSRF_PLL_block_DW.DelayOneStep3_DSTATE * rtb_Sin_e;

  /* Sqrt: '<S8>/Sqrt' incorporates:
   *  Math: '<S8>/Square'
   *  Math: '<S8>/Square1'
   *  Sum: '<S8>/Add'
   */
  rtb_Sqrt = (real32_T)sqrt(rtb_Add2 * rtb_Add2 + rtb_Add3 * rtb_Add3);

  /* DiscreteFilter: '<S1>/LPF1' */
  IC = rtb_Sqrt - -0.98429203F * DDSRF_PLL_block_DW.LPF1_states;

  /* Outport: '<Root>/Line_RMS' incorporates:
   *  DiscreteFilter: '<S1>/LPF1'
   */
  DDSRF_PLL_block_Y.Line_RMS = 0.0F * IC + 0.0157079641F *
    DDSRF_PLL_block_DW.LPF1_states;

  /* Product: '<S1>/Normalize1' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Sum: '<S1>/Add2'
   */
  rtb_Sin_e = rtb_Add3 / (rtb_Sqrt + 1.0E-6F);

  /* DiscreteIntegrator: '<S13>/Integrator' */
  if (DDSRF_PLL_block_DW.Integrator_IC_LOADING != 0) {
    DDSRF_PLL_block_DW.Integrator_DSTATE = DDSRF_PLL_block_ConstB.Conversion;
    if (DDSRF_PLL_block_DW.Integrator_DSTATE > 150000.0F) {
      DDSRF_PLL_block_DW.Integrator_DSTATE = 150000.0F;
    } else if (DDSRF_PLL_block_DW.Integrator_DSTATE < -150000.0F) {
      DDSRF_PLL_block_DW.Integrator_DSTATE = -150000.0F;
    }
  }

  /* DiscreteIntegrator: '<S13>/Integrator' incorporates:
   *  Gain: '<S4>/Ki'
   */
  DDSRF_PLL_block_DW.Integrator_DSTATE += 35530.5742F * rtb_Sin_e * 0.0001F;

  /* DiscreteIntegrator: '<S13>/Integrator' */
  if (DDSRF_PLL_block_DW.Integrator_DSTATE > 150000.0F) {
    /* DiscreteIntegrator: '<S13>/Integrator' */
    DDSRF_PLL_block_DW.Integrator_DSTATE = 150000.0F;
  } else if (DDSRF_PLL_block_DW.Integrator_DSTATE < -150000.0F) {
    /* DiscreteIntegrator: '<S13>/Integrator' */
    DDSRF_PLL_block_DW.Integrator_DSTATE = -150000.0F;
  }

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S4>/Kp'
   */
  u0 = 266.572968F * rtb_Sin_e + DDSRF_PLL_block_DW.Integrator_DSTATE;

  /* Saturate: '<S4>/[A,B]' */
  if (u0 > 150000.0F) {
    u0 = 150000.0F;
  } else if (u0 < -150000.0F) {
    u0 = -150000.0F;
  }

  /* End of Saturate: '<S4>/[A,B]' */

  /* DiscreteFilter: '<S1>/LPF3' incorporates:
   *  Constant: '<S1>/initial Value of ¦Ø2'
   *  Sum: '<S1>/Add1'
   */
  rtb_Sqrt = (u0 + 314.159271F) - -0.990575194F * DDSRF_PLL_block_DW.LPF3_states;

  /* Outport: '<Root>/freq' incorporates:
   *  DiscreteFilter: '<S1>/LPF3'
   */
  DDSRF_PLL_block_Y.freq = 0.0F * rtb_Sqrt + 0.0094247777F *
    DDSRF_PLL_block_DW.LPF3_states;

  /* Outport: '<Root>/theta' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  DDSRF_PLL_block_Y.theta = DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE;

  /* Outputs for Enabled SubSystem: '<S27>/Subsystem1' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  if (DDSRF_PLL_block_ConstB.Compare > 0) {
    /* Fcn: '<S31>/Fcn' incorporates:
     *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
     */
    DDSRF_PLL_block_B.Fcn = rtb_Add2 * (real32_T)cos
      (DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE) - rtb_Add3 * (real32_T)
      sin(DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE);

    /* Fcn: '<S31>/Fcn1' incorporates:
     *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
     */
    DDSRF_PLL_block_B.Fcn1 = rtb_Add2 * (real32_T)sin
      (DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE) + rtb_Add3 * (real32_T)
      cos(DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S27>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S27>/Subsystem - pi//2 delay' incorporates:
   *  EnablePort: '<S30>/Enable'
   */
  if (DDSRF_PLL_block_ConstB.Compare_o > 0) {
    /* Fcn: '<S30>/Fcn' incorporates:
     *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
     */
    DDSRF_PLL_block_B.Fcn_d = rtb_Add2 * (real32_T)sin
      (DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE) + rtb_Add3 * (real32_T)
      cos(DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE);

    /* Fcn: '<S30>/Fcn1' incorporates:
     *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
     */
    DDSRF_PLL_block_B.Fcn1_j = -rtb_Add2 * (real32_T)cos
      (DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE) + rtb_Add3 * (real32_T)
      sin(DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S27>/Subsystem - pi//2 delay' */

  /* Switch: '<S27>/Switch' */
  if (DDSRF_PLL_block_ConstB.Compare != 0) {
    /* SignalConversion generated from: '<S26>/Gain3' */
    tmp[0] = DDSRF_PLL_block_B.Fcn;
    tmp[1] = DDSRF_PLL_block_B.Fcn1;
  } else {
    /* SignalConversion generated from: '<S26>/Gain3' */
    tmp[0] = DDSRF_PLL_block_B.Fcn_d;
    tmp[1] = DDSRF_PLL_block_B.Fcn1_j;
  }

  /* End of Switch: '<S27>/Switch' */

  /* SignalConversion generated from: '<S26>/Gain3' incorporates:
   *  Constant: '<S1>/Zero'
   */
  tmp[2] = 0.0F;

  /* Gain: '<S26>/Gain3' incorporates:
   *  Outport: '<Root>/Vabc_hat'
   */
  rtb_Cos_h = 0.0F;
  rtb_Sin_e = 0.0F;
  rtb_algDD_o1 = 0.0F;
  for (i = 0; i < 3; i++) {
    rtb_algDD_o2 = tmp[i];
    rtb_Cos_h += DDSRF_PLL_block_ConstP.Gain3_Gain_l[3 * i] * rtb_algDD_o2;
    rtb_Sin_e += DDSRF_PLL_block_ConstP.Gain3_Gain_l[3 * i + 1] * rtb_algDD_o2;
    rtb_algDD_o1 += DDSRF_PLL_block_ConstP.Gain3_Gain_l[3 * i + 2] *
      rtb_algDD_o2;
  }

  DDSRF_PLL_block_Y.Vabc_hat[2] = rtb_algDD_o1;
  DDSRF_PLL_block_Y.Vabc_hat[1] = rtb_Sin_e;
  DDSRF_PLL_block_Y.Vabc_hat[0] = rtb_Cos_h;

  /* End of Gain: '<S26>/Gain3' */

  /* Outport: '<Root>/dq' */
  DDSRF_PLL_block_Y.dq[0] = rtb_Add2;
  DDSRF_PLL_block_Y.dq[1] = rtb_Add3;

  /* Outputs for Atomic SubSystem: '<S18>/Two inputs CRL' */
  /* Trigonometry: '<S1>/Sin1' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Gain: '<S1>/Gain'
   *  Trigonometry: '<S1>/Cos1'
   */
  DDSRF_PLL_block_TwoinputsCRL(rtb_Gain1_idx_0, rtb_Gain1_idx_1, (real32_T)sin
    (-DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE), (real32_T)cos
    (-DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE), &rtb_algDD_o1,
    &rtb_algDD_o2);

  /* End of Outputs for SubSystem: '<S18>/Two inputs CRL' */

  /* Gain: '<S3>/Gain' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Gain: '<S1>/Gain'
   */
  rtb_Sin_e = 2.0F * -DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE;

  /* Trigonometry: '<S3>/Cos' */
  rtb_Cos_h = (real32_T)cos(rtb_Sin_e);

  /* Trigonometry: '<S3>/Sin' */
  rtb_Sin_e = (real32_T)sin(rtb_Sin_e);

  /* DiscreteFilter: '<S1>/Discrete Filter' incorporates:
   *  Delay: '<S1>/Delay One Step'
   *  Delay: '<S1>/Delay One Step1'
   *  Delay: '<S1>/Delay One Step2'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product2'
   *  Sum: '<S3>/Add'
   *  Sum: '<S3>/Add2'
   */
  rtb_Gain1_idx_0 = ((rtb_algDD_o1 - rtb_Cos_h *
                      DDSRF_PLL_block_DW.DelayOneStep_DSTATE) - rtb_Sin_e *
                     DDSRF_PLL_block_DW.DelayOneStep1_DSTATE) - -0.981326401F *
    DDSRF_PLL_block_DW.DiscreteFilter_states;
  DDSRF_PLL_block_DW.DelayOneStep2_DSTATE = 0.00933678F * rtb_Gain1_idx_0 +
    0.00933678F * DDSRF_PLL_block_DW.DiscreteFilter_states;

  /* DiscreteFilter: '<S1>/Discrete Filter1' incorporates:
   *  Delay: '<S1>/Delay One Step'
   *  Delay: '<S1>/Delay One Step1'
   *  Delay: '<S1>/Delay One Step3'
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product3'
   *  Sum: '<S3>/Add1'
   *  Sum: '<S3>/Add3'
   */
  rtb_Gain1_idx_1 = ((DDSRF_PLL_block_DW.DelayOneStep_DSTATE * rtb_Sin_e +
                      rtb_algDD_o2) - DDSRF_PLL_block_DW.DelayOneStep1_DSTATE *
                     rtb_Cos_h) - -0.981326401F *
    DDSRF_PLL_block_DW.DiscreteFilter1_states;
  DDSRF_PLL_block_DW.DelayOneStep3_DSTATE = 0.00933678F * rtb_Gain1_idx_1 +
    0.00933678F * DDSRF_PLL_block_DW.DiscreteFilter1_states;

  /* DiscreteFilter: '<S1>/Discrete Filter2' incorporates:
   *  Delay: '<S1>/Delay One Step1'
   */
  rtb_Add3 -= -0.981326401F * DDSRF_PLL_block_DW.DiscreteFilter2_states;
  DDSRF_PLL_block_DW.DelayOneStep1_DSTATE = 0.00933678F * rtb_Add3 + 0.00933678F
    * DDSRF_PLL_block_DW.DiscreteFilter2_states;

  /* DiscreteFilter: '<S1>/Discrete Filter3' incorporates:
   *  Delay: '<S1>/Delay One Step'
   */
  rtb_Add2 -= -0.981326401F * DDSRF_PLL_block_DW.DiscreteFilter3_states;
  DDSRF_PLL_block_DW.DelayOneStep_DSTATE = 0.00933678F * rtb_Add2 + 0.00933678F *
    DDSRF_PLL_block_DW.DiscreteFilter3_states;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/initial Value of ¦Ø2'
   *  Sum: '<S1>/Add1'
   */
  DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE += (u0 + 314.159271F) *
    0.0001F;

  /* Update for DiscreteFilter: '<S1>/LPF1' */
  DDSRF_PLL_block_DW.LPF1_states = IC;

  /* Update for DiscreteIntegrator: '<S13>/Integrator' */
  DDSRF_PLL_block_DW.Integrator_IC_LOADING = 0U;
  DDSRF_PLL_block_DW.Integrator_PrevResetState = 0;

  /* Update for DiscreteFilter: '<S1>/LPF3' */
  DDSRF_PLL_block_DW.LPF3_states = rtb_Sqrt;

  /* Update for DiscreteFilter: '<S1>/Discrete Filter' */
  DDSRF_PLL_block_DW.DiscreteFilter_states = rtb_Gain1_idx_0;

  /* Update for DiscreteFilter: '<S1>/Discrete Filter1' */
  DDSRF_PLL_block_DW.DiscreteFilter1_states = rtb_Gain1_idx_1;

  /* Update for DiscreteFilter: '<S1>/Discrete Filter2' */
  DDSRF_PLL_block_DW.DiscreteFilter2_states = rtb_Add3;

  /* Update for DiscreteFilter: '<S1>/Discrete Filter3' */
  DDSRF_PLL_block_DW.DiscreteFilter3_states = rtb_Add2;
}

/* Model initialize function */
void DDSRF_PLL_block_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(DDSRF_PLL_block_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &DDSRF_PLL_block_B), 0,
                sizeof(B_DDSRF_PLL_block_T));

  /* states (dwork) */
  (void) memset((void *)&DDSRF_PLL_block_DW, 0,
                sizeof(DW_DDSRF_PLL_block_T));

  /* Start for InitialCondition: '<S5>/IC' */
  DDSRF_PLL_block_DW.IC_FirstOutputTime = true;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  DDSRF_PLL_block_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S1>/LPF1' */
  DDSRF_PLL_block_DW.LPF1_states = 14005.6338F;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Integrator' */
  DDSRF_PLL_block_DW.Integrator_PrevResetState = 2;
  DDSRF_PLL_block_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteFilter: '<S1>/LPF3' */
  DDSRF_PLL_block_DW.LPF3_states = 33333.332F;
}

/* Model terminate function */
void DDSRF_PLL_block_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
