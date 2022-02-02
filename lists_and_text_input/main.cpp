#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include <iostream>
#include <typelistmodel.h>

using namespace listandtextinput;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    TypeListModel type_model;
    type_model.add("Name 1", "This is the first description. I am not able to write something more smart than this on a late hour.");
    type_model.add("Name 2", "The second description is the shortest one.");
    type_model.add("Name 3", "This is only the third description.");
    type_model.add("Name 4", "For the four description please search on the internet.");
    type_model.add("Name 5", "Now you just read the fifth description.");
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("type_model", &type_model);
    engine.load(QUrl(QStringLiteral("qrc:main.qml")));
    return app.exec();
}
