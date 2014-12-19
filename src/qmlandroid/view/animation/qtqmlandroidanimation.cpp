#include "qtqmlandroidanimation_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qtqmlandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidAnimation::QQmlAndroidAnimation(QObject *parent) :
    QQmlAndroidContextual(parent), m_interpolator(0)
{
}

int QQmlAndroidAnimation::resource() const
{
    if (m_resource.isNull())
        return 0;
    return m_resource.value();
}

void QQmlAndroidAnimation::setResource(int resource)
{
    if (m_resource.isNull() || m_resource.value() != resource) {
        m_resource = resource;
        emit resourceChanged();
    }
}

int QQmlAndroidAnimation::duration() const
{
    if (m_duration.isNull())
        return 0;
    return m_duration.value();
}

void QQmlAndroidAnimation::setDuration(int duration)
{
    if (m_duration.isNull() || m_duration.value() != duration) {
        m_duration = duration;
        QtQmlAndroid::callIntMethod(instance(), "setDuration", duration);
        emit durationChanged();
    }
}

bool QQmlAndroidAnimation::fillAfter() const
{
    if (m_fillAfter.isNull())
        return false;
    return m_fillAfter.value();
}

void QQmlAndroidAnimation::setFillAfter(bool fill)
{
    if (m_fillAfter.isNull() || m_fillAfter.value() != fill) {
        m_fillAfter = fill;
        QtQmlAndroid::callBoolMethod(instance(), "setFillAfter", fill);
        emit fillAfterChanged();
    }
}

bool QQmlAndroidAnimation::fillBefore() const
{
    if (m_fillBefore.isNull())
        return true;
    return m_fillBefore.value();
}

void QQmlAndroidAnimation::setFillBefore(bool fill)
{
    if (m_fillBefore.isNull() || m_fillBefore.value() != fill) {
        m_fillBefore = fill;
        QtQmlAndroid::callBoolMethod(instance(), "setFillBefore", fill);
        emit fillBeforeChanged();
    }
}

bool QQmlAndroidAnimation::fillEnabled() const
{
    if (!m_fillEnabled.isNull())
        return false;
    return m_fillEnabled.value();
}

void QQmlAndroidAnimation::setFillEnabled(bool fill)
{
    if (m_fillEnabled.isNull() || m_fillEnabled.value()!= fill) {
        m_fillEnabled = fill;
        QtQmlAndroid::callBoolMethod(instance(), "setFillEnabled", fill);
        emit fillEnabledChanged();
    }
}

QQmlAndroidInterpolator *QQmlAndroidAnimation::interpolator() const
{
    return m_interpolator;
}

void QQmlAndroidAnimation::setInterpolator(QQmlAndroidInterpolator *interpolator)
{
    if (m_interpolator != interpolator) {
        if (m_interpolator) {
            disconnect(m_interpolator, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidAnimation::updateInterpolator);
            m_interpolator->destruct();
        }
        m_interpolator = interpolator;
        if (m_interpolator) {
            connect(m_interpolator, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidAnimation::updateInterpolator);
            if (isValid())
                m_interpolator->construct();
        }
    }
}

int QQmlAndroidAnimation::repeatCount() const
{
    if (m_repeatCount.isNull())
        return 0;
    return m_repeatCount.value();
}

void QQmlAndroidAnimation::setRepeatCount(int count)
{
    if (m_repeatCount.isNull() || m_repeatCount.value() != count) {
        m_repeatCount = count;
        QtQmlAndroid::callIntMethod(instance(), "setRepeatCount", count);
        emit repeatCountChanged();
    }
}

QQmlAndroidAnimation::RepeatMode QQmlAndroidAnimation::repeatMode() const
{
    if (m_repeatMode.isNull())
        return RESTART;
    return m_repeatMode.value();
}

