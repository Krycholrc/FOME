#include "engine_test_helper.h"

extern WarningCodeState unitTestWarningCodeState;
extern float getTachFreq(void);
extern float getTachDuty(void);

TEST(tachometer, testPulsePerRev) {
    // This engine has a tach pin set - we need that
    WITH_ENGINE_TEST_HELPER(MAZDA_MIATA_2003);

    // We don't actually care about ign/inj at all, just tach
    engineConfiguration->isInjectionEnabled = false;
    engineConfiguration->isIgnitionEnabled = false;

    // Configure tach pulse count
    // 5 PPR, 25% duty
    engineConfiguration->tachPulsePerRev = 4;
    engineConfiguration->tachPulseDuractionMs = 0.5f;
    engineConfiguration->tachPulseDurationAsDutyCycle = true;

	engineConfiguration->specs.cylindersCount = 6;
	engineConfiguration->specs.firingOrder = FO_1_5_3_6_2_4;
	engineConfiguration->injectionMode = IM_BATCH;
	engineConfiguration->twoWireBatchInjection = true;
	engineConfiguration->ignitionMode = IM_WASTED_SPARK;
	engineConfiguration->useOnlyRisingEdgeForTrigger = true;

	engineConfiguration->tachOutputPin = GPIOC_8;

	setOperationMode(engineConfiguration, FOUR_STROKE_CRANK_SENSOR);

	engineConfiguration->trigger.type = TT_TOOTHED_WHEEL;
	engineConfiguration->trigger.customTotalToothCount = 30;
	engineConfiguration->trigger.customSkippedToothCount = 1;

    // Set predictable trigger settings
    engineConfiguration->trigger.customTotalToothCount = 8;
    engineConfiguration->trigger.customSkippedToothCount = 0;
    engineConfiguration->useOnlyRisingEdgeForTrigger = false;
    engineConfiguration->ambiguousOperationMode = FOUR_STROKE_CAM_SENSOR;
	eth.applyTriggerWaveform();

    // get the engine running - 6 revolutions
    eth.fireTriggerEvents(48);

    // ensure engine speed and position
	ASSERT_EQ(1500,  GET_RPM()) << "RPM";
	ASSERT_EQ(15,  engine->triggerCentral.triggerState.getCurrentIndex()) << "index #1";
    ASSERT_EQ(engine->triggerCentral.triggerState.shaft_is_synchronized, true);
/* TODO Restore testPulsePerRev #2130
    ASSERT_EQ(100,getTachFreq());
    ASSERT_EQ(0.5,getTachDuty());
std::cerr << "Tach Freq: " << getTachFreq() << "\n" << std::endl;
std::cerr << "Tach Duty: " << getTachDuty() << "\n" << std::endl;
 */
}
