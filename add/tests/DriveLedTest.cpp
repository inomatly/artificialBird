
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