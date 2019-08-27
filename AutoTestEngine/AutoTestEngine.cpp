#include "AutoTestEngine.h"

bool AutoTestEngineHost::s_bisLoad = AutoTestEngineHostInit();

AutoTestEngineHost::AutoTestEngineHost()
{
}

AutoTestEngineHost::~AutoTestEngineHost()
{
	if (m_Hinst)
	{
		FreeLibrary(m_Hinst); //Free引擎Dll
	}
}

AutoTestEngineHost& AutoTestEngineHost::instance()
{
    static AutoTestEngineHost s_engineHost;
    return s_engineHost;
}

/************************************************************************/
/*    加载引擎dll                                                         */
/*    寻找dll顺序                                                         */
/* 1、Exe 下；2、当前模块下；3、坏境变量 AutoTestEngine；4、注册表中                  */
/*************************************************************************/
bool AutoTestEngineHost::loadEngine()
{	
    HANDLE nHandle = GetModuleHandle(c_defEngineFileName.c_str());
    if (nHandle != 0)
    {
        return true;
    }

    wstring strAutoTestEngine = getAppPath() + c_defEngineFileName;//用wstring可以兼容有中文路径
    OutputDebugString(strAutoTestEngine.c_str());

    if (!isFileExist(strAutoTestEngine))
    {
        //从当前模块找，没有实现
        wstring ex (L"Engine not Exist!\r\n");
        ex = strAutoTestEngine + ex;
        OutputDebugString(ex.c_str());
	}

    if (!isFileExist(strAutoTestEngine))
    {
        return false;
    }


    m_Hinst = ::LoadLibrary(strAutoTestEngine.c_str());
	if (!m_Hinst)
	{
        wstring ex (L"Load AutoTestEngine Error!\r\n");
		OutputDebugString(ex.c_str());
        return false;
	}
    wstring ex (L" Engine OK!\r\n");
	OutputDebugString(ex.c_str());
	return true;
}

wstring AutoTestEngineHost::getAppPath()
{
    return QApplication::applicationDirPath().toStdWString();
}

bool AutoTestEngineHost::isFileExist(wstring &fileName)
{
    return QFile::exists(QString::fromStdWString(fileName));
}

/************************************************************************/
/* 引擎初始化，只需要调用此方法就行                                                                     */
/************************************************************************/
bool AutoTestEngineHostInit()
{
    return AutoTestEngineHost::instance().loadEngine();
}
