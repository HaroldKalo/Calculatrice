#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculatrice; }
QT_END_NAMESPACE

class Calculatrice : public QWidget
{
    Q_OBJECT

public:
    Calculatrice(QWidget *parent = nullptr);
    ~Calculatrice();

private slots:
    void onQPushButtonClicked();

    void on_pushButtonEgal_2_clicked();

    void on_pushButtonEffacer_2_clicked();

private:
    Ui::Calculatrice *ui;
};
#endif // CALCULATRICE_H
