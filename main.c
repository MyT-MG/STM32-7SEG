#include "main.h"

static void MX_GPIO_Init(void);

// Lookup table for digits 0–9
// For Common Anode: 0 = ON, 1 = OFF
uint8_t segCode[10][7] = {
 // a, b, c, d, e, f, g
 {0,0,0,0,0,0,1}, // 0
 {1,0,0,1,1,1,1}, // 1
 {0,0,1,0,0,1,0}, // 2
 {0,0,0,0,1,1,0}, // 3
 {1,0,0,1,1,0,0}, // 4
 {0,1,0,0,1,0,0}, // 5
 {0,1,0,0,0,0,0}, // 6
 {0,0,0,1,1,1,1}, // 7
 {0,0,0,0,0,0,0}, // 8
 {0,0,0,0,1,0,0}  // 9
};

int main(void)
{
  HAL_Init();
  MX_GPIO_Init();

  while (1)
  {
    for (int num = 0; num < 10; num++) // loop 0–9
    {
      for (int i = 0; i < 7; i++)
      {
        HAL_GPIO_WritePin(GPIOA, (GPIO_PIN_0 << i), segCode[num][i]);
      }
      HAL_Delay(1000); // 1 s delay per digit
    }
  }
}

/* GPIO Init Function */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|
                        GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
