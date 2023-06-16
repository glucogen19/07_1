#include <QtWidgets>
class MainWindow : public QMainWindow {
	public:
		MainWindow();
		void startButtonClick();
		void stopButtonClick();
	private:
		QLabel      *textLabel;
		QPushButton *startButton;
		QPushButton *stopButton;
		
};

MainWindow :: MainWindow(){
	setFixedSize(600,200);
	setWindowTitle("Test QPushButton v7.1");
	QFont fontLabel("Courier", 18, QFont::Normal);
	QFont fontButton("Times", 18, QFont::Bold);
	
	textLabel = new QLabel("Test QLabel", this);
	textLabel->setGeometry(0, 0, 300, 50);
	textLabel->setFont(fontLabel);
	
	startButton = new QPushButton("Start", this);
	startButton->setGeometry(20, 50, 70, 50);
	startButton->setFont(fontButton);
	
	stopButton = new QPushButton("Stop", this);
	stopButton->setGeometry(110, 50, 70, 50);
	stopButton->setFont(fontButton);
	
	connect(startButton, &QPushButton::clicked, 
			this, &MainWindow::startButtonClick); 
	connect(stopButton, &QPushButton::clicked,
			this, &MainWindow::stopButtonClick);
			
}

void MainWindow::startButtonClick(){
	textLabel->setText("Clicked: Start");
}

void MainWindow::stopButtonClick(){
	textLabel->setText("Clicked: Stop");
}
int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	MainWindow mainWin;
	mainWin.show();
	return app.exec();
	
}