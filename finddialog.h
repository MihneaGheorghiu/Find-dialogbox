#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <qdialog.h>

class QLabel;
class QLineEdit;
class QCheckBox;
class QPushButton;

class FindDialog : public QDialog
{
    Q_OBJECT

 public:
    FindDialog(QWidget *parent = NULL, const char *name = NULL);
 signals:
    void findNext(const QString &str, bool caseSensitive);
    void findPrev(const QString &str, bool caseSensitive);
 private slots:
     void findClicked();
     void enableFindButton(const QString &text);

 private:
     QLabel *label;
     QLineEdit *lineEdit;
     QCheckBox *caseCheckBox;
     QCheckBox *backwardCheckBox;
     QPushButton *findButton;
     QPushButton *closeButton;
};

#endif
