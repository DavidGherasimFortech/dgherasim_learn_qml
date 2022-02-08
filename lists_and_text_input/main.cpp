#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QStandardPaths>
#include <iostream>

#include "typelistmodelmanager.h"
#include "databasemodel.h"

using namespace listandtextinput;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    TypeListModelManager type_model;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("type_model", &type_model);
    engine.load(QUrl(QStringLiteral("qrc:main.qml")));
    return app.exec();
}
