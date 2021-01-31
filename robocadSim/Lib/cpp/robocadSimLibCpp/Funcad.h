#pragma once

#include "Base.h"

class ROBOCADSIMLIBCPP_API Funcad 
{
public:
	float cos30;
	float cos60;

	Funcad();
	bool in_range_bool(float val, float min_v, float max_v);
	float* from_motors_to_axis(float right, float left, float back);
	float* from_axis_to_motors(float x, float y, float z);
	float transfunc_coda(float val, float* in_arr, float* out_arr, int size);
};