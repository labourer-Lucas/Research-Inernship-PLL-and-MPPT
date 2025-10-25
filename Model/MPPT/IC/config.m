%% System parameters
T_s=1e-6; % step time for solver (s)
T_run=2; % stop time (s)
%% MPPT parameters
f_MPPT=500; %running frequency of MPPT (Hz)
D_delta=0.001; %step unit of MPPT
D_initial=0.5; %initial duty cycle
D_upperlimit=0.95; %upper limit of mormalized output
D_lowerlimit=0.1; %lower limit of mormalized output
flag_MPPT=0; % flag for MPPT: 0 fro P&O; 1 fro IC
%% BUCK circuit parameters
R_L=10; %oad resistance (ohm)
L_f=0.8653e-3; %filter inductance (H)
C_f=369.79e-6; %filter capacitance for Buck (F)
C_in=2e-3; %input filter capacitance (F)
f_sw=1e4; %switching frequency of PWM
%% Irradiation step
T_step= 1; %step tiem
I_initial=1000; %initial irradiation
I_final=500; %final irradiation 