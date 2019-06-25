//4 headers for the widgets contained
#include <qlabel.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qpushbutton.h>

#include <qlayout.h>
#include <QIcon>

#include "finddialog.h"




//name merge in debugging and testing
FindDialog::FindDialog(QWidget *parent, const char *name)
            : QDialog(parent, Qt::Window | Qt::WindowStaysOnTopHint
                      /*name removed for Qt 4 compatibility*/)
{
    if(name != NULL)
        setObjectName(name);

    //setCaption(tr("Find"));
    setWindowTitle("Find");
    //setWindowIcon(QIcon("Programs-Windows.ico"));

    //Failed attempt to have all minimize, maximize, and help button in the upper right corner
    //failed cause windows sucks
//    Qt::WindowFlags flags = Qt::Window;
//    flags |= Qt::CustomizeWindowHint;
//    flags |= Qt::WindowMaximizeButtonHint;
//    flags |= Qt::WindowMinimizeButtonHint;
//    flags |= Qt::WindowCloseButtonHint;
//    flags |= Qt::WindowSystemMenuHint;
//    flags |= Qt::WindowContextHelpButtonHint;
//    flags |= Qt::WindowStaysOnTopHint;
//    setWindowFlags(flags);

    label = new QLabel(tr("Find &what:"), this);
    lineEdit = new QLineEdit(this);
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"), this);
    backwardCheckBox = new QCheckBox(tr("Search &backward"), this);

    findButton = new QPushButton(tr("&Find"), this);
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"), this);

    connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableFindButton(const QString &)));
    connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch(1);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(10);
    mainLayout->setSpacing(5);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    //tested and it does work
//    QWidget::setTabOrder(closeButton, findButton);
//    QWidget::setTabOrder(findButton, caseCheckBox);
//    QWidget::setTabOrder(caseCheckBox, lineEdit);
}

void FindDialog::findClicked()
{
    QString text = lineEdit->text();

    //bool caseSensitive = caseCheckBox->isOn();      - removed for Qt4 compatibility
    bool caseSensitive = caseCheckBox->isChecked();
    if (backwardCheckBox->isChecked())
        emit findPrev(text, caseSensitive);
    else
        emit findNext(text, caseSensitive);
}

void FindDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
