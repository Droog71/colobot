// * This file is part of the COLOBOT source code
// * Copyright (C) 2001-2008, Daniel ROUX & EPSITEC SA, www.epsitec.ch
// *
// * This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with this program. If not, see  http://www.gnu.org/licenses/.

// interface.cpp


#include <windows.h>
#include <stdio.h>
#include <d3d.h>

#include "common/struct.h"
#include "graphics/d3d/d3dengine.h"
#include "math/old/math3d.h"
#include "common/event.h"
#include "common/misc.h"
#include "common/iman.h"
#include "ui/control.h"
#include "ui/button.h"
#include "ui/color.h"
#include "ui/check.h"
#include "ui/key.h"
#include "ui/group.h"
#include "ui/image.h"
#include "ui/label.h"
#include "ui/edit.h"
#include "ui/editvalue.h"
#include "ui/scroll.h"
#include "ui/slider.h"
#include "ui/list.h"
#include "ui/shortcut.h"
#include "ui/compass.h"
#include "ui/target.h"
#include "ui/map.h"
#include "ui/window.h"
#include "graphics/common/camera.h"
#include "ui/interface.h"




// Object's constructor.

CInterface::CInterface(CInstanceManager* iMan)
{
	int		i;

	m_iMan = iMan;
	m_iMan->AddInstance(CLASS_INTERFACE, this);

	m_engine = (CD3DEngine*)m_iMan->SearchInstance(CLASS_ENGINE);
	m_camera = 0;

	for ( i=0 ; i<MAXCONTROL ; i++ )
	{
		m_table[i] = 0;
	}
}

// Object's destructor.

CInterface::~CInterface()
{
	Flush();
}


// Purge all controls.

void CInterface::Flush()
{
	int		i;

	for ( i=0 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] != 0 )
		{
			delete m_table[i];
			m_table[i] = 0;
		}
	}
}


// Creates a new button.

