GPIO Conf.
==========

1. Thruster

Name | Pin | Func.
--- | --- | --- 
M1-PWM | PA1 | TIM2_CH2 
M1-CS  | PA2 | ADC123_IN2
M1-ENA | PC3 | out       
M1-ENB | PA3 | out        
M1-INA | PC3 | out        
M1-INB | PA4 | out        
ENC1   | PC6 | TIM8_CH1   
ENC2   | PC7 | TIM8_CH2   

2. Tank
* M2-PWM -> PB0 -> TIM1_CH2N
* M2-ENA -> PB1 -> out
* M2-ENB -> PA6 -> out 
* M2-INA -> PB2 -> out
* M2-INB -> PA5 -> out
* TRANS  -> PC8 -> ?

3. Ledd
* SRV1    -> PA8  -> ?
* SRV2    -> PA11 -> ?
* LED-PWM -> PC9  -> TIM3_CH4
