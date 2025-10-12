/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DDSRF_PLL_block_data.c
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

/* Invariant block signals (default storage) */
const ConstB_DDSRF_PLL_block_T DDSRF_PLL_block_ConstB = {
  0.0F,                                /* '<S11>/Conversion' */
  0U,                                  /* '<S28>/Compare' */
  1U                                   /* '<S29>/Compare' */
};

/* Constant parameters (default storage) */
const ConstP_DDSRF_PLL_block_T DDSRF_PLL_block_ConstP = {
  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S9>/Gain3'
   */
  { 1.0F, 0.0F, 0.5F, -0.5F, 0.866025388F, 0.5F, -0.5F, -0.866025388F, 0.5F },

  /* Computed Parameter: Gain3_Gain_l
   * Referenced by: '<S26>/Gain3'
   */
  { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F, -0.866025388F, 1.0F, 1.0F, 1.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