void QQmlAndroidAnimation::setRepeatMode(RepeatMode mode)
{
    if (m_repeatMode.isNull() || m_repeatMode.value() != mode) {
        m_repeatMode = mode;
        QtQmlAndroid::callIntMethod(instance(), "setRepeatMode", mode);
        emit repeatModeChanged();
    }
}

int QQmlAndroidAnimation::startOffset() const
{
    if (m_startOffset.isNull())
        return 0;
    return m_startOffset.value();
}

void QQmlAndroidAnimation::setStartOffset(int offset)
{
    if (m_startOffset.isNull() || m_startOffset.value() != offset) {
        m_startOffset = offset;
        QtQmlAndroid::callIntMethod(instance(), "setStartOffset", offset);
        emit startOffsetChanged();
    }
}

QQmlAndroidAnimation::ZAdjustment QQmlAndroidAnimation::zAdjustment() const
{
    if (m_zAdjustment.isNull())
        return ZORDER_NORMAL;
    return m_zAdjustment.value();
}

void QQmlAndroidAnimation::setZAdjustment(ZAdjustment adjustment)
{
    if (m_zAdjustment.isNull() || m_zAdjustment.value() != adjustment) {
        m_zAdjustment = adjustment;
        QtQmlAndroid::callIntMethod(instance(), "setZAdjustment", adjustment);
        emit zAdjustmentChanged();
    }
}

void QQmlAndroidAnimation::cancel()
{
    QtQmlAndroid::callVoidMethod(instance(), "cancel");
}

void QQmlAndroidAnimation::start()
{
    QtQmlAndroid::callVoidMethod(instance(), "start");
}

void QQmlAndroidAnimation::startNow()
{
    QtQmlAndroid::callVoidMethod(instance(), "startNow");
}

QAndroidJniObject QQmlAndroidAnimation::onCreate()
{
    if (m_resource.isNull())
        return QAndroidJniObject("android/view/animation/Animation");

    return QAndroidJniObject::callStaticObjectMethod("android/view/animation/AnimationUtils",
                                                     "loadAnimation",
                                                     "(Landroid/content/Context;I)Landroid/view/animation/Animation;",
                                                     ctx().object(),
                                                     m_resource.value());
}

void QQmlAndroidAnimation::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidContextual::onInflate(instance);

    if (m_resource.isNull()) {
        if (!m_duration.isNull())
            instance.callMethod<void>("setDuration", "(J)V", static_cast<jlong>(m_duration.value()));
        if (!m_fillAfter.isNull())
            instance.callMethod<void>("setFillAfter", "(Z)V", m_fillAfter.value());
        if (!m_fillBefore.isNull())
            instance.callMethod<void>("setFillBefore", "(Z)V", m_fillBefore.value());
        if (!m_fillEnabled.isNull())
            instance.callMethod<void>("setFillEnabled", "(Z)V", m_fillEnabled.value());
        if (!m_repeatCount.isNull())
            instance.callMethod<void>("setRepeatCount", "(I)V", m_repeatCount.value());
        if (!m_repeatMode.isNull())
            instance.callMethod<void>("setRepeatMode", "(I)V", m_repeatMode.value());
        if (!m_startOffset.isNull())
            instance.callMethod<void>("setStartOffset", "(J)V", static_cast<jlong>(m_startOffset.value()));
        if (!m_zAdjustment.isNull())
            instance.callMethod<void>("setZAdjustment", "(I)V", m_zAdjustment.value());
    }
}

void QQmlAndroidAnimation::objectChange(ObjectChange change)
{
    if (change == InstanceChange)
        updateInterpolator();
}

void QQmlAndroidAnimation::updateInterpolator()
{
    if (!isValid() || !m_interpolator || !m_interpolator->isValid())
        return;

    QAndroidJniObject animation = instance();
    QAndroidJniObject interpolator = m_interpolator->instance();
    QtQmlAndroid::callFunction([=]() {
        animation.callMethod<void>("setInterpolator", "(Landroid/view/animation/Interpolator;)V", interpolator.object());
    });
}

QT_END_NAMESPACE
