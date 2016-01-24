#pragma once
#include "BasicWindow.h"

class MainWindow : public BasicWindow<MainWindow>
{
public:
    MainWindow(void);
    ~MainWindow(void);
public:
    PCWSTR  ClassName() const { return TEXT("Sample Window Class"); }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

