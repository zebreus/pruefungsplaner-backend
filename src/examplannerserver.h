#ifndef EXAMPLANNERSERVER_H
#define EXAMPLANNERSERVER_H

#include <QObject>
#include <QThread>

#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include "day.h"
#include "group.h"
#include "module.h"
#include "plan.h"
#include "semester.h"
#include "timeslot.h"
#include "week.h"

#include "src/examplanner.h"

class ExamPlannerServer : public QObject
{
    Q_OBJECT
private:
    QJsonValue plans;
    QJsonValue plannerPlan;
    int plannerProgress;
    QThread examPlannerThread;
public:
    explicit ExamPlannerServer(QObject *parent = nullptr);

signals:

private slots:
    void finishedPlanning(Plan* finishedPlan);
    void progressChanged(int progress);

public slots:
    QJsonValue getPlans();
    void setPlans(QJsonValue newplans);
    void startPlanning(QJsonValue plan);
    void startPlanningTest();
    int getPlanningProgress();
    QJsonValue getPlannedPlan();
};

#endif // EXAMPLANNERSERVER_H
