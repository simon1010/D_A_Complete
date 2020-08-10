#pragma once
#include <galileo\Framework\IApplicationModel.h>
#include <galileo\Application\global.h>
#include <galileo\Application\ConfigScene.h>
#include <galileo\Application\AppScene.h>

namespace galileo
{
	class Application_EXPORT_IMPORT_API ApplicationModel : public IApplicationModel
	{
	public:

		ApplicationModel();

		virtual void defineScene();

		virtual void defineInitialScene();

		virtual void defineTransientData();

	private:
		std::shared_ptr<ConfigScene> m_initialScene;
		std::shared_ptr<AppScene>    m_secondScene;
	};
}
