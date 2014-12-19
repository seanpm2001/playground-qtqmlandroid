#include "qtqmlandroidaccelerateinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidAccelerateInterpolator::QQmlAndroidAccelerateInterpolator(QObject *parent) :
    QQmlAndroidInterpolator(parent)
{
}

qreal QQmlAndroidAccelerateInterpolator::factor() const
{
    if (m_factor.isNull())
        return 1.0;
    return m_factor.value();
}

void QQmlAndroidAccelerateInterpolator::setFactor(qreal factor)
{
    if (m_factor.isNull() || m_factor.value() != factor) {
        m_factor = factor;
        emit factorChanged();
    }
}

QAndroidJniObject QQmlAndroidAccelerateInterpolator::onCreate()
{
    if (m_factor.isNull())
        return QAndroidJniObject("android/view/animation/AccelerateInterpolator");

    return QAndroidJniObject("android/view/animation/AccelerateInterpolator",
                             "(F)V",
                             m_factor.value());
}

QT_END_NAMESPACE
