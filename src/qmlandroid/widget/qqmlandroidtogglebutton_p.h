/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt QML Android module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QQMLANDROIDTOGGLEBUTTON_P_H
#define QQMLANDROIDTOGGLEBUTTON_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtQmlAndroid/private/qqmlandroidcompoundbutton_p.h>

QT_BEGIN_NAMESPACE

class Q_QMLANDROID_EXPORT QQmlAndroidToggleButton : public QQmlAndroidCompoundButton
{
    Q_OBJECT
    Q_PROPERTY(QString textOn READ textOn WRITE setTextOn NOTIFY textOnChanged)
    Q_PROPERTY(QString textOff READ textOff WRITE setTextOff NOTIFY textOffChanged)

public:
    explicit QQmlAndroidToggleButton(QQmlAndroidView *parent = nullptr);

    QString textOn() const;
    void setTextOn(const QString &text);

    QString textOff() const;
    void setTextOff(const QString &text);

Q_SIGNALS:
    void textOnChanged();
    void textOffChanged();

protected:
    QAndroidJniObject onCreate() override;
    void onInflate(QAndroidJniObject &instance) override;

private:
    QString m_textOn;
    QString m_textOff;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDTOGGLEBUTTON_P_H
