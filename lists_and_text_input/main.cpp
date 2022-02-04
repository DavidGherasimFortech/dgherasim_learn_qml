#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include <iostream>
#include <typelistmodelmanager.h>

using namespace listandtextinput;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    TypeListModelManager type_model;
    type_model.insertDataStructure("Name 1", "This is the first description. I am not able to write something more smart than this on a late hour.");
    type_model.insertDataStructure("Name 2", "The second description is the shortest one.");
    type_model.insertDataStructure("Name 3", "This is only the third description.");
    type_model.insertDataStructure("Name 4", "For the four description please search on the internet.");
    type_model.insertDataStructure("Name 5", "Now you just read the fifth description.");
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("type_model", &type_model);
    engine.load(QUrl(QStringLiteral("qrc:main.qml")));
    return app.exec();
}
