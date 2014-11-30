#include <QtQml>

#include "qtdroidactionbar_p.h"
#include "qtdroidactivity_p.h"

#include "qtdroidlayoutparams_p.h"
#include "qtdroidview_p.h"
#include "qtdroidviewgroup_p.h"
#include "qtdroidlinearlayout_p.h"

#include "qtdroidbutton_p.h"
#include "qtdroidcheckbox_p.h"
#include "qtdroidprogressbar_p.h"
#include "qtdroidradiobutton_p.h"
#include "qtdroidrelativelayout_p.h"
#include "qtdroidrelativelayoutparams_p.h"
#include "qtdroidscrollview_p.h"
#include "qtdroidseekbar_p.h"
#include "qtdroidswitch_p.h"
#include "qtdroidtextview_p.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qmlRegisterType<QtDroidActionBar>("qtdroid.app", 0, 1, "ActionBar");
    qmlRegisterType<QtDroidActivity>("qtdroid.app", 0, 1, "Activity");

    qmlRegisterUncreatableType<QtDroidLayoutParams>("qtdroid.view", 0, 1, "LayoutParams", QLatin1String("LayoutParams is an attached property."));
    qmlRegisterType<QtDroidView>();
    qmlRegisterType<QtDroidViewGroup>();

    qmlRegisterType<QtDroidButton>("qtdroid.widget", 0, 1, "Button");
    qmlRegisterType<QtDroidCheckBox>("qtdroid.widget", 0, 1, "CheckBox");
    qmlRegisterType<QtDroidLinearLayout>("qtdroid.widget", 0, 1, "LinearLayout");
    qmlRegisterType<QtDroidProgressBar>("qtdroid.widget", 0, 1, "ProgressBar");
    qmlRegisterType<QtDroidRelativeLayout>("qtdroid.widget", 0, 1, "RelativeLayout");
    qmlRegisterUncreatableType<QtDroidRelativeLayoutParams>("qtdroid.view", 0, 1, "RelativeLayoutParams", QLatin1String("RelativeLayoutParams is an attached property."));
    qmlRegisterType<QtDroidRadioButton>("qtdroid.widget", 0, 1, "RadioButton");
    qmlRegisterType<QtDroidScrollView>("qtdroid.widget", 0, 1, "ScrollView");
    qmlRegisterType<QtDroidSeekBar>("qtdroid.widget", 0, 1, "SeekBar");
    qmlRegisterType<QtDroidSwitch>("qtdroid.widget", 0, 1, "Switch");
    qmlRegisterType<QtDroidTextView>("qtdroid.widget", 0, 1, "TextView");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
