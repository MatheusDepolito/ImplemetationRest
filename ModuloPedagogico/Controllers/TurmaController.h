#ifndef TURMACONTROLLER_H
#define TURMACONTROLLER_H

#include <QObject>
#include "../../Utils/RestAccessManager.h"
#include "../Models/TurmaModel.h"


class TurmaController : public QObject
{
    Q_OBJECT
public:
    explicit TurmaController(RestAccessManager* restAccessManager, QObject *parent = nullptr);

    void solicitarConsultaTurmas(QString ano);

private:
    QString consulta = "WB.GET.TURMA";
    QVector<QString> parametro = {"ANO"};
    TurmaModel* turmaModel;
    RestAccessManager* restAccessManager;

private slots:
    void onConsultaTurmasFinalizada(JsonListProxyModel* jsonListProxyModel);
signals:
    void consultaTurmasFinalizada(JsonListProxyModel* jsonListProxyModel);
};

#endif // TURMACONTROLLER_H
