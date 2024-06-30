#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C" {
#include "src/artificialBird.X/headers/ReceiveSignal.h"
#include "src/artificialBird.X/headers/ControlMotor.h"
}

//
// モック関数
//
int wrPHOTO1_GetValue(void){
    return mock().actualCall("wrPHOTO1_GetValue").returnIntValueOrDefault(0);
}
int wrPHOTO2_GetValue(void){
    return mock().actualCall("wrPHOTO2_GetValue").returnIntValueOrDefault(0);
}
int wrPHOTO3_GetValue(void){
    return mock().actualCall("wrPHOTO3_GetValue").returnIntValueOrDefault(0);
}
int wrPHOTO4_GetValue(void){
    return mock().actualCall("wrPHOTO4_GetValue").returnIntValueOrDefault(0);
}

void TestUtil_SetGetValueMock(int SensorValue);

TEST_GROUP(ReceiveSignalUT){
    void setup(){
        mock().clear();
        InitReceiveSignal();
    }
    void teardown() {
        mock().checkExpectations();     //期待する呼び出しが行われたことを確認
        mock().clear();  // モックをクリア //mockは()を忘れずに
    }
};  // TEST_GROUPには「;」が必要。構造体で実装しているらしい。

/**
 * @brief wrPHOTO1_GetValue関数のモック動作を確認するテスト
 */
TEST(ReceiveSignalUT, WrPHOTO1_GetValueTest) {
    // Arrange
    mock().expectOneCall("wrPHOTO1_GetValue").andReturnValue(1);

    // Act
    int result = wrPHOTO1_GetValue();

    // Assert
    CHECK_EQUAL(1, result);
}
/**
 * @brief wrPHOTO1_GetValue関数のモック動作を確認するテスト
 */
TEST(ReceiveSignalUT, WrPHOTO1_GetValue_Defoult_Test) {
    // Arrange
    mock().expectOneCall("wrPHOTO1_GetValue");

    // Act
    int result = wrPHOTO1_GetValue();

    // Assert
    CHECK_EQUAL(0, result);
}


/**
 * @brief 受光しているのが4つの受光素子のどれか一つであっても、入力として適切に使用できることを確認する
 */
TEST(ReceiveSignalUT, InputMergeTest_AllSensorsOff) {
    // Arrange
    mock().expectOneCall("wrPHOTO1_GetValue").andReturnValue(0);
    mock().expectOneCall("wrPHOTO2_GetValue").andReturnValue(0);
    mock().expectOneCall("wrPHOTO3_GetValue").andReturnValue(0);
    mock().expectOneCall("wrPHOTO4_GetValue").andReturnValue(0);
    int result = 2;
    // Act
    
    result = InputMerge();

    // Assert
    CHECK_EQUAL(0, result);

}

/**
 * @brief InputMerge関数のテスト: 受光素子1がONのときの動作を確認する
 */
TEST(ReceiveSignalUT, InputMergeTest_OneSensorOn) {
    // Arrange
    mock().expectOneCall("wrPHOTO1_GetValue").andReturnValue(1);
    mock().expectOneCall("wrPHOTO2_GetValue").andReturnValue(0);
    mock().expectOneCall("wrPHOTO3_GetValue").andReturnValue(0);
    mock().expectOneCall("wrPHOTO4_GetValue").andReturnValue(0);

    // Act
    int result = InputMerge();

    // Assert
    CHECK_EQUAL(1, result);
}


/**
 * @brief InputMerge関数のテスト: 複数の受光素子がONのときの動作を確認する
 */
TEST(ReceiveSignalUT, InputMergeTest_MultipleSensorsOn) {
    // Arrange
    mock().expectOneCall("wrPHOTO1_GetValue").andReturnValue(1);
    mock().expectOneCall("wrPHOTO2_GetValue").andReturnValue(1);
    mock().expectOneCall("wrPHOTO3_GetValue").andReturnValue(1);
    mock().expectOneCall("wrPHOTO4_GetValue").andReturnValue(1);

    // Act
    int result = InputMerge();

    // Assert
    CHECK_EQUAL(1, result);
}

/**
 * @brief InitReceiveSignalでパラメータを初期化する
 */
TEST(ReceiveSignalUT, InitReceiveSignal) {
    // Arrange
    g_CntCh1 = 999;
    g_CntCh2 = 999;
    g_CntCh3 = 999;
    f_UpdateParam = 999;
    g_SignalState = 999;

    // Act
    InitReceiveSignal();

    // Assert
    CHECK_EQUAL(0, g_CntCh1);
    CHECK_EQUAL(0, g_CntCh2);
    CHECK_EQUAL(0, g_CntCh3);
    CHECK_EQUAL(0, g_SignalState);
    CHECK_EQUAL(0, f_UpdateParam);
}

/**
 * @brief InputMergeが特定の順番で値を返す場合のAnalizeSignalの動作を確認するテスト
 */
