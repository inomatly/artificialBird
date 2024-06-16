#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C" {
#include "src/artificialBird.X/headers/DriveLed.h"
#include "src/artificialBird.X/headers/MakePwm.h"
}

TEST_GROUP(MakePwmUT){void setup(){mock().clear();
}
void teardown() {
    // mock().checkExpectations();     //期待する呼び出しが行われたことを確認
    mock().clear();  // モックをクリア //mockは()を忘れずに
}
}
;  // TEST_GROUPには「;」が必要。構造体で実装しているらしい。



/**
 * @brief Dutyサイクル内でPWM信号がONになることを確認するテスト(50%)
 */
TEST(MakePwmUT, PwmSignal_DutyCycle_Fifty) {
    int Duty = 50;
    int SumOfNumeratorAndDenominator = 10;
    int LocalStep = 0;

    mock().expectNCalls(5, "wrLED1_SetHigh");
    mock().expectNCalls(5, "wrLED1_SetLow");
    
    for (int i = 0; i < SumOfNumeratorAndDenominator; ++i) {
        MakePWMformGPIO(Duty, SumOfNumeratorAndDenominator, &LocalStep);
    }
}

/**
 * @brief Dutyサイクル内でPWM信号がONになることを確認するテスト(30%)
 */
TEST(MakePwmUT, PwmSignal_DutyCycle_Thirty) {
    int Duty = 30;
    int SumOfNumeratorAndDenominator = 10;
    int LocalStep = 0;

    mock().expectNCalls(3, "wrLED1_SetHigh");
    mock().expectNCalls(7, "wrLED1_SetLow");
    
    for (int i = 0; i < SumOfNumeratorAndDenominator; ++i) {
        MakePWMformGPIO(Duty, SumOfNumeratorAndDenominator, &LocalStep);
    }
}

/**
 * @brief SumOfNumeratorAndDenominatorが奇数の場合の動作を確認するテスト
 */
TEST(MakePwmUT, OddPeriod_DutyCycle_Fifty) {
    int Duty = 50;
    int SumOfNumeratorAndDenominator = 5;
    int LocalStep = 0;

    mock().expectNCalls(2, "wrLED1_SetHigh");
    mock().expectNCalls(3, "wrLED1_SetLow");
    
    for (int i = 0; i < SumOfNumeratorAndDenominator; ++i) {
        MakePWMformGPIO(Duty, SumOfNumeratorAndDenominator, &LocalStep);
    }
}

/**
 * @brief LocalStepが最大値に達した後にリセットされることを確認するテスト
 */
TEST(MakePwmUT, LocalStepResetAfterMaxValue) {
    int Duty = 50;
    int SumOfNumeratorAndDenominator = 10;
    int LocalStep = 0;

    mock().expectNCalls(5, "wrLED1_SetLow");
    mock().expectNCalls(6, "wrLED1_SetHigh");
    for (int i = 0; i < 11; ++i) {
        MakePWMformGPIO(Duty, SumOfNumeratorAndDenominator, &LocalStep);
    }
}

/**
 * @brief Dutyサイクルの端でのPWM信号の挙動を確認するテスト
 */
TEST(MakePwmUT, PwmSignalEdgeCases_Zero) {
    int Duty = 0;
    int SumOfNumeratorAndDenominator = 10;
    int LocalStep = 0;
    mock().expectNCalls(10, "wrLED1_SetLow");
    for (int i = 0; i < 10; ++i) {
        MakePWMformGPIO(Duty, SumOfNumeratorAndDenominator, &LocalStep);
    }
}

/**
 * @brief Dutyサイクルの端でのPWM信号の挙動を確認するテスト
 */
TEST(MakePwmUT, PwmSignalEdgeCases_Full) {
    int Duty = 100;
    int SumOfNumeratorAndDenominator = 10;
    int LocalStep = 0;

    mock().expectNCalls(10, "wrLED1_SetHigh");
    for (int i = 0; i < 10; ++i) {
        MakePWMformGPIO(Duty, SumOfNumeratorAndDenominator, &LocalStep);
    }
}
