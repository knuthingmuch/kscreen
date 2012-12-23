/*************************************************************************************
*  Copyright (C) 2012 by Alejandro Fiestas Olivares <afiestas@kde.org>              *
*                                                                                   *
*  This program is free software; you can redistribute it and/or                    *
*  modify it under the terms of the GNU General Public License                      *
*  as published by the Free Software Foundation; either version 2                   *
*  of the License, or (at your option) any later version.                           *
*                                                                                   *
*  This program is distributed in the hope that it will be useful,                  *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
*  GNU General Public License for more details.                                     *
*                                                                                   *
*  You should have received a copy of the GNU General Public License                *
*  along with this program; if not, write to the Free Software                      *
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
*************************************************************************************/

#ifndef KSCREN_DAEMON_H
#define KSCREN_DAEMON_H

#include <QtCore/QVariant>

#include <kdedmodule.h>

class KDE_EXPORT KScreenDaemon : public KDEDModule
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.KScreen")

    public:
        KScreenDaemon(QObject *parent, const QList<QVariant>&);
        virtual ~KScreenDaemon();

    public Q_SLOTS:
        void init();
        void applyConfig();
        void configChanged();
        void saveCurrentConfig();
        void displayButton();

    private:
        void monitorForChanges();

        quint8 m_iteration;
        bool m_pendingSave;
};

#endif /*KSCREN_DAEMON_H*/