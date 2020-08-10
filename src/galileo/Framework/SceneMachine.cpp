#include <galileo/Framework/SceneMachine.h>
#include <qcoreapplication.h>
#include <assert.h>

namespace galileo
{
	CSceneMachine::CSceneMachine(const std::string ac_sInitialScene, 
															std::map<const std::string, IScene*> a_SceneCollection, 
															std::map<const std::string, const boost::any> a_TransientData,
															std::unique_ptr<QMainWindow> av_xMainWindow) :
		m_SceneCollection(a_SceneCollection)
		, m_TransientDataCollection(a_TransientData)
		, m_uMainWindow(std::move(av_xMainWindow))
		, m_InitialScene(ac_sInitialScene)
		, m_CurrentScene("")
	{
		assert(m_SceneCollection.size() != 0);

		for (const auto& Scene : m_SceneCollection) {
			QObject::connect(Scene.second, SIGNAL(SceneChange(const std::string&)),
				this, SLOT(setActiveScene(const std::string&)));
		}

		getActiveScene(m_InitialScene);

		QCoreApplication* app = QCoreApplication::instance();
		connect(app, SIGNAL(aboutToQuit()), this, SLOT(release()));
	}


	void CSceneMachine::setActiveScene(const std::string& ac_sSceneName)
	{
		getActiveScene(ac_sSceneName);
	}

	void CSceneMachine::getActiveScene(const std::string ac_sSceneName)
	{
		if (m_CurrentScene != ac_sSceneName) {

			IScene* currentScene = nullptr;
			if (m_CurrentScene != "") {

				const auto& it = m_SceneCollection.find(m_CurrentScene);
				currentScene = it->second;

				m_uMainWindow = currentScene->getMainWindow();
				m_TransientDataCollection = currentScene->getTransientDataCollection();
			}

			const auto& nextScene = m_SceneCollection.find(ac_sSceneName)->second;
			if (nextScene != nullptr) {
				if (currentScene != nullptr)
					currentScene->release();

				nextScene->setWindow(std::move(m_uMainWindow));
				nextScene->setTransientData(m_TransientDataCollection);
				nextScene->createScene();
				nextScene->drawScene();
				nextScene->show();
				m_CurrentScene = ac_sSceneName;
			}
		}
	}

	void CSceneMachine::release() const
	{
		const auto& currentScene = m_SceneCollection.find(m_CurrentScene)->second;
		if (currentScene != nullptr)
			currentScene->release();
	}
}
