#ifndef QTQMLANDROIDTOAST_P_H
#define QTQMLANDROIDTOAST_P_H

#include "qtqmlandroidobject_p.h"
#include "qtqmlandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidView;

class QQmlAndroidToast : public QQmlAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)

public:
    explicit QQmlAndroidToast(QObject *parent = 0);

    QString text() const;
    void setText(const QString &text);

    int gravity() const;
    void setGravity(int gravity);

public Q_SLOTS:
    void show();
    void cancel();

Q_SIGNALS:
    void textChanged();
    void gravityChanged();

private:
    QString m_text;
    QQmlAndroidOptional<int> m_gravity;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDTOAST_P_H
