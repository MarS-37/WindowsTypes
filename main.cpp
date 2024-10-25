#include <QSplashScreen>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QToolTip>
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QTimer>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        auto *centralWidget = new QWidget(this);
        auto *layout = new QVBoxLayout(centralWidget);

        // Кнопки для каждого типа окна
        layout->addWidget(createButton("Qt::Widget", [=]() { showWidget(); }));
        layout->addWidget(createButton("Qt::Window", [=]() { showWindow(); }));
        layout->addWidget(createButton("Qt::Dialog", [=]() { showDialog(); }));
        layout->addWidget(createButton("Qt::Sheet", [=]() { showSheet(); }));
        layout->addWidget(createButton("Qt::Drawer", [=]() { showDrawer(); }));
        layout->addWidget(createButton("Qt::Popup", [=]() { showPopup(); }));
        layout->addWidget(createButton("Qt::Tool", [=]() { showTool(); }));
        layout->addWidget(createButton("Qt::ToolTip", [=]() { showToolTip(); }));
        layout->addWidget(createButton("Qt::SplashScreen", [=]() { showSplashScreen(); }));
        layout->addWidget(createButton("Qt::SubWindow", [=]() { showSubWindow(); }));
        layout->addWidget(createButton("Qt::ForeignWindow", [=]() { showForeignWindow(); }));
        layout->addWidget(createButton("Qt::CoverWindow", [=]() { showCoverWindow(); }));

        setCentralWidget(centralWidget);
    }

private:
    QPushButton *createButton(const QString &title, std::function<void()> showFunc)
    {
        auto *button = new QPushButton(title, this);
        connect(button, &QPushButton::clicked, this, showFunc);

        return button;
    }

    void showWidget()
    {
        auto *window = new QWidget();
        window->setWindowTitle("Qt::Widget");
        window->resize(200, 100);
        window->show();
    }

    void showWindow()
    {
        auto *window = new QWidget(nullptr, Qt::Window);
        window->setWindowTitle("Qt::Window");
        window->resize(200, 100);
        window->show();
    }

    void showDialog()
    {
        auto *dialog = new QDialog(this);
        dialog->setWindowTitle("Qt::Dialog");
        dialog->resize(200, 100);
        dialog->exec();
    }

    void showSheet()
    {
        auto *sheet = new QDialog(this, Qt::Sheet);
        sheet->setWindowTitle("Qt::Sheet");
        sheet->resize(200, 100);
        sheet->exec();
    }

    void showDrawer()
    {
        auto *drawer = new QWidget(nullptr, Qt::Drawer);
        drawer->setWindowTitle("Qt::Drawer");
        drawer->resize(200, 100);
        drawer->show();
    }

    void showPopup()
    {
        auto *popup = new QWidget(nullptr, Qt::Popup);
        popup->setWindowTitle("Qt::Popup");
        popup->resize(200, 100);
        popup->show();
    }

    void showTool()
    {
        auto *tool = new QWidget(nullptr, Qt::Tool);
        tool->setWindowTitle("Qt::Tool");
        tool->resize(200, 100);
        tool->show();
    }

    void showToolTip()
    {
        QToolTip::showText(mapToGlobal(QPoint(100, 100)), "This is Qt::ToolTip", this);
    }

    void showSplashScreen()
    {
        auto *pixmap = new QPixmap(200, 100);
        pixmap->fill(Qt::blue);
        QSplashScreen *splash = new QSplashScreen(*pixmap);
        splash->show();
        QTimer::singleShot(2000, splash, &QSplashScreen::close);  // Закрыть через 2 секунды
    }

    void showSubWindow()
    {
        auto *subWindow = new QWidget(nullptr, Qt::SubWindow);
        subWindow->setWindowTitle("Qt::SubWindow");
        subWindow->resize(200, 100);
        subWindow->show();
    }

    void showForeignWindow()
    {
        auto *foreignWindow = new QWidget(nullptr, Qt::ForeignWindow);
        foreignWindow->setWindowTitle("Qt::ForeignWindow");
        foreignWindow->resize(200, 100);
        foreignWindow->show();
    }

    void showCoverWindow()
    {
        auto *coverWindow = new QWidget(nullptr, Qt::CoverWindow);
        coverWindow->setWindowTitle("Qt::CoverWindow");
        coverWindow->resize(200, 100);
        coverWindow->show();
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Window Types Example");
    window.resize(300, 500);
    window.show();

    return app.exec();
}


#include "main.moc"
