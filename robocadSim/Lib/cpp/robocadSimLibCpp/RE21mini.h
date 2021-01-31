#pragma once

#include "Base.h"

#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <windows.h>
// #include <opencv2/opencv.hpp>
#include <fileapi.h>
#include <fstream>

using namespace cv;


#define MAX_PATH 260

class ROBOCADSIMLIBCPP_API RE21mini
{
public:
	float rightMotorSpeed;
	float leftMotorSpeed;
	float backMotorSpeed;

	float liftMotorSpeed;
	float bigServoAngle;
	float smallServoDir;

	float rightMotorEnc;
	float leftMotorEnc;
	float backMotorEnc;
	float liftMotorEnc;

	bool resetRightEnc;
	bool resetLeftEnc;
	bool resetBackEnc;
	bool resetLiftEnc;

	bool resetGyro;

	bool buttonEMS;
	bool buttonStart;
	bool buttonLimit;

	float rightUS;
	float rightIR;
	float leftUS;
	float leftIR;

	float navX;

	Mat imageFromCamera;
	char* bytesFromCamera;

	RE21mini();

	void WriteMotors(float right, float left, float back);
	void WriteOMS(float lift, float big, float small_s);
	void WriteReset(bool right, bool left, bool back, bool lift, bool gyro);
	float* ReadEncs();
	float* ReadSensors();
	bool* ReadButtons();
	Mat ReadCamera();
	char* ReadCameraBytes();

	void WriteMotorsVoid();
	void WriteOMSVoid();
	void WriteResetVoid();
	void ReadEncsVoid();
	void ReadSensorsVoid();
	void ReadButtonsVoid();
	void ReadCameraVoid();
	void ReadCameraBytesVoid();

private:
	bool IsPathExist(const std::string& s);

	std::string pathTMP;
	std::string pathToMotors;
	std::string pathToOMS;
	std::string pathToEncs;
	std::string pathToLED;
	std::string pathToSensors;
	std::string pathToButtons;
	std::string pathToReset;
	std::string pathToCamera;
	std::string pathToOtherSet;
	std::string pathToOtherGet;

	std::string lastEncsRead = "0.0;0.0;0.0;0.0";
	std::string lastSensRead = "0.0;0.0;0.0;0.0;0.0";
	std::string lastButtonsRead = "0;0;0";

	DWORD dwBuffSize = MAX_PATH;
	char lpPathBuffer[MAX_PATH];

};
