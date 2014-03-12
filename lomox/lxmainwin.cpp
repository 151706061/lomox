
/*******************************************************************************
* ��Ȩ����(C) 1988-2014 All Rights Reserved.
*
* �ļ�����	: basewin.cpp
* ��    ��	: �̶��S (mailto:caidongyun19@qq.com)
* ��������	: 2014/3/9
* ��������	: 
* ��    ע	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxmainwin.h"
#include <QWebPage>
#include "lxdialogoperate.h"
#include "lxdialogs.h"
#include "lxwebpluginfactory.h"

LxMainWindow::LxMainWindow( QWidget* prarent /*= 0*/ )
:LxBaseWin(prarent)
{
/*	m_strApiName = LOMOX_API_DIALOG ;*/
	_initWidget();
	this->setRenderHints(QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);
	QObject::connect(this, SIGNAL(linkClicked(const QUrl&)), this, SLOT(linkClickedAction(const QUrl&)));
}



LxMainWindow::~LxMainWindow()
{

}
bool LxMainWindow::_initWidget()
{
	setObjectName("lomoxwin");

	do 
	{
		LxOption* pOption = lxCoreApp->getOption();

		if (!pOption)
			break;

		Qt::WindowFlags winType = Qt::Dialog ;

		if (pOption->getNeedShowMainNcFrame())
		{
			winType = Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint;
		}
		else
		{
			winType |= Qt::FramelessWindowHint;
			this->setAttribute(Qt::WA_TranslucentBackground, true);
			this->setStyleSheet("#lomoxwin{background-color:transparent} QMenu{background-color:none;}");
		}

		if (pOption->getMainWindowStaysOnTopHint())
			winType |= Qt::WindowStaysOnTopHint;

		this->setWindowFlags(winType);

		QPointer<QWebPage> ptrWebPage = this->page();
		QPointer<LxWebPluginFactory> ptrPlugin = new LxWebPluginFactory(ptrWebPage);
		ptrWebPage->setPluginFactory(ptrPlugin);
		ptrWebPage->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);//LinkDelegationPolicy::DelegateAllLinks
	} while (false);


	return true;
}



void LxMainWindow::linkClickedAction( const QUrl& url )
{
	LxDialogs* pDialogs = lxCoreApp->getDialogs();
	if (pDialogs)
	{
		QString strUrl = url.toString();
		QPointer<LxDialogBase> ptrDialog = reinterpret_cast<LxDialogBase*>(pDialogs->add(strUrl,strUrl));
		if (ptrDialog)
		{
			ptrDialog->show();
		}
	}
	return ;
}