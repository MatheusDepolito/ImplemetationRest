#ifndef TURMAMODEL_H
#define TURMAMODEL_H

#include <QObject>
#include "../../Utils/Tipos.h"
#include "../../Utils/RestAccessManager.h"
#include "../../Utils/utils.h"

class TurmaModel : public QObject
{
    Q_OBJECT
public:
    explicit TurmaModel(RestAccessManager* restAccessManager, QObject *parent = nullptr);

    void getTurmas(QString url, QUrlQuery parameters);

private:
    std::optional<JsonListModel*> jsonModelOpt;
    std::optional<JsonListProxyModel*> jsonListProxyModelOpt;

    RestAccessManager* restAccessManager;

    QString defineEscolaridade(const QString &nomeTurma);

signals:
    void dataReceived(std::optional<QByteArray> data);
    void dataReadReady(JsonListProxyModel* jsonListProxyModel);

private slots:
    void processResponseData(std::optional<QByteArray> data);
};

#endif // TURMAMODEL_H
