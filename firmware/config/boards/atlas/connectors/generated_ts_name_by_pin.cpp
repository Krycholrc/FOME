//DO NOT EDIT MANUALLY, let automation work hard.

// auto-generated by PinoutLogic.java based on config/boards/atlas/connectors/analog.yaml
// auto-generated by PinoutLogic.java based on config/boards/atlas/connectors/digital_in.yaml
// auto-generated by PinoutLogic.java based on config/boards/atlas/connectors/outputs.yaml
#include "pch.h"

// see comments at declaration in pin_repository.h
const char * getBoardSpecificPinName(brain_pin_e brainPin) {
	switch(brainPin) {
		case Gpio::A0: return "Analog Volt 1";
		case Gpio::A1: return "Analog Volt 2";
		case Gpio::A15: return "Lowside 7";
		case Gpio::A2: return "Analog Volt 3";
		case Gpio::A3: return "Analog Volt 4";
		case Gpio::A4: return "Analog Volt 5";
		case Gpio::A5: return "Analog Volt 6";
		case Gpio::A6: return "Analog Volt 7";
		case Gpio::A7: return "Analog Volt 8";
		case Gpio::B0: return "Analog Volt 9";
		case Gpio::B1: return "Analog Volt 10";
		case Gpio::B3: return "Ignition 1";
		case Gpio::B4: return "Lowside 9";
		case Gpio::B5: return "Lowside 10";
		case Gpio::B6: return "Lowside 11";
		case Gpio::B7: return "Lowside 12";
		case Gpio::B8: return "Lowside 13";
		case Gpio::B9: return "Lowside 14";
		case Gpio::C0: return "Analog Volt 11";
		case Gpio::C1: return "Analog Temp 1";
		case Gpio::C2: return "Analog Temp 2";
		case Gpio::C3: return "Analog Temp 3";
		case Gpio::C4: return "Analog Temp 4";
		case Gpio::C6: return "Lowside 5";
		case Gpio::C7: return "Lowside 6";
		case Gpio::D15: return "Highside 4";
		case Gpio::D3: return "Lowside 8";
		case Gpio::D4: return "Ignition 12";
		case Gpio::D5: return "Ignition 11";
		case Gpio::D6: return "Ignition 10";
		case Gpio::D7: return "Ignition 9";
		case Gpio::E0: return "Lowside 15";
		case Gpio::E1: return "Lowside 16";
		case Gpio::E10: return "Digital 3";
		case Gpio::E11: return "Digital 4";
		case Gpio::E12: return "Digital 5";
		case Gpio::E13: return "Digital 6";
		case Gpio::E14: return "VR 1";
		case Gpio::E15: return "VR 2";
		case Gpio::G0: return "Digital 1";
		case Gpio::G1: return "Digital 2";
		case Gpio::G10: return "Ignition 7";
		case Gpio::G11: return "Ignition 6";
		case Gpio::G12: return "Ignition 5";
		case Gpio::G13: return "Ignition 4";
		case Gpio::G14: return "Ignition 3";
		case Gpio::G15: return "Ignition 2";
		case Gpio::G2: return "Highside 3";
		case Gpio::G3: return "Highside 2";
		case Gpio::G4: return "Highside 1";
		case Gpio::G5: return "Lowside 1";
		case Gpio::G6: return "Lowside 2";
		case Gpio::G7: return "Lowside 3";
		case Gpio::G8: return "Lowside 4";
		case Gpio::G9: return "Ignition 8";
		default: return nullptr;
	}
	return nullptr;
}
