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

#ifndef QQMLANDROIDRELATIVELAYOUTPARAMS_P_H
#define QQMLANDROIDRELATIVELAYOUTPARAMS_P_H

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

#include <QtQmlAndroid/private/qqmlandroidmarginlayoutparams_p.h>

QT_BEGIN_NAMESPACE

class Q_QMLANDROID_EXPORT QQmlAndroidRelativeLayoutParams : public QQmlAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(QQmlAndroidView *above READ above WRITE setAbove NOTIFY aboveChanged)
    Q_PROPERTY(QQmlAndroidView *below READ below WRITE setBelow NOTIFY belowChanged)
    Q_PROPERTY(QQmlAndroidView *alignTop READ alignTop WRITE setAlignTop NOTIFY alignTopChanged)
    Q_PROPERTY(QQmlAndroidView *alignLeft READ alignLeft WRITE setAlignLeft NOTIFY alignLeftChanged)
    Q_PROPERTY(QQmlAndroidView *alignRight READ alignRight WRITE setAlignRight NOTIFY alignRightChanged)
    Q_PROPERTY(QQmlAndroidView *alignBottom READ alignBottom WRITE setAlignBottom NOTIFY alignBottomChanged)
    Q_PROPERTY(QQmlAndroidView *alignStart READ alignStart WRITE setAlignStart NOTIFY alignStartChanged)
    Q_PROPERTY(QQmlAndroidView *alignEnd READ alignEnd WRITE setAlignEnd NOTIFY alignEndChanged)
    Q_PROPERTY(QQmlAndroidView *alignBaseline READ alignBaseline WRITE setAlignBaseline NOTIFY alignBaselineChanged)
    Q_PROPERTY(QQmlAndroidView *toLeftOf READ toLeftOf WRITE setToLeftOf NOTIFY toLeftOfChanged)
    Q_PROPERTY(QQmlAndroidView *toRightOf READ toRightOf WRITE setToRightOf NOTIFY toRightOfChanged)
    Q_PROPERTY(QQmlAndroidView *toStartOf READ toStartOf WRITE setToStartOf NOTIFY toStartOfChanged)
    Q_PROPERTY(QQmlAndroidView *toEndOf READ toEndOf WRITE setToEndOf NOTIFY toEndOfChanged)
    Q_PROPERTY(bool alignParentTop READ alignParentTop WRITE setAlignParentTop NOTIFY alignParentTopChanged)
    Q_PROPERTY(bool alignParentLeft READ alignParentLeft WRITE setAlignParentLeft NOTIFY alignParentLeftChanged)
    Q_PROPERTY(bool alignParentRight READ alignParentRight WRITE setAlignParentRight NOTIFY alignParentRightChanged)
    Q_PROPERTY(bool alignParentBottom READ alignParentBottom WRITE setAlignParentBottom NOTIFY alignParentBottomChanged)
    Q_PROPERTY(bool alignParentStart READ alignParentStart WRITE setAlignParentStart NOTIFY alignParentStartChanged)
    Q_PROPERTY(bool alignParentEnd READ alignParentEnd WRITE setAlignParentEnd NOTIFY alignParentEndChanged)
    Q_PROPERTY(bool alignWithParent READ alignWithParent WRITE setAlignWithParent NOTIFY alignWithParentChanged)
    Q_PROPERTY(bool centerHorizontal READ centerHorizontal WRITE setCenterHorizontal NOTIFY centerHorizontalChanged)
    Q_PROPERTY(bool centerVertical READ centerVertical WRITE setCenterVertical NOTIFY centerVerticalChanged)
    Q_PROPERTY(bool centerInParent READ centerInParent WRITE setCenterInParent NOTIFY centerInParentChanged)

