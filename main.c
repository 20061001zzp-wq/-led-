#include "stm32f10x.h"

/**
 * @brief  初始化用于连接 LED 的 GPIO（示例：PC13）。
 * @note   请根据开发板实际 LED 引脚修改 GPIO 端口与引脚号。
 */
static void LED_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* 1. 使能 GPIOC 时钟（PC13 所在端口） */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    /* 2. 配置 PC13 为推挽输出，速度 2MHz */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

int main(void)
{
    /* 初始化 LED 引脚 */
    LED_GPIO_Config();

    /*
     * 很多 STM32 开发板（如最小系统板）上的 PC13 LED 为“低电平点亮”：
     * 输出 0 -> LED 亮
     * 输出 1 -> LED 灭
     */
    GPIO_ResetBits(GPIOC, GPIO_Pin_13);  /* 点亮 LED */

    while (1)
    {
        /* 保持常亮 */
    }
}
