#pragma once
#include "QWinApp.h"

class QDemoWinApp : public QWinApp
{
public:
    QDemoWinApp(void);
    ~QDemoWinApp(void);

private:

public:
    virtual BOOL InitInstance();
    virtual BOOL ExitInstance();
};

extern QDemoWinApp * theApp;

