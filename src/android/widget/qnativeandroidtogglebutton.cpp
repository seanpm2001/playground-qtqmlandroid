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

#include "qnativeandroidtogglebutton_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidToggleButton::QNativeAndroidToggleButton(QNativeAndroidContext *context) :
    QNativeAndroidCompoundButton(context)
{
}

QString QNativeAndroidToggleButton::textOn() const
{
    return m_textOn;
}

void QNativeAndroidToggleButton::setTextOn(const QString &text)
{
    if (m_textOn != text) {
        m_textOn = text;
        QtNativeAndroid::callTextMethod(instance(), "setTextOn", text);
        emit textOnChanged();
    }
}

QString QNativeAndroidToggleButton::textOff() const
{
    return m_textOff;
}

void QNativeAndroidToggleButton::setTextOff(const QString &text)
{
    if (m_textOff != text) {
        m_textOff = text;
        QtNativeAndroid::callTextMethod(instance(), "setTextOff", text);
        emit textOffChanged();
    }
}

QAndroidJniObject QNativeAndroidToggleButton::onCreate()
{
    return QAndroidJniObject("android/widget/ToggleButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidToggleButton::onInflate(QAndroidJniObject &instance)
{
    QNativeAndroidCompoundButton::onInflate(instance);

    if (!m_textOn.isNull())
        instance.callMethod<void>("setTextOn", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_textOn).object());
    if (!m_textOff.isNull())
        instance.callMethod<void>("setTextOff", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_textOff).object());
}

QT_END_NAMESPACE
