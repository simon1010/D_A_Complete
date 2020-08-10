#include <galileo\Application\AppScene.h>

#include "ui_app_scene.h"

namespace galileo
{
	AppScene::AppScene(const std::string& ac_szSceneName) : IScene(ac_szSceneName)
	{
	}

	void AppScene::createScene()
	{
		//create the UI
		const auto ui = std::make_shared<Ui_AppScene>();
		ui->setupUi(m_uMainWindow.get());

		//setting a temporary new title
		m_uMainWindow->setWindowTitle(QString("new title goes here"));

		//setting centralWidget
		centralWidget = ui->centralwidget;

		//Get the title from transient data
		std::string appName = boost::any_cast<std::string>(m_TransientDataCollection["ApplicationName"]);

		m_uMainWindow->setWindowTitle(QString(appName.c_str()));

	}
	void AppScene::release()
	{
		delete centralWidget;
	}

	AppScene::~AppScene()
	{

	}
}
