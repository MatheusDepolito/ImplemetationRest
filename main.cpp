#include "Controllers/MainController.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/Icones/logo-anglo.ico"));
    app.setOrganizationName("Anglo");
    app.setOrganizationDomain("Anglo");
    app.setApplicationName("Dashboard Educacional");

    QQmlApplicationEngine engine;


//    RestAccessManager rst;
//    rst.setUsuario("rafael.yuji","38621509");
//    rst.GET("http://186.194.232.102:8051/api/framework/v1/consultaSQLServer/RealizaConsulta/DASH.ACOL.PED.AB/1/S/",QUrlQuery(""),{});


    MainController mc;
    mc.autenticar("rafael.yuji","38621509");

    mc.solicitarConsultaTurmas("2023");


    qmlRegisterSingletonType<MainController>("MainController", 1, 0, "MainController", [&](QQmlEngine *, QJSEngine *)-> QObject*{
        return &mc;
    });



    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("DashboardEducacional", "Main");

    return app.exec();
}
