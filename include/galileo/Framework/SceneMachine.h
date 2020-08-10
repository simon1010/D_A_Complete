#pragma once
#include <galileo\Framework\global.h>
#include <QtCore\qobject.h>
#include <galileo/Framework/IScene.h>

namespace galileo
{
	class Framework_EXPORT_IMPORT_API CSceneMachine : public QObject
	{
		Q_OBJECT

	public:
		CSceneMachine(const std::string initialScene,
							    std::map<const std::string, IScene*> sceneCollection,
							    std::map<const std::string, const boost::any> transientDataCollection,
								  std::unique_ptr<QMainWindow> mainWindow);

		typedef std::shared_ptr<CSceneMachine> s_ptr;
		typedef std::unique_ptr<CSceneMachine> u_ptr;

	private:
		std::map<const std::string, IScene*>  m_SceneCollection;
		std::map<const std::string, const boost::any> m_TransientDataCollection;
		std::unique_ptr<QMainWindow> m_uMainWindow;
		const std::string m_InitialScene;

		std::string m_CurrentScene;

		void getActiveScene(const std::string sceneName);

	private slots:
		void setActiveScene(const std::string& sceneName);
		void release() const;

	};

}