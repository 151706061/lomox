

/*******************************************************************************
* ��Ȩ����(C) 1988-2014 All Rights Reserved.
*
* �ļ�����	: basewin.cpp
* ��    ��	: �̶��S (mailto:caidongyun19@qq.com)
* ��������	: 2014/3/9
* ��������	: 
* ��    ע	: 
********************************************************************************/

#ifndef __LXMAINWIN_H__
#define __LXMAINWIN_H__

#include "lomox_global.h"

#include "lxoption.h"

#include "lxbasewin.h"
#include "lxcoreapplication.h"
#include "lxcoreprivate.h"
#include <QtGui/QWidget>
class LxBaseWin;

class LOMOX_EXPORT LxMainWindow : public LxBaseWin
{
	Q_OBJECT
public:
	explicit LxMainWindow(QWidget* prarent = 0);

	virtual ~LxMainWindow();

	bool _initWidget();

// public slots:
// 	void linkClickedAction( const QUrl& url );

};


#endif