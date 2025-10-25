%% Set the following parameters


grid_frequency_hz = single(50); %% Nominal Grid Frequency in Hz 
damping_factor_zeta = single(1/sqrt(2)); %% Damping factor for SRF PLL, usually between 0 and 1
pll_bandwidth_hz = single(30); %% Bandwidth of PLL
pll_sat_min = single(-150000); %% Lower limit saturation for PLL PI regulator
pll_sat_max = single(150000); %% Upper limit saturation for PLL PI regulator


lpf_freq_out_cutoff_hz = single(15); %%cut off for frequency (Hz) LPF output
lpf_rms_out_cutoff_hz = single(25); %%cut off for frequency (Hz) LPF output


sample_time_s = single(100e-6); %%Sample time/period/loop frequency
Ts = sample_time_s; %% for simulation vars
sample_time_s_d = double(sample_time_s); % for simulation step settings 


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
filter_rms_out_init = single(220);


%% SRF PLL Config
SRF_PI_P = single(2*2*pi*pll_bandwidth_hz*damping_factor_zeta);
SRF_PI_I = single((2*pll_bandwidth_hz*pi)^2);