CWindow* CInterface::CreateWindows(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CWindow*	pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	if ( eventMsg == EVENT_WINDOW0 )  {i=0; goto create;}
	if ( eventMsg == EVENT_WINDOW1 )  {i=1; goto create;}
	if ( eventMsg == EVENT_WINDOW2 )  {i=2; goto create;}
	if ( eventMsg == EVENT_WINDOW3 )  {i=3; goto create;}
	if ( eventMsg == EVENT_WINDOW4 )  {i=4; goto create;}
	if ( eventMsg == EVENT_WINDOW5 )  {i=5; goto create;}
	if ( eventMsg == EVENT_WINDOW6 )  {i=6; goto create;}
	if ( eventMsg == EVENT_WINDOW7 )  {i=7; goto create;}
	if ( eventMsg == EVENT_WINDOW8 )  {i=8; goto create;}
	if ( eventMsg == EVENT_WINDOW9 )  {i=9; goto create;}

	if ( eventMsg == EVENT_TOOLTIP )  {i=MAXCONTROL-1; goto create;}

	for ( i=10 ; i<MAXCONTROL-1 ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			create:
			m_table[i] = new CWindow(m_iMan);
			pc = (CWindow*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new button.

CButton* CInterface::CreateButton(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CButton*	pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CButton(m_iMan);
			pc = (CButton*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new button.

CColor* CInterface::CreateColor(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CColor*		pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CColor(m_iMan);
			pc = (CColor*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new button.

CCheck* CInterface::CreateCheck(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CCheck*		pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CCheck(m_iMan);
			pc = (CCheck*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new button.

CKey* CInterface::CreateKey(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CKey*		pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CKey(m_iMan);
			pc = (CKey*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new button.

CGroup* CInterface::CreateGroup(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CGroup*		pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CGroup(m_iMan);
			pc = (CGroup*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new button.

CImage* CInterface::CreateImage(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CImage*		pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CImage(m_iMan);
			pc = (CImage*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new label.

CLabel* CInterface::CreateLabel(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg,
							 char *name)
{
	CLabel*		pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CLabel(m_iMan);
			pc = (CLabel*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			pc->SetName(name);
			return pc;
		}
	}
	return 0;
}

// Creates a new pave editable.

CEdit* CInterface::CreateEdit(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CEdit*		pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CEdit(m_iMan);
			pc = (CEdit*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new pave editable.

CEditValue* CInterface::CreateEditValue(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CEditValue*	pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CEditValue(m_iMan);
			pc = (CEditValue*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new lift.

CScroll* CInterface::CreateScroll(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CScroll*	pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CScroll(m_iMan);
			pc = (CScroll*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new cursor.

CSlider* CInterface::CreateSlider(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CSlider*	pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CSlider(m_iMan);
			pc = (CSlider*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new list.

CList* CInterface::CreateList(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg,
							float expand)
{
	CList*		pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CList(m_iMan);
			pc = (CList*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg, expand);
			return pc;
		}
	}
	return 0;
}

// Creates a new shortcut.

CShortcut* CInterface::CreateShortcut(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CShortcut*	ps;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CShortcut(m_iMan);
			ps = (CShortcut*)m_table[i];
			ps->Create(pos, dim, icon, eventMsg);
			return ps;
		}
	}
	return 0;
}

// Creates a new compass.

CCompass* CInterface::CreateCompass(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CCompass*	pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CCompass(m_iMan);
			pc = (CCompass*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new target.

CTarget* CInterface::CreateTarget(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CTarget*	pc;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CTarget(m_iMan);
			pc = (CTarget*)m_table[i];
			pc->Create(pos, dim, icon, eventMsg);
			return pc;
		}
	}
	return 0;
}

// Creates a new map.

CMap* CInterface::CreateMap(Math::Point pos, Math::Point dim, int icon, EventMsg eventMsg)
{
	CMap*		pm;
	int			i;

	if ( eventMsg == EVENT_NULL )  eventMsg = GetUniqueEventMsg();

	for ( i=10 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] == 0 )
		{
			m_table[i] = new CMap(m_iMan);
			pm = (CMap*)m_table[i];
			pm->Create(pos, dim, icon, eventMsg);
			return pm;
		}
	}
	return 0;
}

// Removes a control.

bool CInterface::DeleteControl(EventMsg eventMsg)
{
	int		i;

	for ( i=0 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] != 0 )
		{
			if ( eventMsg == m_table[i]->RetEventMsg() )
			{
				delete m_table[i];
				m_table[i] = 0;
				return true;
			}
		}
	}
	return false;
}

// Gives a control.

CControl* CInterface::SearchControl(EventMsg eventMsg)
{
	int		i;

	for ( i=0 ; i<MAXCONTROL ; i++ )
	{
		if ( m_table[i] != 0 )
		{
			if ( eventMsg == m_table[i]->RetEventMsg() )
			{
				return m_table[i];
			}
		}
	}
	return 0;
}

// Management of an event.

bool CInterface::EventProcess(const Event &event)
{
	int		i;

	if ( event.event == EVENT_MOUSEMOVE )
	{
		if ( m_camera == 0 )
		{
			m_camera = (CCamera*)m_iMan->SearchInstance(CLASS_CAMERA);
		}
		m_engine->SetMouseType(m_camera->RetMouseDef(event.pos));
	}

	for ( i=MAXCONTROL-1 ; i>=0 ; i-- )
	{
		if ( m_table[i] != 0 &&
			 m_table[i]->TestState(STATE_ENABLE) )
		{
			if ( !m_table[i]->EventProcess(event) )
			{
				return false;
			}
		}
	}

	return true;
}


// Gives the tooltip binding to the window.

bool CInterface::GetTooltip(Math::Point pos, char* name)
{
	int		i;

	for ( i=MAXCONTROL-1 ; i>=0 ; i-- )
	{
		if ( m_table[i] != 0 )
		{
			if ( m_table[i]->GetTooltip(pos, name) )
			{
				return true;
			}
		}
	}
	return false;
}


// Draws all buttons.

void CInterface::Draw()
{
	D3DMATERIAL7	material;
	int				i;

	ZeroMemory( &material, sizeof(D3DMATERIAL7) );
	material.diffuse.r = 1.0f;
	material.diffuse.g = 1.0f;
	material.diffuse.b = 1.0f;
	material.ambient.r = 0.5f;
	material.ambient.g = 0.5f;
	material.ambient.b = 0.5f;
	m_engine->SetMaterial(material);

	for ( i=0 ; i<MAXCONTROL ; i++ )
//?	for ( i=MAXCONTROL-1 ; i>=0 ; i-- )
	{
		if ( m_table[i] != 0 )
		{
			m_table[i]->Draw();
		}
	}
}

