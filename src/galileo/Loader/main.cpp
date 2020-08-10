#include <QApplication.h>
#include <galileo\Framework\Application.h>
#include <galileo\Application\ApplicationModel.h>

int main(int argc, char **argv)
{
	QApplication qApplication(argc, argv);

	galileo::Application& app = galileo::Application::getInstance();

	galileo::ApplicationModel appModel;

	app.setApplicationModel(&appModel);

	app.start("Spring school project", 420, 420);

	qApplication.exec();

	return 0;
}