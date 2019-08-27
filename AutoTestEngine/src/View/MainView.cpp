#include "MainView.h"
#include "CaseManager.h"
#include <QBoxLayout>

MainView::MainView(QWidget *parent)
    : QDialog(parent),
      m_pTextEdit(nullptr)
{
    initUI();
    initData();
}

MainView::~MainView()
{

}

void MainView::initUI()
{
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    this->setLayout(pLayout);

    m_pTextEdit = new QPlainTextEdit(NULL);
    pLayout->addWidget(m_pTextEdit);

    this->resize(500, 400);
}

void MainView::initData()
{
    ICase * pCase = UserOperationCaseManager::instance().take();
    while (nullptr != pCase)
    {
        m_pTextEdit->appendPlainText(pCase->ruby());
        delete pCase;
        pCase = nullptr;
        pCase = UserOperationCaseManager::instance().take();
    }
}

