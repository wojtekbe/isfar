Motor driver
====
| Name    | Pin  |  Func.    |
| ------- | ---- | --------- |
| M1_ENA  | PC3  |           |
| M1_ENB  | PA3  |           |
| M1_INA  | PC2  |           |
| M1_INB  | PA4  |           |
| M1_PWM  | PA1  | TIM2_CH2  |
| M1_CS   | PA2  | ADCx_IN2  |
| ENC1    | PC6  | TIM8_CH1  |
| ENC2    | PC7  | TIM8_CH2  |

TIM4 -> calculate speed isr 
TIM5 -> PID isr

Tank driver
====
| Name    | Pin  |  Func.    |
| ------- | ---- | --------- |
| M2_ENA  | PB1  |           |
| M2_ENB  | PA6  |           |
| M2_INA  | PB2  |           |
| M2_INB  | PA5  |           |
| M2_PWM  | PB0  | TIM1_CH2N |
| M2_CS   | PA7  | ADCx_IN7  |
| TRANS	  | PB6  | TIM3_CH3* |
| MIN     | PB10 |           |
| MAX     | PB11 |           |

* counting in isr

LED driver
====
| Name    | Pin  |  Func.    |
| ------- | ---- | --------- |
| LED_PWM | PC9  | TIM3_CH4  |
| SM1_PWM | PA0  | TIM5_CH1  |
| SM2_PWM | PA1  | TIM5_CH2  |

External IO
===
| Name    | Pin  |  Func.    |
| ------- | ---- | --------- |
| G_ADC1  | PC0  | ADC3_IN10 |
| G_ADC2  | PC1  | ADCx_IN11 |
