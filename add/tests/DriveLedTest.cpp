
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C" {
#include "src/artificialBird.X/headers/DriveLed.h"
}

//
// モック関数
//
void wrLED1_SetHigh(void){
    mock().actualCall("wrLED1_SetHigh");
}
void wrLED1_SetLow(void){
    mock().actualCall("wrLED1_SetLow");
}
void wrLED1_Toggle(void){
    mock().actualCall("wrLED1_Toggle");
}

TEST_GROUP(DriveLedUT) {
    void setup() {
        mock().clear();
    }
    void teardown() {
        mock().checkExpectations();     //期待する呼び出しが行われたことを確認
        mock().clear();                 // モックをクリア //mockは()を忘れずに 
    }
}; //TEST_GROUPには「;」が必要。構造体で実装しているらしい。

TEST_GROUP(MakePwmUT) {
    void setup() {
        mock().clear();
    }
    void teardown() {
        //mock().checkExpectations();     //期待する呼び出しが行われたことを確認
        mock().clear();                 // モックをクリア //mockは()を忘れずに 
    }
}; //TEST_GROUPには「;」が必要。構造体で実装しているらしい。


/**
 * @brief LED ONのマクロを呼び出すテスト
 */
TEST(DriveLedUT, LedOn) {
    // Arrange
    mock().expectOneCall("wrLED1_SetHigh");//MCC定義のマクロ関数が呼び出せればOK。
    int result=10;
    // Act
    result = DriveLed(IoON);
    // Assert
    CHECK_EQUAL(0, result);  // 正常終了なら0が帰る。
}

/**
 * @brief LED OFFのマクロを呼び出すテスト
 */
TEST(DriveLedUT, LedOff) {
    // Arrange
    mock().expectOneCall("wrLED1_SetLow");//MCC定義のマクロ関数が呼び出せればOK。
    int result=10;
    // Act
    result = DriveLed(IoOFF);
    // Assert
    CHECK_EQUAL(0, result);  // 正常終了なら0が帰る。
}

/**
 * @brief LED のトグル機能マクロを呼び出すテスト
 */
TEST(DriveLedUT, LedToggle) {
    // Arrange
    mock().expectOneCall("wrLED1_Toggle");//MCC定義のマクロ関数が呼び出せればOK。
    int result=10;
    // Act
    result = DriveLed(IoTOGGLE);
    // Assert
    CHECK_EQUAL(0, result);  // 正常終了なら0が帰る。
}

/**
 * @brief LED のトグル機能マクロを呼び出すテスト
 */
TEST(DriveLedUT, Led_InvalidInput) {
    // Arrange
    int result=10;
    // Act
    result = DriveLed(999);
    // Assert
    CHECK_EQUAL(1, result);  // 正常終了なら0が帰る。
}

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
