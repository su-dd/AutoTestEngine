/*!
 * @brief 头文件说明
 *
 * AutoTest引擎window实现
 * @author  王庆彬
 * @date:	2019/07/2
 * @remarks	
 * Copyright   (c) 1998-2012 Glodon Corporation
*/
#ifndef AUTOTESTENGINEUTILS_H
#define AUTOTESTENGINEUTILS_H

#include <qglobal.h>
#include <Windows.h>
#include <QtCore/QTranslator>
#include <QLocale>
#include <QtCore/QString>
#include <QApplication>
#include <QFile>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


const wstring  c_defEngineFileName       (L"AutoTestEngine.dll");

class AutoTestEngineHost
{
public:   
    static AutoTestEngineHost& instance();
	bool loadEngine();
    wstring getAppPath();
private:
    AutoTestEngineHost();
    ~AutoTestEngineHost();
	bool isFileExist(wstring &fileName);

private:
    static bool s_bisLoad;
	HINSTANCE m_Hinst;
};

bool AutoTestEngineHostInit();

#endif //AUTOTESTENGINEUTILS_H
