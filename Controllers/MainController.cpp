#include "MainController.h"


MainController::MainController(QObject *parent)
    : QObject{parent}
{
    restAccessManager = new RestAccessManager{this};
    turmaController = new TurmaController{restAccessManager, this};
    connect(turmaController, &TurmaController::consultaTurmasFinalizada, this, &MainController::consultaTurmasFinalizada);
}

void MainController::solicitarConsultaTurmas(QString ano)
{
    //    qDebug() << ano;
    turmaController->solicitarConsultaTurmas(ano);
}

void MainController::autenticar(QString userName, QString password)
{
    restAccessManager->setUsuario(userName, password);
}

void MainController::consultaTurmasFinalizada(JsonListProxyModel* jsonListProxyModel)
{
    // Criar uma instância do JsonListProxyModel e definir o modelo de origem
    emit getTurmasListModel(jsonListProxyModel);
}
