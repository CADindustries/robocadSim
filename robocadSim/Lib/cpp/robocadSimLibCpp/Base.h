#pragma once

#ifdef ROBOCADSIMLIBCPP_EXPORTS
#define ROBOCADSIMLIBCPP_API __declspec(dllexport)
#else
#define ROBOCADSIMLIBCPP_API __declspec(dllimport)
#endif