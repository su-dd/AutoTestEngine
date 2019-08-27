#include "AutoTestEngine.h"

bool AutoTestEngineHost::s_bisLoad = AutoTestEngineHostInit();

AutoTestEngineHost::AutoTestEngineHost()
{
}

AutoTestEngineHost::~AutoTestEngineHost()
{
	if (m_Hinst)
	{
		FreeLibrary(m_Hinst); //Free����Dll
	}
}

AutoTestEngineHost& AutoTestEngineHost::instance()
{
    static AutoTestEngineHost s_engineHost;
    return s_engineHost;
}

/************************************************************************/
/*    ��������dll                                                         */
/*    Ѱ��dll˳��                                                         */
/* 1��Exe �£�2����ǰģ���£�3���������� AutoTestEngine��4��ע�����                  */
/*************************************************************************/
bool AutoTestEngineHost::loadEngine()
{	
    HANDLE nHandle = GetModuleHandle(c_defEngineFileName.c_str());
    if (nHandle != 0)
    {
        return true;
    }

    wstring strAutoTestEngine = getAppPath() + c_defEngineFileName;//��wstring���Լ���������·��
    OutputDebugString(strAutoTestEngine.c_str());

    if (!isFileExist(strAutoTestEngine))
    {
        //�ӵ�ǰģ���ң�û��ʵ��
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
/* �����ʼ����ֻ��Ҫ���ô˷�������                                                                     */
/************************************************************************/
bool AutoTestEngineHostInit()
{
    return AutoTestEngineHost::instance().loadEngine();
}
