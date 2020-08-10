#pragma once

#include "galileo\Framework\IScene.h"
#include "qobject.h"

namespace galileo
{
	class ConfigScene : public IScene
	{
		Q_OBJECT

	public:
		ConfigScene(const std::string& ac_szSceneName);

		virtual void createScene();

		virtual void release();

		~ConfigScene();

	public slots:

		void mf_OkButton();

	private:

		QWidget *centralWidget;

	};
}
