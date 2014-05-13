#ifndef GCODESIMPLER_H
#define GCODESIMPLER_H

#include <QObject>

static const QString outSuffix = "xj3dp1";

class GCodeSimpler : public QObject
{
    Q_OBJECT
public:
    explicit GCodeSimpler(QObject *parent = 0);
    const QString simplify(const QString & reference);

signals:
    void processing(QString filepath);
    void finished(bool status, QString filepath);


public slots:
    void processGCode(QString filepath);
    void clearPosition();

private slots:
    void processLayerChange(QStringList &outList, QStringList &list);

private:
    double x,y,z,e,f;
    double last_z;
    double ref_z;
    int data_count;
    int layer_count;
    bool first;
    bool z_ground;

};

#endif // GCODESIMPLER_H
