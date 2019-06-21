#ifndef CRCTOOL_H
#define CRCTOOL_H

#include <QObject>

class CRCTool : public QObject
{
    Q_OBJECT
public:
    explicit CRCTool(QObject *parent = nullptr);
    void AddCRC16(uint16_t *buffer,uint16_t n,uint16_t *pcrc);
    uint16_t CheckCRC16(uint8_t *buffer,uint16_t n);
signals:

public slots:
};

#endif // CRCTOOL_H
