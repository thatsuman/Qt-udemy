#ifndef APPLIANCE_H
#define APPLIANCE_H

#include "freezer.h"
#include "microwave.h"
#include "toaster.h"

#include <QObject>

class appliance : public QObject, public freezer, public microwave, public toaster
{
    Q_OBJECT
public:
    explicit appliance(QObject *parent = nullptr);


    // toaster interface
public:
    bool grill();

    // microwave interface
public:
    bool cook();

    // freezer interface
public:
    bool freeze();
};

#endif // APPLIANCE_H
