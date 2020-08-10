#include <galileo\Application\ApplicationModel.h>
#include <galileo\Application\ConfigScene.h>
#include <galileo\Application\AppScene.h>

const std::string configSceneName = std::string("Config scene");
const std::string appSceneName    = std::string("App scene");

namespace galileo
{
	ApplicationModel::ApplicationModel() : IApplicationModel()
	{
	}

	void ApplicationModel::defineScene()
	{
		m_initialScene = std::make_shared<ConfigScene>(configSceneName);
		m_secondScene  = std::make_shared<AppScene>(appSceneName);

		m_Scenes.emplace(configSceneName, m_initialScene.get());
		m_Scenes.emplace(appSceneName, m_secondScene.get());
	}

	void ApplicationModel::defineInitialScene()
	{
		m_InitialScene = configSceneName;
	}

	void ApplicationModel::defineTransientData()
	{
		//add initial values for all transient data 

		std::string applicationName = "Undefined";
		m_TransientData.emplace("ApplicationName", applicationName);

		unsigned int sampleRate = 25600;
		m_TransientData.emplace("SampleRate", sampleRate);

		double displayTime = 0.1;
		m_TransientData.emplace("DisplayTime", displayTime);

		double refreshRate = 1.0;
		m_TransientData.emplace("RefreshRate", refreshRate);
	}
}