TEST(ReceiveSignalUT, AnalizeSignalTest) {
    CHECK_EQUAL(0, g_CntCh1);
    CHECK_EQUAL(0, g_CntCh2);
    CHECK_EQUAL(0, g_CntCh3);

    // Arrange
    TestUtil_SetGetValueMock(1); //1
    TestUtil_SetGetValueMock(0); //2
    TestUtil_SetGetValueMock(0); //3
    TestUtil_SetGetValueMock(1); //4
    TestUtil_SetGetValueMock(0); //5
    TestUtil_SetGetValueMock(0); //6
    TestUtil_SetGetValueMock(0); //7
    TestUtil_SetGetValueMock(1); //8
    TestUtil_SetGetValueMock(0); //9
    TestUtil_SetGetValueMock(0); //10
    TestUtil_SetGetValueMock(0); //11
    TestUtil_SetGetValueMock(0); //12
    TestUtil_SetGetValueMock(1); //13
    TestUtil_SetGetValueMock(1); //14
//    TestUtil_SetGetValueMock(1); //15

    // Act
    for (int i = 0; i < 14; ++i) {
        AnalizeSignal();
    }

    // Assert
    CHECK_EQUAL(2, g_CntCh1);
    CHECK_EQUAL(3, g_CntCh2);
    CHECK_EQUAL(4, g_CntCh3);
}

/**
 * @brief AnalizeSignalの終端でフラグが立つことを確認するテスト
 */
TEST(ReceiveSignalUT, RiseFlagTest) {
    CHECK_EQUAL(0, f_UpdateParam);
    CHECK_EQUAL(0, g_SignalState);

    // Arrange
    TestUtil_SetGetValueMock(1); //1
    TestUtil_SetGetValueMock(0); //2
    TestUtil_SetGetValueMock(1); //3
    TestUtil_SetGetValueMock(0); //4
    TestUtil_SetGetValueMock(1); //5
    TestUtil_SetGetValueMock(0); //6
    TestUtil_SetGetValueMock(1); //7
    TestUtil_SetGetValueMock(1); //8
    TestUtil_SetGetValueMock(1); //9

    // Act
    for (int i = 0; i < 9; ++i) {
        AnalizeSignal();
    }

    // Assert
    CHECK_EQUAL(1, f_UpdateParam);
    CHECK_EQUAL(0, g_SignalState);
}

/**
 * @brief AnalizeSignalの各状態を確認するテスト
 */
TEST(ReceiveSignalUT, AnalizeSignalStateTest) {
    CHECK_EQUAL(0, g_SignalState);

    // Arrange
    TestUtil_SetGetValueMock(1); //1
    TestUtil_SetGetValueMock(0); //2
    TestUtil_SetGetValueMock(1); //3
    TestUtil_SetGetValueMock(0); //4
    TestUtil_SetGetValueMock(1); //5
    TestUtil_SetGetValueMock(0); //6
    TestUtil_SetGetValueMock(1); //7
    TestUtil_SetGetValueMock(1); //8
    TestUtil_SetGetValueMock(1); //9

    // Act & Assert
    AnalizeSignal();
    CHECK_EQUAL(1, g_SignalState);
    AnalizeSignal();
    AnalizeSignal();
    CHECK_EQUAL(2, g_SignalState);
    AnalizeSignal();
    AnalizeSignal();
    CHECK_EQUAL(3, g_SignalState);
    AnalizeSignal();
    AnalizeSignal();
    CHECK_EQUAL(4, g_SignalState);
    AnalizeSignal();
    CHECK_EQUAL(5, g_SignalState);
    AnalizeSignal();
    CHECK_EQUAL(0, g_SignalState);
}

/**
 * @brief UpdateRefs関数のテスト
 */
TEST(ReceiveSignalUT, UpdateRefsTest) {
    // Arrange
    g_CntCh1 = 5;
    g_CntCh2 = 10;
    g_CntCh3 = 15;
    f_UpdateParam = 1;

    // Act
    UpdateRefs();

    // Assert
    CHECK_EQUAL(5, DcMotorRef);
    CHECK_EQUAL(10, ServoARef);
    CHECK_EQUAL(15, ServoBRef);
    CHECK_EQUAL(0, f_UpdateParam); // フラグがリセットされることを確認
}

//
// テスト用ユーティリティ
//

/**
 * @brief wrPHOTOn_GetValueモックをまとめてセットする
 */
void TestUtil_SetGetValueMock(int SensorValue){
    mock().expectNCalls(1, "wrPHOTO1_GetValue").andReturnValue(SensorValue);
    mock().expectNCalls(1, "wrPHOTO2_GetValue").andReturnValue(SensorValue);
    mock().expectNCalls(1, "wrPHOTO3_GetValue").andReturnValue(SensorValue);
    mock().expectNCalls(1, "wrPHOTO4_GetValue").andReturnValue(SensorValue);
}