public:
    explicit QQmlAndroidRelativeLayoutParams(QQmlAndroidView *view);

    QQmlAndroidView *above() const;
    void setAbove(QQmlAndroidView *view);

    QQmlAndroidView *below() const;
    void setBelow(QQmlAndroidView *view);

    QQmlAndroidView *alignTop() const;
    void setAlignTop(QQmlAndroidView *view);

    QQmlAndroidView *alignLeft() const;
    void setAlignLeft(QQmlAndroidView *view);

    QQmlAndroidView *alignRight() const;
    void setAlignRight(QQmlAndroidView *view);

    QQmlAndroidView *alignBottom() const;
    void setAlignBottom(QQmlAndroidView *view);

    QQmlAndroidView *alignStart() const;
    void setAlignStart(QQmlAndroidView *view);

    QQmlAndroidView *alignEnd() const;
    void setAlignEnd(QQmlAndroidView *view);

    QQmlAndroidView *alignBaseline() const;
    void setAlignBaseline(QQmlAndroidView *view);

    QQmlAndroidView *toLeftOf() const;
    void setToLeftOf(QQmlAndroidView *view);

    QQmlAndroidView *toRightOf() const;
    void setToRightOf(QQmlAndroidView *view);

    QQmlAndroidView *toStartOf() const;
    void setToStartOf(QQmlAndroidView *view);

    QQmlAndroidView *toEndOf() const;
    void setToEndOf(QQmlAndroidView *view);

    bool alignParentTop() const;
    void setAlignParentTop(bool align);

    bool alignParentLeft() const;
    void setAlignParentLeft(bool align);

    bool alignParentRight() const;
    void setAlignParentRight(bool align);

    bool alignParentBottom() const;
    void setAlignParentBottom(bool align);

    bool alignParentStart() const;
    void setAlignParentStart(bool align);

    bool alignParentEnd() const;
    void setAlignParentEnd(bool align);

    bool alignWithParent() const;
    void setAlignWithParent(bool align);

    bool centerHorizontal() const;
    void setCenterHorizontal(bool center);

    bool centerVertical() const;
    void setCenterVertical(bool center);

    bool centerInParent() const;
    void setCenterInParent(bool center);

Q_SIGNALS:
    void aboveChanged();
    void belowChanged();
    void alignTopChanged();
    void alignLeftChanged();
    void alignRightChanged();
    void alignBottomChanged();
    void alignStartChanged();
    void alignEndChanged();
    void alignBaselineChanged();
    void toLeftOfChanged();
    void toRightOfChanged();
    void toStartOfChanged();
    void toEndOfChanged();

    void alignParentTopChanged();
    bool alignParentLeftChanged();
    bool alignParentRightChanged();
    bool alignParentBottomChanged();
    bool alignParentStartChanged();
    bool alignParentEndChanged();
    bool alignWithParentChanged();
    bool centerHorizontalChanged();
    bool centerVerticalChanged();
    bool centerInParentChanged();

protected:
    QAndroidJniObject onCreate() override;
    void onInflate(QAndroidJniObject &instance) override;

private:
    QQmlAndroidView *m_above;
    QQmlAndroidView *m_below;
    QQmlAndroidView *m_alignTop;
    QQmlAndroidView *m_alignLeft;
    QQmlAndroidView *m_alignRight;
    QQmlAndroidView *m_alignBottom;
    QQmlAndroidView *m_alignStart;
    QQmlAndroidView *m_alignEnd;
    QQmlAndroidView *m_alignBaseline;
    QQmlAndroidView *m_toLeftOf;
    QQmlAndroidView *m_toRightOf;
    QQmlAndroidView *m_toStartOf;
    QQmlAndroidView *m_toEndOf;

    bool m_alignParentTop;
    bool m_alignParentLeft;
    bool m_alignParentRight;
    bool m_alignParentBottom;
    bool m_alignParentStart;
    bool m_alignParentEnd;
    bool m_alignWithParent;
    bool m_centerHorizontal;
    bool m_centerVertical;
    bool m_centerInParent;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDRELATIVELAYOUTPARAMS_P_H
