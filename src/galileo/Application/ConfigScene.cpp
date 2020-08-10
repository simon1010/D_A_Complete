#include <galileo/Application/ConfigScene.h>

#include "ui_config_scene.h"

namespace galileo
{

	ConfigScene::ConfigScene(const std::string& ac_szSceneName) : IScene(ac_szSceneName)
	{
	}

	void ConfigScene::createScene()
	{
		//create the UI
		auto ui = std::make_unique<Ui_ConfigScene>();
		ui->setupUi(m_uMainWindow.get());

		//connect btn's release signal to defined slot
		QObject::connect(ui->okButton, SIGNAL(released()), this, SLOT( mf_OkButton()));

		// go to plotting
		QObject::connect(ui->plottingButton, SIGNAL(released()), this, SLOT(mf_PlottingButton()));

		//set centralWidget
		centralWidget = ui->centralwidget;

		//setting default values for the controls in first scene
			//Application name
		const std::string applicationName = boost::any_cast<std::string>(m_TransientDataCollection.find("ApplicationName")->second);

		auto applicationNameLineEdit = centralWidget->findChild<QLineEdit*>("applicationNameLineEdit");
		applicationNameLineEdit->setText(QString(applicationName.c_str()));

			//Sample rate
		const unsigned int sampleRate = boost::any_cast<unsigned int>(m_TransientDataCollection.find("SampleRate")->second);
		
		auto sampleRateSpinBox = centralWidget->findChild<QSpinBox*>("sampleRateSpinBox");
		sampleRateSpinBox->setValue(sampleRate);

			//Display time
		const double displayTime = boost::any_cast<double>(m_TransientDataCollection.find("DisplayTime")->second);
		
		auto displayTimeDoubleSpinBox = centralWidget->findChild<QDoubleSpinBox*>("displayTimeDoubleSpinBox");
		displayTimeDoubleSpinBox->setValue(displayTime);

			//Refresh rate
		const double refreshRate = boost::any_cast<double>(m_TransientDataCollection.find("RefreshRate")->second);

		auto refreshRateDoubleSpinBox = centralWidget->findChild<QDoubleSpinBox*>("refreshRateDoubleSpinBox");
		refreshRateDoubleSpinBox->setValue(refreshRate);

	}

	void ConfigScene::release()
	{
		delete centralWidget;
	}

	ConfigScene::~ConfigScene()
	{

	}

	void ConfigScene::mf_OkButton()
	{
		auto applicationNameLineEdit = centralWidget->findChild<QLineEdit*>("applicationNameLineEdit");
		const std::string appName = applicationNameLineEdit->text().toStdString();
		if (!appName.empty())
		{
			m_TransientDataCollection.erase("ApplicationName");
			m_TransientDataCollection.emplace("ApplicationName", appName);
		}

		//setting the new sample rate value in transient data
		const auto sampleRateSpinBox = centralWidget->findChild<QSpinBox*>("sampleRateSpinBox");
		const unsigned int value = sampleRateSpinBox->value();
		m_TransientDataCollection.erase("SampleRate");
		m_TransientDataCollection.emplace("SampleRate", value);

		const auto displayTimeDoubleSpinBox = centralWidget->findChild<QDoubleSpinBox*>("displayTimeDoubleSpinBox");
		const double newDisplayTime = displayTimeDoubleSpinBox->value();
		m_TransientDataCollection.erase("DisplayTime");
		m_TransientDataCollection.emplace("DisplayTime", newDisplayTime);

		const auto refreshRateSpinBox = centralWidget->findChild<QDoubleSpinBox*>("refreshRateDoubleSpinBox");
		const double newRefreshRate = refreshRateSpinBox->value();
		m_TransientDataCollection.erase("RefreshRate");
		m_TransientDataCollection.emplace("RefreshRate", newRefreshRate);

		const std::string c_szNextSceneName = "App scene";
		emit SceneChange(c_szNextSceneName);
	}


	void ConfigScene::mf_PlottingButton()
	{
	  const std::string c_szNextSceneName = "Plotting scene";
		emit SceneChange(c_szNextSceneName);
	}
	
}
