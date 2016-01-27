#pragma once
#include "stdafx.h"
#include "QWnd.h"

class QMainFrame : public QWnd
{
public:
    QMainFrame(void);
    ~QMainFrame(void);

public:
    // message handle
    virtual LRESULT OnClose(WPARAM wParam, LPARAM lParam);
    virtual LRESULT OnDestroy(WPARAM wParam, LPARAM lParam);
    virtual LRESULT OnCreate(WPARAM wParam, LPARAM lParam);

};

