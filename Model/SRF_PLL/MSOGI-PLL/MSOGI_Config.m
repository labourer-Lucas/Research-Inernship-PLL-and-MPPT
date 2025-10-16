%% Set the following parameters


grid_frequency_hz = single(50); %% Nominal Grid Frequency in Hz 
damping_factor_zeta = single(1/sqrt(2)); %% Damping factor for SRF PLL, usually between 0 and 1
pll_bandwidth_hz = single(500); %% Bandwidth of PLL
pll_sat_min = single(-150); %% Lower limit saturation for PLL PI regulator
pll_sat_max = single(150); %% Upper limit saturation for PLL PI regulator

k_sogi = single(sqrt(2)); %% Gain for SOGI

%%Curve fitting data for k_rms to k_sogi relationship for approximation of
%%rms gain
%%f(x) = a*exp(b*x) + c*exp(d*x)
%%Ksogi_data =   [0.6970634 0.6960532 0.6948187 0.693276 0.6914514 0.6886455 0.6849423 0.6793857 0.6701281 0.66273530]
%%Krms_data =   [2.2 2.0 1.8 1.6 1.4142135 1.2 1.0 0.8 0.6 0.5]
k_rms_a = 0.6856;
k_rms_b = 0.0077;
k_rms_c = -0.1102;
k_rms_d = -2.9340;

k_rms = k_rms_a*exp(k_rms_b*k_sogi) + k_rms_c*exp(k_rms_d*k_sogi);

lpf_freq_sogi_cutoff_hz = single(15); %%cut off for frequency LPF to SOGI
lpf_freq_out_cutoff_hz = single(lpf_freq_sogi_cutoff_hz); %%cut off for frequency LPF output
lpf_rms_out_cutoff_hz = single(25); %%cut off for RMS ouput LPF

k_dc_comp = single(0.22); %%Gain for DC offset compensation

dc_offset_max_v = single(2); %% clamping for DC offset values
dc_offset_min_v = single(-2); %% clamping for DC offset values
k_dc_comp_en = 0; %%enable DC compensation
har5_comp_en = 0; %%enable DC compensation
har3_comp_en = 0; %%enable DC compensation

sample_time_s = single(100e-6); %%Sample time/period/loop frequency
Ts = sample_time_s; %% for simulation vars
sample_time_s_d = double(sample_time_s); % for simulation step settings 

%%%Test Parameters
test_dc_offset = single(0.1);
test_ac_amplitude = single(1.5);
test_5th_harmonic_gain = single(0.00);
test_3rd_harmonic_gain = single(0.01);




%% IIR Filter for frequency for SOGI of the form a/(b+z) where b = a-1
%% This is just an alpha beta / RC filter of the form y[n+1] = ax[n] + (a-1)y[n] 
%% init is the value of y[0]

filter_omega_sogi_a = single(2*pi*lpf_freq_sogi_cutoff_hz*sample_time_s);
filter_omega_sogi_b = single(1-filter_omega_sogi_a);
filter_omega_sogi_init = single(filter_omega_sogi_a * grid_frequency_hz/(lpf_freq_sogi_cutoff_hz*sample_time_s));


%% IIR Filter for frequency for output of the form a/(b+z) where b = 1-a
%% This is just an alpha beta / RC filter of the form y[n+1] = ax[n] + (1-a)y[n] 
%% init is the value of y[0]

filter_omega_out_a = single((2*pi*lpf_freq_out_cutoff_hz*sample_time_s));
filter_omega_out_b = single((1-(2*pi*lpf_freq_out_cutoff_hz*sample_time_s)));
filter_omega_out_init = single(filter_omega_out_a * grid_frequency_hz/(lpf_freq_out_cutoff_hz*sample_time_s));

%% IIR Filter for rms output of the form a/(b+z) where b = 1-a
%% This is just an alpha beta / RC filter of the form y[n+1] = ax[n] + (1-a)y[n] 
%% init is the value of y[0]

filter_rms_out_a = single((2*pi*lpf_rms_out_cutoff_hz*sample_time_s));
filter_rms_out_b = single((1-(2*pi*lpf_rms_out_cutoff_hz*sample_time_s)));
filter_rms_out_init = single(0);



%% SRF PLL Config
SRF_PI_P = single(2*2*pi*pll_bandwidth_hz*damping_factor_zeta);
SRF_PI_I = single((2*pll_bandwidth_hz*pi)^2);


%% Gain Sogi 3rd Order integrator
k_sogi_integrator = single(sample_time_s/12);

%% SOGI Harmonic rejection Gains
k_sogi_3rd_hardmonic = single(k_sogi/3);
k_sogi_5th_hardmonic = single(k_sogi/5);




