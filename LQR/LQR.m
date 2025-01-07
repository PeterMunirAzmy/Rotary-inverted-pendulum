% motor parameters 
motor_b = 0.010758;      % Damping Coefficient
motor_j = 0.0010337;      % System Inertia
motor_kb =0.0044813;     % Motor speed constant
motor_kt = 0.07292;     % Motor Torque constant
motor_l = 0.066883;  % Motor inductance
motor_r = 3.0018;     % Motor Resistance
motor_effeciency = 0.69;        % Motor effeciency
gear_box_effeciency = 0.9;      % Gearbox Effeciency
gear_box_ratio = 11;            % Motor gearbox ratio

%system parameters
m_pendulum = 27/1000;           %the mass of pendulum
r = 90/1000;                    %length of arm
l = (150/1000)/2;               %length of arm of pendulum

%state space parameters
a=motor_j+(m_pendulum*r*r);
b=m_pendulum*l*r;
c=(4/3)*m_pendulum*l*l;
d=m_pendulum*9.8*l;
E=(a*c)-(b*b);
G = ((motor_effeciency*gear_box_effeciency*motor_kb*motor_kt*(gear_box_ratio*gear_box_ratio))-(motor_b*motor_r))/(motor_r);
H= (motor_effeciency*gear_box_effeciency*motor_kt*gear_box_ratio)/(motor_r*E);

%state space Matrices
A_mat=[0 0 1 0;0 0 0 1;0 (b*d)/(E) (-(c*G)/E) 0 ; 0 ((a*d)/E) (-b*G)/E 0 ]; % system matrix
B_mat=[0;0;(c)*(H);(b)*(H)];    % input matrix  
C_mat=[1 0 0 0 ; 0 1 0 0];      % output matrix
D_mat=[0;0];                    % feedforward matrix

%state space
state_space_model=ss(A_mat,B_mat,C_mat,D_mat);

% LQR q and r
Q = diag([3      800     720       450]);
%      [theta  alpha  thetadot  alphadot]
R = 1;

%calc k
k=lqr(A_mat,B_mat,Q,R);    
k_theta = k(1);
k_alpha = k(2);
k_thetadot = k(3);
k_alphadot = k(4);

%constants
PWMBias = 35;
PWMSat = 255;

%calc rank
contr_matrix = ctrb(state_space_model);
rank_ord = rank(contr_matrix);

display(contr_matrix);
display(rank_ord);
display(k);



