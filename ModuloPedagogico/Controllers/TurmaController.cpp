#include "TurmaController.h"

TurmaController::TurmaController(RestAccessManager *restAccessManager, QObject *parent)
    : QObject{parent}
    , restAccessManager(restAccessManager)
{
    turmaModel = new TurmaModel{restAccessManager};
    connect(turmaModel, &TurmaModel::dataReadReady, this, &TurmaController::onConsultaTurmasFinalizada);
}

void TurmaController::solicitarConsultaTurmas(QString ano)
{
    if(ano.isEmpty())
        qDebug() << "Ano Vazio";
    else {
        restAccessManager->makeApiUrl(consulta, parametro, {ano});
        turmaModel->getTurmas(restAccessManager->apiUrl, QUrlQuery());
    }
}

void TurmaController::onConsultaTurmasFinalizada(JsonListProxyModel* jsonListProxyModel)
{
    //    qInfo() << customResult.message();
    emit consultaTurmasFinalizada(jsonListProxyModel);
}
