/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SRF_PLL_Block_data.c
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

/* Invariant block signals (default storage) */
const ConstB_SRF_PLL_Block_T SRF_PLL_Block_ConstB = {
  0U,                                  /* '<S7>/Compare' */
  1U,                                  /* '<S8>/Compare' */
  0U,                                  /* '<S65>/Compare' */
  1U                                   /* '<S66>/Compare' */
};

/* Constant parameters (default storage) */
const ConstP_SRF_PLL_Block_T SRF_PLL_Block_ConstP = {
  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S5>/Gain3'
   */
  { 1.0F, 0.0F, 0.5F, -0.5F, 0.866025388F, 0.5F, -0.5F, -0.866025388F, 0.5F },

  /* Computed Parameter: Gain3_Gain_p
   * Referenced by: '<S63>/Gain3'
   */
  { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F, -0.866025388F, 1.0F, 1.0F, 1.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
