#include <qapplication.h>
#include <QIcon>
#include "finddialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FindDialog *dialog = new FindDialog();

    //app.setMainWidget(dialog);
    //QIcon *icon = new QIcon(":\Programs-Windows.ico");
    app.setWindowIcon( QIcon("Programs-Windows.ico"));
    dialog->show();


    return app.exec();
}
